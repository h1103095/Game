#include "stdafx.h"
#include "Transform.h"

Transform::Transform()
	: position_(Vector2::zero())
	, scale_(Vector2::normal())
{

}

Transform::Transform(Vector2 position)
	: position_(position)
	, scale_(Vector2::normal())
{

}

Transform::Transform(Vector2 position, Vector2 scale)
	: position_(position)
	, scale_(scale)
{

}

Vector2* Transform::GetPosition(void){
	return &position_;
}

Vector2* Transform::GetScale(void){
	return &scale_;
}

void Transform::Translate(float x, float y) {
	position_ = Vector2(x, y);
}

void Transform::Translate(Vector2& position) {
	position_ = position;
}

void Transform::SetScale(float x, float y) {
	scale_ = Vector2(x, y);
}

void Transform::SetScale(Vector2& scale) {
	scale_ = scale;
}

void Transform::Move(float x, float y) {
	position_.add(x, y);
}

void Transform::Move(Vector2& vec) {
	position_ += vec;
}
