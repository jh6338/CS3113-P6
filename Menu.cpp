#include "Menu.h"

#define ENEMY_COUNT 1

#define MENU_WIDTH 14
#define MENU_HEIGHT 9

unsigned int menu_data[] =
{
	 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5,
	 10, 60, 61, 62, 62, 60, 61, 62, 62, 60, 61, 62, 62, 15,
	 10, 70, 71, 72, 73, 70, 71, 72, 73, 70, 71, 72, 73, 15,
	 10, 70, 71, 72, 73, 70, 71, 72, 73, 70, 71, 72, 73, 15,
	 20, 70, 71, 72, 73, 70, 71, 72, 73, 70, 71, 72, 73, 25,
	 30, 70, 71, 72, 73, 70, 71, 72, 73, 70, 71, 72, 73, 35,
	 30, 70, 71, 72, 73, 70, 71, 72, 73, 70, 71, 72, 73, 35,
	 30, 70, 71, 72, 73, 70, 71, 72, 73, 70, 71, 72, 73, 35,
	 40, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 45,

};

void Menu::Initialize() {

	state.nextScene = -1;

	GLuint mapTextureID = Util::LoadTexture("Dungeon_Tileset.png");
	state.map = new Map(MENU_WIDTH, MENU_HEIGHT, menu_data, mapTextureID, 1.0f, 10, 10);

	// Move over all of the player and enemy code from initialization.

		// Initialize Game Objects

	// Initialize Player

	state.player = new Entity();
	state.player->entityType = PLAYER;
	state.player->position = glm::vec3(7, -4, 0);
	state.player->movement = glm::vec3(0);
	state.player->speed = 2.0f;
	state.player->lives = 3;
	state.player->textureID = Util::LoadTexture("slime_run.png");

	state.player->animIndices = new int[6]{ 0, 1, 2, 3, 4, 5 };
	state.player->animIndex = 0;
	state.player->animFrames = 6;
	state.player->animTime = 0;
	state.player->animCols = 6;
	state.player->animRows = 1;

	state.player->width = 0.5f;
	state.player->height = 0.5f;

	// enemies 
	state.enemies = new Entity[ENEMY_COUNT];
	GLuint enemyTextureID = Util::LoadTexture("Dungeon_Character.png");

	state.enemies[0].entityType = ENEMY;
	state.enemies[0].textureID = enemyTextureID;
	state.enemies[0].animFrames = 1;
	state.enemies[0].animIndex = 0;
	state.enemies[0].animRows = 4;
	state.enemies[0].animCols = 7;
	state.enemies[0].animIndices = new int[1]{ 0 };
	state.enemies[0].position = glm::vec3(4, -2.25, 0);
	state.enemies[0].speed = 1;
	state.enemies[0].aiType = WAITANDGO;
	state.enemies[0].aiState = IDLE;
	state.enemies[0].isActive = false;

}
void Menu::Update(float deltaTime) {
	state.player->Update(deltaTime, state.player, state.enemies, ENEMY_COUNT, state.enemies, ENEMY_COUNT, state.map);
}
void Menu::Render(ShaderProgram* program) {

	state.map->Render(program);

	GLuint fontTextureID = Util::LoadTexture("font1.png");
	Util::DrawText(program, fontTextureID, "Escape the Dungeon!", 0.6f, -0.25f, 
		glm::vec3(state.player->position.x - 2.8f, state.player->position.y + 2.5f, 0));
	Util::DrawText(program, fontTextureID, "Press Enter to start!", 0.45f, -0.25f, 
		glm::vec3(state.player->position.x - 1.75f, state.player->position.y - 2.5f, 0));

	state.player->Render(program);
}
