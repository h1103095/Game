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
	position_.Add(x, y);
}

void Transform::Translate(const Vector2<int>& vec) {
	position_ += vec;
}

void Transform::SetPosition(int x, int y) {
	position_.SetXY(x, y);
}

void Transform::SetPosition(Vector2<int> position) {
	position_ = position;
}

void Transform::SetScale(int x, int y) {
	scale_.SetXY(x, y);
}

void Transform::SetScale(Vector2<int> scale) {
	scale_ = scale;
}
