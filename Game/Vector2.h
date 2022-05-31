#pragma once
class Vector2
{
public:
	Vector2(int x, int y);
	Vector2(float x, float y);
	~Vector2(void);

	static Vector2 zero(void);
	static Vector2 normal(void);

	Vector2 operator+(const Vector2& vec);
	Vector2& operator+=(const Vector2& vec);

	int get_int_x(void) const;
	int get_int_y(void) const;
	float get_x(void) const;
	float get_y(void) const;
	void add(float x, float y);

	float x;
	float y;
};
