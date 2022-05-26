#include "stdafx.h"
#include "Collider.h"


Collider::Collider(GameObject* parent) 
	: GameComponent(parent, ComponentID::COLLIDER)
	, rect_(new CRect())
{
	Transform* transform = parent->GetTransform();
	Vector2* position = transform->GetPosition();
	Vector2* scale = transform->GetScale();
	int pos_x = position->get_int_x();
	int pos_y = position->get_int_y();
	int scale_x = scale->get_int_x();
	int scale_y = scale->get_int_y();
	rect_.left = pos_x;
	rect_.top = pos_y;
	rect_.right = pos_x + scale_x;
	rect_.bottom = pos_y + scale_y;
}

Collider::~Collider(void) {

}

bool Collider::OnColliderEnter(GameObject* gameObject) const {
	CRect dstRect;
	/*
	if (IntersectRect(&dstRect, &rect, gameObject->GetComponent<Collider>()->GetRect())) {
		return true;
	}
	*/
	return false;
}

CRect* Collider::GetRect(void) {
	return &rect_;
}