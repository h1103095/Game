#pragma once
#include "GameComponent.h"
#include "Transform.h"

class Rigidbody: GameComponent
{
public:
	Rigidbody(GameObject* parent, bool use_gravity);
	~Rigidbody();
	void AddForce(float dx, float dy);

private:
	float x_speed = 0.0;
	float y_speed = 0.0;
	Transform* transform;
	CRect rect;
	bool use_gravity;
};

