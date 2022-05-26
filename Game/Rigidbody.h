#pragma once
#include "GameComponent.h"
#include "Transform.h"

class Rigidbody: public GameComponent
{
public:
	Rigidbody(GameObject* parent, bool use_gravity);
	~Rigidbody();
	void AddForce(float dx, float dy);

private:
	float x_speed_ = 0.0;
	float y_speed_ = 0.0;
	Transform* transform_;
	CRect rect_;
	bool use_gravity_;
};

