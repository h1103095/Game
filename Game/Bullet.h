#pragma once
#include "atltypes.h"
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet(GameScene& game_scene, Vector2<int> position, Vector2<int> scale);
	virtual ~Bullet(void);
	void Move(void);

private:
	Vector2<int> destination_;
	const float kSpeed = 17;
	double distance_;
	double degree_;
};
