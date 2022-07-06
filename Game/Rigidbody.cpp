#include "stdafx.h"
#include "Rigidbody.h"


Rigidbody::Rigidbody(IGameObject& parent, bool use_gravity)
	: GameComponent(parent)
	, transform_(parent.GetTransform())
	, speed_(Vector2<float>::Zero())
	, use_gravity_(use_gravity)
{
}

Rigidbody::~Rigidbody(void) {

}

void Rigidbody::SetForce(float x, float y) {
	speed_.x = x;
	speed_.y = y;
}

void Rigidbody::AddForce(float dx, float dy) {
	speed_.Add(dx, dy);
}

void Rigidbody::ResetForce(void) {
	speed_.x = 0.0f;
	speed_.y = 0.0f;
}

void Rigidbody::Update(const float& delta_time) {
	if (use_gravity_) {
		AddForce(0.0f, kGravity_);
	}
	transform_.Translate(speed_ * delta_time);
}

Transform& Rigidbody::GetTransform(void) {
	return transform_;
}

Vector2<float> Rigidbody::GetSpeed(void) {
	return speed_;
}