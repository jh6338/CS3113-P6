#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"
#include <SDL_mixer.h>

#include "Entity.h"
#include "Map.h"
#include "Util.h"	
#include "Effects.h" 
#include "Scene.h"
#include "Menu.h"
#include "Level1.h"
#include "Level2.h"


/*
Joyce Huang
May 10th, 2020
CS-UY 3113 Intro to Game Programming
Project 6: Student's Choice
*/


SDL_Window* displayWindow;
bool gameIsRunning = true;

ShaderProgram program;
glm::mat4 viewMatrix, modelMatrix, projectionMatrix;

Scene* currentScene;
Scene* sceneList[3];

Effects* effects; 

Mix_Music* music;
Mix_Chunk* pickup; 
Mix_Chunk* loseLife; 
Mix_Chunk* openDoor; 
Mix_Chunk* winGame; 

bool startGame = false;  
int playerLives = 3;
bool finalDoorClue = false; 
bool door1Clue = false; 
bool door2Clue = false; 
bool door3Clue = false; 
bool doorDelete = false; 


GLuint fontTextureID;

void SwitchToScene(Scene* scene) {
	currentScene = scene;
	currentScene->Initialize();
}

void Initialize() {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	displayWindow = SDL_CreateWindow("Project 6: Escape the Dungeon!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);

#ifdef _WINDOWS
	glewInit();
#endif

	glViewport(0, 0, 640, 480);

	program.Load("shaders/vertex_textured.glsl", "shaders/fragment_textured.glsl");
	
	// program.Load("shaders/vertex_lit.glsl", "shaders/fragment_lit.glsl");
	
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
	music = Mix_LoadMUS("8bit-Field01.mp3");
	Mix_PlayMusic(music, -1);
	Mix_VolumeMusic(MIX_MAX_VOLUME / 4);

	pickup = Mix_LoadWAV("pickup_item.wav");
	loseLife = Mix_LoadWAV("who-waa-sound-effect.wav");
	openDoor = Mix_LoadWAV("magic-idea-05-sound-effect.wav");
	winGame = Mix_LoadWAV("8bit_Victory01.wav");

	// Mix_VolumeChunk(pickup, MIX_MAX_VOLUME / 2);

	viewMatrix = glm::mat4(1.0f);
	modelMatrix = glm::mat4(1.0f);
	projectionMatrix = glm::ortho(-5.0f, 5.0f, -3.75f, 3.75f, -1.0f, 1.0f);

	program.SetProjectionMatrix(projectionMatrix);
	program.SetViewMatrix(viewMatrix);

	glUseProgram(program.programID);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glEnable(GL_BLEND);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	fontTextureID = Util::LoadTexture("font1.png");

	sceneList[0] = new Menu();
	sceneList[1] = new Level1();
	sceneList[2] = new Level2(); 
	SwitchToScene(sceneList[0]); 

	effects = new Effects(projectionMatrix, viewMatrix);

}

void ProcessInput() {

	currentScene->state.player->movement = glm::vec3(0);

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
		case SDL_WINDOWEVENT_CLOSE:
			gameIsRunning = false;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				// Move the player left
				break;

			case SDLK_RIGHT:
				// Move the player right
				break;

			case SDLK_SPACE:
				/*if (currentScene->state.player->collidedBottom) {
					currentScene->state.player->jump = true;
				}*/
				break;
				break; // SDL_KEYDOWN
			} // switch (event.key.keysym.sym) {
		}  // switch (event.type)
	} // while loop

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_LEFT]) {
		currentScene->state.player->movement.x = -1.0f;
	}
	else if (keys[SDL_SCANCODE_RIGHT]) {
		currentScene->state.player->movement.x = 1.0f;
	}

	if (keys[SDL_SCANCODE_DOWN]) {
		currentScene->state.player->movement.y = -1.0f;
	}
	else if (keys[SDL_SCANCODE_UP]) {
		currentScene->state.player->movement.y = 1.0f; 
	}

	if (keys[SDL_SCANCODE_RETURN] && (currentScene == sceneList[0])) {
		startGame = true;
	}

	if (glm::length(currentScene->state.player->movement) > 1.0f) {
		currentScene->state.player->movement = glm::normalize(currentScene->state.player->movement);
	}

}

#define FIXED_TIMESTEP 0.0166666f
float lastTicks = 0;
float accumulator = 0.0f;

void Update() {
	float ticks = (float)SDL_GetTicks() / 1000.0f;
	float deltaTime = ticks - lastTicks;
	lastTicks = ticks;

	deltaTime += accumulator;
	if (deltaTime < FIXED_TIMESTEP) {
		accumulator = deltaTime;
		return;
	}

	while (deltaTime >= FIXED_TIMESTEP) {
		currentScene->Update(FIXED_TIMESTEP);
		// program.SetLightPosition(currentScene->state.player->position);
		// effects->Update(FIXED_TIMESTEP);
		deltaTime -= FIXED_TIMESTEP;
	}

	accumulator = deltaTime;

	viewMatrix = glm::mat4(1.0f);

	viewMatrix = glm::translate(viewMatrix, glm::vec3(-currentScene->state.player->position.x, 
		-currentScene->state.player->position.y, 0)); 

	// check for when player collides with enemy (dead) 

	if (currentScene->state.player->collidedLeft || currentScene->state.player->collidedRight |
		currentScene->state.player->collidedTop || currentScene->state.player->collidedBottom) {
		if (currentScene->state.player->lastCollided == ENEMY) {
			playerLives -= 1;
			Mix_PlayChannel(-1, loseLife, 0);
			currentScene->state.player->position = currentScene->state.player->initialPosition;
		}
		else if (currentScene->state.player->lastCollided == ITEM) {
			switch (currentScene->state.player->lastCollidedItem) {
				case NOTHING: 
					break; 
				case ARROW: 
					break; 
				case SILVERKEY: 
					Mix_PlayChannel(-1, pickup, 0);
					currentScene->state.player->sKeys += 1;
					currentScene->state.player->lastCollidedEntity->isActive = false;
					break; 
				case GOLDENKEY: 
					Mix_PlayChannel(-1, pickup, 0);
					currentScene->state.player->gKey += 1;
					currentScene->state.player->lastCollidedEntity->isActive = false;
					break; 
				case FINALDOOR:
					if (currentScene->state.player->gKey > 0) {
						currentScene->state.player->collidedFinalDoor = true;
						Mix_PlayChannel(-1, winGame, 0); 
					}
					else {
						finalDoorClue = true; 
					}
					break; 
				case DOOR1: 
					if (currentScene->state.player->sKeys >= 1) {
						currentScene->state.player->sKeys -= 1;
						doorDelete = true; 
						Mix_PlayChannel(-1, openDoor, 0); 
					}
					else {
						door1Clue = true; 
					}
					break; 
				case DOOR2_1:
					if (currentScene->state.player->sKeys >= 2) {
						currentScene->state.player->sKeys -= 2;
						doorDelete = true; 
						Mix_PlayChannel(-1, openDoor, 0);
					}
					else {
						door2Clue = true; 
					}
					break;
				case DOOR2_2:
					if (currentScene->state.player->sKeys >= 2) {
						currentScene->state.player->sKeys -= 2;
						doorDelete = true;
						Mix_PlayChannel(-1, openDoor, 0);
					}
					else {
						door2Clue = true;
					}
					break;
				case DOOR3: 
					if (currentScene->state.player->sKeys >= 3) {
						currentScene->state.player->sKeys -= 3;
						doorDelete = true; 
						Mix_PlayChannel(-1, openDoor, 0);
					}
					else {
						door3Clue = true; 
					}
					break; 
				case REDPOTION: 
					Mix_PlayChannel(-1, pickup, 0);
					playerLives += 1;
					currentScene->state.player->lastCollidedEntity->isActive = false;
					break; 
				case BLUEPOTION: 
					Mix_PlayChannel(-1, pickup, 0);
					currentScene->state.player->speed += 1.0f;
					currentScene->state.player->lastCollidedEntity->isActive = false;
					break; 
			}
			for (int i = 0; i < currentScene->itemsCount; ++i) {
				if (doorDelete && currentScene->state.items[i].itemType == currentScene->state.player->lastCollidedItem) {
					currentScene->state.items[i].isActive = false; 
				}
			}
			doorDelete = false; 
			currentScene->state.player->lastCollidedItem = NOTHING; 
		}
		currentScene->state.player->lastCollided = NONE;
	}

	currentScene->state.player->lives = playerLives;

	if (playerLives == 0) {
		currentScene->gameOver = true;
		currentScene->winner = false;
		currentScene->state.player->isActive = false;
	}

}

void Render() {
	glClear(GL_COLOR_BUFFER_BIT);

	program.SetViewMatrix(viewMatrix);

	// use this shader program when it calls render for your level 
	glUseProgram(program.programID);
	currentScene->Render(&program);

	std::string text;
	glm::vec3 textPosition = glm::vec3(0, 0, 0);
	glm::vec3 cluePosition1 = glm::vec3(currentScene->state.player->position.x - 2.35f, currentScene->state.player->position.y - 1.5f, 0);
	glm::vec3 cluePosition2 = glm::vec3(currentScene->state.player->position.x - 2.05f, currentScene->state.player->position.y - 2.0f, 0);

	if (currentScene->gameOver) {

		if (currentScene->winner) {
			text = "Congratulations! You Win!";
		}
		else {
			text = "Game Over! You Lose!";
		}
		textPosition = glm::vec3(currentScene->state.player->position.x - 2.5f, currentScene->state.player->position.y + 2, 0);
		Util::DrawText(&program, fontTextureID, text, 0.5f, -0.25f, textPosition);
	} 

	if (finalDoorClue) {
		Util::DrawText(&program, fontTextureID, "There seems to be", 0.5f, -0.25f, cluePosition1);
		Util::DrawText(&program, fontTextureID, "a golden keyhole... ", 0.5f, -0.25f, cluePosition2);
		finalDoorClue = false; 
	}

	if (door1Clue) {
		Util::DrawText(&program, fontTextureID, "There seems to be", 0.5f, -0.25f, cluePosition1); 
		Util::DrawText(&program, fontTextureID, "one silver keyhole...", 0.5f, -0.25f, cluePosition2); 
		door1Clue = false; 
	}

	if (door2Clue) {
		Util::DrawText(&program, fontTextureID, "There seems to be", 0.5f, -0.25f, cluePosition1);
		Util::DrawText(&program, fontTextureID, "two silver keyholes...", 0.5f, -0.25f, cluePosition2);
		door2Clue = false; 
	}

	if (door3Clue) {
		Util::DrawText(&program, fontTextureID, "There seems to be", 0.5f, -0.25f, cluePosition1);
		Util::DrawText(&program, fontTextureID, "three silver keyholes...", 0.5f, -0.25f, cluePosition2);
		door3Clue = false; 
	}

	// effects->Render(); 

	SDL_GL_SwapWindow(displayWindow);
}


void Shutdown() {

	Mix_FreeChunk(pickup); 
	Mix_FreeChunk(loseLife); 
	Mix_FreeChunk(openDoor); 
	Mix_FreeChunk(winGame); 
	Mix_FreeMusic(music);

	SDL_Quit();
}

int main(int argc, char* argv[]) {
	Initialize();

	while (gameIsRunning) {
		ProcessInput();
		Update();

		if (currentScene->state.nextScene >= 0) SwitchToScene(sceneList[currentScene->state.nextScene]);
		else if (startGame) {
			startGame = false;
			SwitchToScene(sceneList[1]);
		}

		Render();
	}

	Shutdown();
	return 0;
}