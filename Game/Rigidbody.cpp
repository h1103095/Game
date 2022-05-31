#include "stdafx.h"
#include "Rigidbody.h"


Rigidbody::Rigidbody(IGameObject* parent, bool use_gravity)
	: GameComponent(parent, ComponentID::RIGIDBODY)
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
	transform_->Move(x_speed_, y_speed_);
}