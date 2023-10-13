#pragma once
#include <memory>
#include "IGameObject.h"
#include "GameComponent.h"
#include "Transform.h"

class Rigidbody: public GameComponent
{
public:
	Rigidbody(IGameObject& parent, bool use_gravity);
	virtual ~Rigidbody();
	void SetForce(float dx, float dy);
	void AddForce(float dx, float dy);
	void ResetForce(void);
	virtual void Update(const float& delta_time);

	Transform& GetTransform(void);
	Vector2<float> GetSpeed(void);

private:
	Transform& transform_;
	Vector2<float> speed_;
	bool use_gravity_;
	const float kGravity_ = 12.0f; // 9.8f보다 빠르게
};

