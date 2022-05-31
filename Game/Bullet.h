#pragma once
#include "atltypes.h"
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet(GameScene* game_scene, Vector2 position, Vector2 scale);
	virtual ~Bullet(void);
	void Move(void);

private:
	Vector2 destination_;
	const float kSpeed = 17;
	double distance_;
	double degree_;
};

