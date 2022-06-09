#include "stdafx.h"
#include "Collider.h"


Collider::Collider(IGameObject& parent, Vector2<int> position, Vector2<int> scale)
	: GameComponent(parent, ComponentID::COLLIDER)
	, rect_()
{
	int pos_x = position.GetX();
	int pos_y = position.GetY();
	int scale_x = scale.GetX();
	int scale_y = scale.GetY();
	rect_.left = pos_x;
	rect_.top = pos_y;
	rect_.right = pos_x + scale_x;
	rect_.bottom = pos_y + scale_y;
}

Collider::~Collider(void) {

}

bool Collider::OnColliderEnter(IGameObject* gameObject) const {
	CRect dstRect;
	/*
	if (IntersectRect(&dstRect, &rect, gameObject->GetComponent<Collider>()->GetRect())) {
		return true;
	}
	*/
	return false;
}

CRect& Collider::GetRect(void) {
	return rect_;
}