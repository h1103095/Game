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

	static Vector2<T> zero(void) {
		return Vector2<T>(0, 0);
	}
	static Vector2<T> normal(void) {
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

	void set_x(T x) {
		this->x = x;
	}
	void set_y(T y) {
		this->y = y;
	}
	void set_x_y(T x, T y) {
		this->x = x;
		this->y = y;
	}

	T get_x(void) const {
		return x;
	}
	T get_y(void) const {
		return y;
	}
	void add(T x, T y) {
		this->x += x;
		this->y += y;
	}

	T x;
	T y;
};

template class Vector2<int>;
template class Vector2<float>;