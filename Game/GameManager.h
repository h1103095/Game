#pragma once
#include "GameObject.h"

class GameManager : GameObject
{
public:
	GameManager(GameScene* game_scene, Vector2 position, Vector2 scale);
	virtual ~GameManager(void);
	void GenerateGround(void);

private:
	static bool instantiated_;
};

bool GameManager::instantiated_ = false;

