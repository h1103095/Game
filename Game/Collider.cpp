#include "stdafx.h"
#include "Collider.h"


Collider::Collider(IGameObject& parent)
	: GameComponent(parent, ComponentID::COLLIDER)
	, rect_(new CRect())
{
	Transform& transform = parent.GetTransform();
	Vector2<int>& position = transform.GetPosition();
	Vector2<int>& scale = transform.GetScale();
	int pos_x = position.get_x();
	int pos_y = position.get_y();
	int scale_x = scale.get_x();
	int scale_y = scale.get_y();
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