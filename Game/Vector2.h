#pragma once
#include <cmath>

template<typename T>
class Vector2
{
public:
	Vector2(T x, T y)
		: x(x)
		, y(y)
	{

	}
	~Vector2(void) {}

	static Vector2<T> Zero(void) {
		return Vector2<T>(0, 0);
	}
	static Vector2<T> Normal(void) {
		return Vector2<T>(1, 1);
	}

	Vector2<T> operator+(const Vector2& vec) {
		return Vector2<T>(x + vec.x, y + vec.y);
	}
	Vector2<T>& operator+=(const Vector2& vec) {
		x += vec.x;
		y += vec.y;
		return *this;
	}

	void SetX(T x) {
		this->x = x;
	}
	void SetY(T y) {
		this->y = y;
	}
	void SetXY(T x, T y) {
		this->x = x;
		this->y = y;
	}

	T GetX(void) const {
		return x;
	}
	T GetY(void) const {
		return y;
	}
	void Add(T x, T y) {
		this->x += x;
		this->y += y;
	}

	T x;
	T y;
};

template class Vector2<int>;
template class Vector2<float>;