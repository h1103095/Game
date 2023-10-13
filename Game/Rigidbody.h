#pragma once
#include <memory>
#include "IGameObject.h"
#include "GameComponent.h"
#include "Transform.h"
#include "BodyType.h"

class Rigidbody: public GameComponent
{
public:
	Rigidbody(IGameObject& parent, BodyType body_type);
	virtual ~Rigidbody();
	void SetForce(float dx, float dy);
	void AddForce(float dx, float dy);
	void ResetForce(void);
	virtual void Update(const float& delta_time);

	Transform GetTransform(void);
	Vector2<float> GetSpeed(void);
	BodyType GetBodyType(void);

private:
	Transform& transform_;
	Vector2<float> speed_;
	BodyType body_type_;
	const float kGravity_ = 12.0f; // 9.8f
};

