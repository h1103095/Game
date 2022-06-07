#include "stdafx.h"
#include "Rigidbody.h"


Rigidbody::Rigidbody(IGameObject& parent, float& delta_time, bool use_gravity)
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
	transform_.Move(static_cast<int>(x_speed_ * delta_time), static_cast<int>(y_speed_ * delta_time));
}