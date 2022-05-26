#pragma once
#include "Vector2.h"
#include "GameObject.h"
#include "GameComponent.h"
#include "Transform.h"

class Collider: public GameComponent
{
public:
	Collider(GameObject* parent);
	virtual ~Collider(void);
	bool OnColliderEnter(GameObject* game_object) const;
	CRect* GetRect(void);

private:
	CRect rect_;
};

