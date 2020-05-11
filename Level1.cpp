#include "Level1.h"

#define LEVEL1_ENEMY_COUNT 21
#define LEVEL1_ITEM_COUNT 23

#define LEVEL1_WIDTH 36
#define LEVEL1_HEIGHT 36

unsigned int level1_data[] =
{
	 00,  1,  1,  1,  1,  1,  2,  2,  2,  2,  3,  3,  3,  3,  4,  5, 78, 78, 78, 78, 00,  1,  1,  1,  1,  1,  2,  2,  2,  2,  3,  3,  3,  3,  4,  5,
	 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15, 78, 78, 78, 78, 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15,
	 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15, 78, 78, 78, 78, 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15,
	 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15, 78, 78, 78, 78, 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15,
	 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15, 78, 78, 78, 78, 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15,
	 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15, 78, 78, 78, 78, 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15,
	 10, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17,  1,  2,  3,  4,  4,  1, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 15,
	 10, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17,  6,  7,  8,  9,  6,  6, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 15,
	 30, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 16, 17, 18, 19, 16, 16, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 35, 
	 30, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 50, 51, 52, 51, 52, 55, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 35, 
	 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35, 78, 78, 78, 78, 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35,
	 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35, 78, 78, 78, 78, 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35,
	 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35, 78, 78, 78, 78, 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35,
	 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35, 78, 78, 78, 78, 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35,
	 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35, 78, 78, 78, 78, 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35,
	 40, 41, 41, 41, 41, 41, 55,  6, 16, 50, 44, 44, 44, 44, 44, 45, 78, 78, 78, 78, 40, 41, 41, 41, 41, 41, 55,  6, 16, 50, 44, 44, 44, 44, 44, 45,
	 78, 78, 78, 78, 78, 78, 10,  6, 16, 15, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 10,  6, 16, 15, 78, 78, 78, 78, 78, 78, 
	 78, 78, 78, 78, 78, 78, 10,  7, 17, 15, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 10,  7, 17, 15, 78, 78, 78, 78, 78, 78, 
	 78, 78, 78, 78, 78, 78, 30,  8, 18, 35, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 30,  8, 18, 35, 78, 78, 78, 78, 78, 78, 
	 78, 78, 78, 78, 78, 78, 30,  8, 18, 35, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 30,  8, 18, 35, 78, 78, 78, 78, 78, 78, 
	 00,  1,  1,  1,  1,  1,  1,  9, 19,  3,  3,  3,  3,  3,  4,  5, 78, 78, 78, 78, 00,  1,  1,  1,  1,  1,  1,  9, 19,  3,  3,  3,  3,  3,  4,  5,
	 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15, 78, 78, 78, 78, 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15,
	 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15, 78, 78, 78, 78, 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15,
	 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15, 78, 78, 78, 78, 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15,
	 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15, 78, 78, 78, 78, 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15,
	 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15, 78, 78, 78, 78, 10,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7,  8,  9,  6,  7, 15,
	 10, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17,  1,  2,  3,  4,  4,  1, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 15,
	 10, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17,  6,  7,  8,  9,  6,  6, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 15,
	 30, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 16, 17, 18, 19, 16, 16, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 35,
	 30, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 50, 51, 52, 51, 52, 55, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 18, 19, 16, 17, 35,
	 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35, 78, 78, 78, 78, 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35,
	 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35, 78, 78, 78, 78, 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35,
	 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35, 78, 78, 78, 78, 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35,
	 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35, 78, 78, 78, 78, 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35,
	 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35, 78, 78, 78, 78, 30, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 28, 29, 26, 27, 35,
	 40, 41, 41, 41, 41, 41, 41, 41, 41, 41, 44, 44, 44, 44, 44, 45, 78, 78, 78, 78, 40, 41, 41, 41, 41, 41, 41, 41, 41, 41, 44, 44, 44, 44, 44, 45
};

ShaderProgram program1; 

void Level1::Initialize() {

	state.nextScene = -1;

	program1.Load("shaders/vertex_lit.glsl", "shaders/fragment_lit.glsl");

	GLuint mapTextureID = Util::LoadTexture("Dungeon_Tileset.png");
	state.map = new Map(LEVEL1_WIDTH, LEVEL1_HEIGHT, level1_data, mapTextureID, 1.0f, 10, 10);

	// Move over all of the player and enemy code from initialization.

	// Initialize Game Objects

	// Initialize Player

	state.player = new Entity();
	state.player->entityType = PLAYER;
	state.player->position = glm::vec3(7, -7, 0);
	state.player->initialPosition = glm::vec3(7, -7, 0); 
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

	// items 

	state.items = new Entity[LEVEL1_ITEM_COUNT]; 
	GLuint itemTextureID = Util::LoadTexture("Dungeon_Tileset.png");
	GLuint arrowTextureID = Util::LoadTexture("arrow_1.png"); 

	for (int i = 0; i < LEVEL1_ITEM_COUNT; ++i) {
		state.items[i].entityType = ITEM; 
		state.items[i].textureID = itemTextureID;
		state.items[i].animFrames = 1;
		state.items[i].animIndex = 0;
		state.items[i].animCols = 10;
		state.items[i].animRows = 10;
	}

	state.items[0].itemType = FINALDOOR;
	state.items[0].animIndices = new int[1]{ 38 };
	state.items[0].position = glm::vec3(1, -1, 0);

	state.items[1].itemType = GOLDENKEY; 
	state.items[1].animIndices = new int[1]{ 99 };
	state.items[1].position = glm::vec3(1, -27, 0);

	state.items[2].itemType = BLUEPOTION;
	state.items[2].animIndices = new int[1]{ 87 };
	state.items[2].position = glm::vec3(23, -7, 0);

	state.items[3].itemType = REDPOTION;
	state.items[3].animIndices = new int[1]{ 98 };
	state.items[3].position = glm::vec3(27, -23, 0);

	state.items[4].itemType = BLUEPOTION;
	state.items[4].animIndices = new int[1]{ 87 };
	state.items[4].position = glm::vec3(12, -27, 0);

	state.items[5].itemType = SILVERKEY;
	state.items[5].animIndices = new int[1]{ 88 };
	state.items[5].position = glm::vec3(7, -17, 0);

	state.items[6].itemType = SILVERKEY;
	state.items[6].animIndices = new int[1]{ 88 };
	state.items[6].position = glm::vec3(34, -1, 0);
	
	state.items[7].itemType = SILVERKEY;
	state.items[7].animIndices = new int[1]{ 88 };
	state.items[7].position = glm::vec3(34, -14, 0);

	state.items[8].itemType = SILVERKEY;
	state.items[8].animIndices = new int[1]{ 88 };
	state.items[8].position = glm::vec3(34, -34, 0);

	state.items[9].itemType = SILVERKEY;
	state.items[9].animIndices = new int[1]{ 88 };
	state.items[9].position = glm::vec3(21, -34, 0);

	state.items[10].itemType = SILVERKEY;
	state.items[10].animIndices = new int[1]{ 88 };
	state.items[10].position = glm::vec3(12, -32, 0);

	state.items[11].itemType = SILVERKEY;
	state.items[11].animIndices = new int[1]{ 88 };
	state.items[11].position = glm::vec3(12, -23, 0);

	state.items[12].itemType = SILVERKEY;
	state.items[12].animIndices = new int[1]{ 88 };
	state.items[12].position = glm::vec3(3, -34, 0);

	state.items[13].itemType = SILVERKEY;
	state.items[13].animIndices = new int[1]{ 88 };
	state.items[13].position = glm::vec3(3, -21, 0);

	state.items[14].itemType = ARROW; 
	state.items[14].textureID = arrowTextureID; 
	state.items[14].position = glm::vec3(1, 0, 0); 

	state.items[15].itemType = DOOR1; 
	state.items[15].animIndices = new int[1]{ 47 }; 
	state.items[15].position = glm::vec3(16, -7, 0); 
	
	state.items[16].itemType = DOOR1; 
	state.items[16].animIndices = new int[1]{ 57 }; 
	state.items[16].position = glm::vec3(16, -8, 0); 

	state.items[17].itemType = DOOR2_1;
	state.items[17].animIndices = new int[1]{ 66 };
	state.items[17].position = glm::vec3(27, -19, 0);

	state.items[18].itemType = DOOR2_1;
	state.items[18].animIndices = new int[1]{ 67 };
	state.items[18].position = glm::vec3(28, -19, 0);

	state.items[19].itemType = DOOR2_2;
	state.items[19].animIndices = new int[1]{ 48 };
	state.items[19].position = glm::vec3(18, -27, 0);

	state.items[20].itemType = DOOR2_2;
	state.items[20].animIndices = new int[1]{ 58 };
	state.items[20].position = glm::vec3(18, -28, 0);

	state.items[21].itemType = DOOR3;
	state.items[21].animIndices = new int[1]{ 66 };
	state.items[21].position = glm::vec3(7, -19, 0);

	state.items[22].itemType = DOOR3;
	state.items[22].animIndices = new int[1]{ 67 };
	state.items[22].position = glm::vec3(8, -19, 0);

	itemsCount = LEVEL1_ITEM_COUNT; 

	// enemies 

	state.enemies = new Entity[LEVEL1_ENEMY_COUNT];
	GLuint enemyTextureID = Util::LoadTexture("Dungeon_Character.png");

	for (int i = 0; i < LEVEL1_ENEMY_COUNT; ++i) {
		state.enemies[i].textureID = enemyTextureID;
		state.enemies[i].animFrames = 1; 
		state.enemies[i].animIndex = 0; 
		state.enemies[i].animRows = 4; 
		state.enemies[i].animCols = 7; 
		state.enemies[i].entityType = ENEMY;
		state.enemies[i].speed = 3.0f;
	}

	// first box 

	state.enemies[0].aiType = WALKER; 
	state.enemies[0].moveRight = true; 
	state.enemies[0].animIndices = new int[1]{ 0 };
	state.enemies[0].position = glm::vec3(3, -12, 0);

	state.enemies[1].aiType = WALKER;
	state.enemies[1].moveRight = false;
	state.enemies[1].animIndices = new int[1]{ 0 };
	state.enemies[1].position = glm::vec3(11, -12, 0);

	// second box

	state.enemies[2].aiType = WALKER;
	state.enemies[2].moveRight = true;
	state.enemies[2].animIndices = new int[1]{ 0 };
	state.enemies[2].position = glm::vec3(23, -12, 0);

	state.enemies[3].aiType = WALKER;
	state.enemies[3].moveRight = false;
	state.enemies[3].animIndices = new int[1]{ 0 };
	state.enemies[3].position = glm::vec3(31, -12, 0);

	state.enemies[4].aiType = WALKER;
	state.enemies[4].moveRight = true;
	state.enemies[4].animIndices = new int[1]{ 0 };
	state.enemies[4].position = glm::vec3(23, -3, 0);

	state.enemies[5].aiType = WALKER;
	state.enemies[5].moveRight = false;
	state.enemies[5].animIndices = new int[1]{ 0 };
	state.enemies[5].position = glm::vec3(31, -3, 0);

	state.enemies[6].aiType = UPANDDOWN;
	state.enemies[6].moveUp = false;
	state.enemies[6].animIndices = new int[1]{ 10 };
	state.enemies[6].position = glm::vec3(31, -3, 0);

	state.enemies[7].aiType = UPANDDOWN;
	state.enemies[7].moveUp = true;
	state.enemies[7].animIndices = new int[1]{ 10 };
	state.enemies[7].position = glm::vec3(31, -12, 0);

	// third box

	state.enemies[8].aiType = UPANDDOWN;
	state.enemies[8].moveUp = false;
	state.enemies[8].animIndices = new int[1]{ 13 };
	state.enemies[8].position = glm::vec3(23, -23, 0);

	state.enemies[9].aiType = UPANDDOWN;
	state.enemies[9].moveUp = true;
	state.enemies[9].animIndices = new int[1]{ 13 };
	state.enemies[9].position = glm::vec3(23, -31, 0);

	state.enemies[10].aiType = UPANDDOWN;
	state.enemies[10].moveUp = false;
	state.enemies[10].animIndices = new int[1]{ 13 };
	state.enemies[10].position = glm::vec3(31, -23, 0);

	state.enemies[11].aiType = UPANDDOWN;
	state.enemies[11].moveUp = false;
	state.enemies[11].animIndices = new int[1]{ 13 };
	state.enemies[11].position = glm::vec3(31, -31, 0);

	state.enemies[12].aiType = WALKER;
	state.enemies[12].moveRight = true;
	state.enemies[12].animIndices = new int[1]{ 0 };
	state.enemies[12].position = glm::vec3(23, -31, 0);

	state.enemies[13].aiType = WALKER;
	state.enemies[13].moveRight = false;
	state.enemies[13].animIndices = new int[1]{ 0 };
	state.enemies[13].position = glm::vec3(31, -31, 0);
	
	state.enemies[14].aiType = WAITANDGO;
	state.enemies[14].aiState = IDLE; 
	state.enemies[14].speed = 1.0f;
	state.enemies[14].animIndices = new int[1]{ 8 };
	state.enemies[14].position = glm::vec3(27, -28, 0);

	// fourth box 

	state.enemies[15].aiType = UPANDDOWN;
	state.enemies[15].moveUp = false;
	state.enemies[15].animIndices = new int[1]{ 13 };
	state.enemies[15].position = glm::vec3(1, -23, 0);

	state.enemies[16].aiType = UPANDDOWN;
	state.enemies[16].moveUp = true;
	state.enemies[16].animIndices = new int[1]{ 13 };
	state.enemies[16].position = glm::vec3(1, -31, 0);

	state.enemies[17].aiType = UPANDDOWN;
	state.enemies[17].moveUp = false;
	state.enemies[17].animIndices = new int[1]{ 13 };
	state.enemies[17].position = glm::vec3(3, -23, 0);

	state.enemies[18].aiType = UPANDDOWN;
	state.enemies[18].moveUp = false;
	state.enemies[18].animIndices = new int[1]{ 13 };
	state.enemies[18].position = glm::vec3(3, -31, 0);

	state.enemies[19].aiType = WAITANDGO;
	state.enemies[19].aiState = IDLE;
	state.enemies[19].speed = 1.0f;
	state.enemies[19].animIndices = new int[1]{ 8 };
	state.enemies[19].position = glm::vec3(14, -21, 0);

	state.enemies[20].aiType = WAITANDGO;
	state.enemies[20].aiState = IDLE;
	state.enemies[20].speed = 1.0f;
	state.enemies[20].animIndices = new int[1]{ 8 };
	state.enemies[20].position = glm::vec3(14, -34, 0);

}
void Level1::Update(float deltaTime) {

	state.player->Update(deltaTime, state.player, state.enemies, LEVEL1_ENEMY_COUNT, state.items, LEVEL1_ITEM_COUNT, state.map);

	for (int i = 0; i < LEVEL1_ENEMY_COUNT; ++i) {
		state.enemies[i].Update(deltaTime, state.player, state.enemies, LEVEL1_ENEMY_COUNT, state.items, LEVEL1_ITEM_COUNT, state.map);
	}

	for (int i = 0; i < LEVEL1_ITEM_COUNT; ++i) {
		state.items[i].Update(deltaTime, state.player, state.enemies, LEVEL1_ITEM_COUNT, state.items, LEVEL1_ITEM_COUNT, state.map);
	}

	if (state.player->collidedFinalDoor) {
		state.nextScene = 2; 
		gameOver = true; 
		winner = true; 
	} 

	/*if (enemiesAlive == 0 && state.player->position.x >= 19) {
		state.nextScene = 2;
	}*/

}

void Level1::Render(ShaderProgram* program) {

	state.map->Render(program);
	
	GLuint fontTextureID = Util::LoadTexture("font1.png");
	glm::vec3 sKeysPosition = glm::vec3(0, 0, 0);
	glm::vec3 gKeyPosition = glm::vec3(0, 0, 0);
	glm::vec3 livesPosition = glm::vec3(0, 0, 0);

	livesPosition = glm::vec3(state.player->position.x + 3, state.player->position.y + 3.5f, 0);
	sKeysPosition = glm::vec3(state.player->position.x - 4.6f, state.player->position.y + 3.5f, 0);
	gKeyPosition = glm::vec3(state.player->position.x - 4.6f, state.player->position.y + 3.0f, 0);

	Util::DrawText(program, fontTextureID, "Lives: " + std::to_string(state.player->lives), 0.45f, -0.25f, livesPosition);
	Util::DrawText(program, fontTextureID, "Silver Keys: " + std::to_string(state.player->sKeys), 0.45f, -0.25f, sKeysPosition);
	Util::DrawText(program, fontTextureID, "Golden Keys: " + std::to_string(state.player->gKey), 0.45f, -0.25f, gKeyPosition);

	state.player->Render(program);

	for (int i = 0; i < LEVEL1_ENEMY_COUNT; ++i) {
		state.enemies[i].Render(program);
	}

	for (int i = 0; i < LEVEL1_ITEM_COUNT; ++i) {
		state.items[i].Render(program);
	}

}
