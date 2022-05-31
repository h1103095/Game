#include "stdafx.h"
#include "Rigidbody.h"


Rigidbody::Rigidbody(IGameObject* parent, float* delta_time, bool use_gravity)
	: GameComponent(parent, ComponentID::RIGIDBODY)
	, delta_time_(delta_time)
	, transform_(parent->GetTransform())
	, use_gravity_(use_gravity)
{

}

Rigidbody::~Rigidbody(void) {

}

void Rigidbody::AddForce(float dx, float dy) {
	x_speed_ += dx;
	y_speed_ += dy;
}

void Rigidbody::Update(void) {
	transform_->Move(x_speed_ * (*delta_time_), y_speed_ * (*delta_time_));
}