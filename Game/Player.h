#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Animator.h"
#include "Rigidbody.h"

class Player: public GameObject
{
public:
	Player(GameScene& game_scene, Vector2<int> position, Vector2<int> scale);
	virtual ~Player(void);

private:
	Sprite sprite_;
	Animator animator_;
	Rigidbody rigidbody_;
	Collider collider_;
};

