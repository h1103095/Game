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

Vector2 Transform::get_position(void) {
	return position;
}

Vector2 Transform::get_scale(void) {
	return scale;
}

void Transform::translate(int x, int y) {
	position = Vector2(x, y);
}

void Transform::translate(Vector2 position) {
	this->position = position;
}

void Transform::set_scale(int x, int y) {
	scale = Vector2(x, y);
}

void Transform::set_scale(Vector2 scale) {
	this->scale = scale;
}

void Transform::move(int x, int y) {
	position.x += x;
	position.y += y;
}

void Transform::move(Vector2 vec) {
	position += vec;
}
