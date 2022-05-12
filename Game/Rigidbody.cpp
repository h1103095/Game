#include "stdafx.h"
#include "Rigidbody.h"


Rigidbody::Rigidbody(GameObject* parent, bool use_gravity) 
	: GameComponent(parent, ComponentID::RIGIDBODY)
{
	this->transform = parent->GetTransform();
	this->use_gravity = use_gravity;

	Vector2 position = transform->GetPosition();
	Vector2 scale = transform->GetScale();

	rect = CRect((int)position.x, (int)position.y, (int)(position.x + scale.x), (int)(position.y + scale.y));
}

Rigidbody::~Rigidbody() {

}

void Rigidbody::AddForce(float dx, float dy) {

}