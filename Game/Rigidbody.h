#pragma once
#include <memory>
#include "IGameObject.h"
#include "GameComponent.h"
#include "Transform.h"

class Rigidbody: public GameComponent
{
public:
	Rigidbody(IGameObject* parent, float* delta_time, bool use_gravity);
	virtual ~Rigidbody();
	void AddForce(float dx, float dy);
	virtual void Update(void);

private:
	float* delta_time_;
	float x_speed_ = 0.0;
	float y_speed_ = 0.0;
	std::shared_ptr<Transform> transform_;
	bool use_gravity_;
};

