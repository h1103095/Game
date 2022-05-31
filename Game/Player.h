#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Animator.h"

class Player: public GameObject
{
public:
	Player(GameScene* game_scene, Vector2 position, Vector2 scale);
	virtual ~Player(void);

private:
	Sprite sprite_;
	Animator animator_;
};

