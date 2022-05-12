#pragma once
#include "Vector2.h"
#include "GameObject.h"
#include "GameComponent.h"
#include "Transform.h"

class Collider: GameComponent
{
public:
	Collider(GameObject* parent);
	~Collider(void);
	bool OnColliderEnter(GameObject* gameObject);
	CRect* GetRect(void);
private:
	CRect rect;
};

