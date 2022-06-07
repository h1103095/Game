#pragma once
#include "Vector2.h"

class Transform
{
public:
	Transform(Vector2<int> position=Vector2<int>::zero(), Vector2<int> scale=Vector2<int>::normal());
	Vector2<int>& GetPosition(void);
	Vector2<int>& GetScale(void);
	void Translate(int x, int y);
	void Translate(Vector2<int>& position);
	void SetScale(int x, int y);
	void SetScale(Vector2<int>& scale);
	void Move(int x, int y);
	void Move(Vector2<int>& vec);
private:
	Vector2<int> position_;
	Vector2<int> scale_;
};

