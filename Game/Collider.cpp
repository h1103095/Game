#include "stdafx.h"
#include "Collider.h"


Collider::Collider(IGameObject& parent, Vector2<int> position, Vector2<int> scale, bool is_trigger)
	: GameComponent(parent)
	, position_(position)
	, parent_pos_(parent_.GetTransform().GetPosition())
	, rect_()
	, is_trigger_(is_trigger)
{
	int pos_x = position_.GetX() + parent_pos_.GetX();
	int pos_y = position_.GetY() + parent_pos_.GetY();
	rect_.left = pos_x;
	rect_.top = pos_y;
	rect_.right = pos_x + scale.GetX();
	rect_.bottom = pos_y + scale.GetY();
}

Collider::~Collider(void) {

}

void Collider::Update(const float& delta_time) {
}

bool Collider::IsTrigger(void) {
	return is_trigger_;
}

CRect Collider::GetRect(void) {
	rect_.MoveToXY(position_.GetX() + parent_pos_.GetX(), position_.GetY() + parent_pos_.GetY());
	return rect_;
}