#include "stdafx.h"
#include "Vector2.h"

Vector2::Vector2(int x, int y)
	:x(static_cast<float>(x)), y(static_cast<float>(y))
{

}

Vector2::Vector2(float x, float y)
	:x(x), y(y)
{

}

Vector2::~Vector2(void) {

}

Vector2 Vector2::zero(void) {
	return Vector2(0, 0);
}

Vector2 Vector2::normal(void) {
	return Vector2(1, 1);
}

Vector2 Vector2::operator+(const Vector2& vec) {
	return Vector2(this->x + vec.x, this->y + vec.y);
}

Vector2& Vector2::operator+=(const Vector2& vec) {
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

int Vector2::get_int_x(void) const {
	return static_cast<int>(x);
}

int Vector2::get_int_y(void) const {
	return static_cast<int>(y);
}

float Vector2::get_x(void) const {
	return x;
}

float Vector2::get_y(void) const {
	return y;
}

void Vector2::add(float x, float y) {
	this->x += x;
	this->y += y;
}
