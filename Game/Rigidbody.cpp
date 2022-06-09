#include "stdafx.h"
#include "Rigidbody.h"


Rigidbody::Rigidbody(IGameObject& parent, bool use_gravity)
	: GameComponent(parent, ComponentID::RIGIDBODY)
	, transform_(parent.GetTransform())
	, use_gravity_(use_gravity)
{
}

Rigidbody::~Rigidbody(void) {

}

void Rigidbody::AddForce(float dx, float dy) {
	x_speed_ += dx;
	y_speed_ += dy;
}

void Rigidbody::Update(const float& delta_time) {
	if (use_gravity_) {
		AddForce(0.0f, 9.8f);
	}
	transform_.Translate(static_cast<int>(x_speed_ * delta_time), static_cast<int>(y_speed_ * delta_time));
}