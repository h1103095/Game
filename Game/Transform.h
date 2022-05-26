#pragma once
#include "Vector2.h"

class Transform
{
public:
	Transform(void);
	Transform(Vector2 position);
	Transform(Vector2 position, Vector2 scale);
	Vector2* GetPosition(void);
	Vector2* GetScale(void);
	void Translate(float x, float y);
	void Translate(Vector2& position);
	void SetScale(float x, float y);
	void SetScale(Vector2& scale);
	void Move(float x, float y);
	void Move(Vector2& vec);
private:
	Vector2 position_;
	Vector2 scale_;
};

