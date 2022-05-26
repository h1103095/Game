#include "stdafx.h"
#include "Rigidbody.h"


Rigidbody::Rigidbody(GameObject* parent, bool use_gravity) 
	: GameComponent(parent, ComponentID::RIGIDBODY)
{
	this->transform_ = parent->GetTransform();
	this->use_gravity_ = use_gravity;

	Vector2* position = transform_->GetPosition();
	Vector2* scale = transform_->GetScale();

	rect_ = CRect(position->get_int_x(), position->get_int_y(),
		position->get_int_x() + scale->get_int_x(),
		position->get_int_y() + scale->get_int_y());
}

Rigidbody::~Rigidbody() {

}

void Rigidbody::AddForce(float dx, float dy) {

}