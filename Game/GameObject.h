#pragma once
#include "Vector2.h"

class GameObject
{
public:
	GameObject(void);
	~GameObject(void);

protected:
	void Start(void);
	void Update(void);
	Vector2 position;
	Vector2 scale;
};