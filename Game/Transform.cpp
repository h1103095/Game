#include "stdafx.h"
#include "Transform.h"

Transform::Transform()
	: position(Vector2(0, 0))
	, scale(Vector2(1, 1))
{

}

Transform::Transform(Vector2 position)
	: position(position)
	, scale(Vector2(1, 1))
{

}

Transform::Transform(Vector2 position, Vector2 scale)
	: position(position)
	, scale(scale)
{

}

Vector2 Transform::GetPosition(void) {
	return position;
}

Vector2 Transform::GetScale(void) {
	return scale;
}

void Transform::Translate(int x, int y) {
	position = Vector2(x, y);
}

void Transform::Translate(Vector2 position) {
	this->position = position;
}

void Transform::SetScale(int x, int y) {
	scale = Vector2(x, y);
}

void Transform::SetScale(Vector2 scale) {
	this->scale = scale;
}

void Transform::Move(int x, int y) {
	position.x += x;
	position.y += y;
}

void Transform::Move(Vector2 vec) {
	position += vec;
}
