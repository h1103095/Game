#pragma once
#include "Vector2.h"

class Transform
{
public:
	Transform(Vector2<int> position=Vector2<int>::Zero(), Vector2<int> scale=Vector2<int>::Normal());
	Vector2<int>& GetPosition(void);
	Vector2<int>& GetScale(void);
	void Translate(int x, int y);
	void Translate(const Vector2<int>& vec);
	void Translate(const Vector2<float>& vec);
	void SetPosition(int x, int y);
	void SetPosition(Vector2<int> position);
	void SetScale(int x, int y);
	void SetScale(Vector2<int> scale);
private:
	Vector2<int> position_;
	Vector2<int> scale_;
};

