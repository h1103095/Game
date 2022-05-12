#include "stdafx.h"
#include "Collider.h"


Collider::Collider(GameObject* parent) 
	: GameComponent(parent, ComponentID::COLLIDER)
{
	Transform* transform = parent->GetTransform();
	Vector2 position = transform->GetPosition();
	Vector2 scale = transform->GetScale();
	rect = new CRect((int)position.x, (int)position.y, (int)(position.x + scale.x), (int)(position.y + scale.y));
}

Collider::~Collider(void) {

}

bool Collider::OnColliderEnter(GameObject* gameObject) {
	CRect dstRect;
	/*
	if (IntersectRect(&dstRect, &rect, gameObject->GetComponent<Collider>()->GetRect())) {
		return true;
	}
	*/
	return false;
}

CRect* Collider::GetRect(void) {
	return &rect;
}