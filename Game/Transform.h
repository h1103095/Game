#pragma once
#include "GameComponent.h"
#include "Vector2.h"

class Transform: GameComponent
{
public:
	Transform(void);
	Transform(Vector2 position);
	Transform(Vector2 position, Vector2 scale);
	Vector2 get_position(void);
	Vector2 get_scale(void);
	void translate(int x, int y);
	void translate(Vector2 position);
	void set_scale(int x, int y);
	void set_scale(Vector2 scale);
	void move(int x, int y);
	void move(Vector2 vec);
private:
	Vector2 position;
	Vector2 scale;
};

