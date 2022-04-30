#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(int x, int y);
	~Vector2();
	float get_x();
	float get_y();
	float x;
	float y;

	Vector2 operator+(const Vector2& vec);
	Vector2& operator+=(const Vector2& vec);
private:
	
};
