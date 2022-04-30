#include "stdafx.h"
#include "Vector2.h"

Vector2::Vector2() {

}

Vector2::Vector2(int x, int y) {
	this->x = x;
	this->y = y;
}

Vector2::~Vector2() {

}

float Vector2::get_x() {
	return x;
}

float Vector2::get_y() {
	return y;
}

Vector2 Vector2::operator+(const Vector2& vec) {
	return Vector2(this->x + vec.x, this->y + vec.y);
}

Vector2& Vector2::operator+=(const Vector2& vec) {
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}