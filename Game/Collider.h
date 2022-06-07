#pragma once
#include "Vector2.h"
#include "IGameObject.h"
#include "GameComponent.h"
#include "Transform.h"

class Collider: public GameComponent
{
public:
	Collider(IGameObject& parent);
	virtual ~Collider(void);
	bool OnColliderEnter(IGameObject* game_object) const;
	CRect& GetRect(void);

private:
	CRect rect_;
};

