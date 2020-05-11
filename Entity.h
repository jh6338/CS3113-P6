#pragma once
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
#include "Map.h" 

enum EntityType { NONE, PLAYER, ENEMY, ITEM };
enum ItemType { NOTHING, ARROW, GOLDENKEY, SILVERKEY, FINALDOOR, DOOR1, DOOR2_1, DOOR2_2, DOOR3, REDPOTION, BLUEPOTION };
enum AIType { WALKER, WAITANDGO, UPANDDOWN };
enum AIState { IDLE, WALKING, ATTACKING };


class Entity {
public:

	EntityType entityType;
	AIType aiType;
	AIState aiState;
	ItemType itemType; 

	EntityType lastCollided = NONE;
	ItemType lastCollidedItem = NOTHING; 

	// find and make inactive the specific entity that the player collided with 
	Entity* lastCollidedEntity = nullptr;

	glm::vec3 position;
	glm::vec3 movement;
	glm::vec3 acceleration;
	glm::vec3 velocity;
	glm::vec3 initialPosition; 

	float width = 1;
	float height = 1;

	int lives;

	bool jump = false;
	float jumpPower = 0;

	float speed;

	GLuint textureID;

	glm::mat4 modelMatrix;

	int* animRight = NULL;
	int* animLeft = NULL;
	int* animUp = NULL;
	int* animDown = NULL;

	int* animIndices = NULL;
	int animFrames = 0;
	int animIndex = 0;
	float animTime = 0;
	int animCols = 0;
	int animRows = 0;

	bool isActive = true;

	bool collidedTop = false;
	bool collidedBottom = false;
	bool collidedLeft = false;
	bool collidedRight = false;

	bool moveRight = false;
	bool moveUp = false; 
	bool collidedFinalDoor = false; 

	int sKeys = 0; 
	int gKey = 0; 
	int count = 1; 

	Entity();

	bool CheckCollision(Entity* other);
	void CheckCollisionsY(Entity* objects, int objectCount);
	void CheckCollisionsX(Entity* objects, int objectCount);
	void CheckCollisionsX(Map* map);
	void CheckCollisionsY(Map* map);

	void Update(float deltaTime, Entity* player, Entity* objects, int objectCount, Entity* items, int itemCount, Map* map);
	void Render(ShaderProgram* program);
	void DrawSpriteFromTextureAtlas(ShaderProgram* program, GLuint textureID, int index);

	void AI(Entity* player);
	void AIWalker();
	void AIWaitAndGo(Entity* player);
	void AIUpAndDown();

};