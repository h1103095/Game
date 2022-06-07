#include "stdafx.h"
#include "Transform.h"

Transform::Transform(Vector2<int> position, Vector2<int> scale)
	: position_(position)
	, scale_(scale)
{

}

Vector2<int>& Transform::GetPosition(void){
	return position_;
}

Vector2<int>& Transform::GetScale(void){
	return scale_;
}

void Transform::Translate(int x, int y) {
	position_.set_x_y(x, y);
}

void Transform::Translate(Vector2<int>& position) {
	position_ = position;
}

void Transform::SetScale(int x, int y) {
	scale_.set_x_y(x, y);
}

void Transform::SetScale(Vector2<int>& scale) {
	scale_ = scale;
}

void Transform::Move(int x, int y) {
	position_.add(x, y);
}

void Transform::Move(Vector2<int>& vec) {
	position_ += vec;
}
