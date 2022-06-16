#pragma once
#include "Vector2.h"
#include "IGameObject.h"
#include "GameComponent.h"
#include "Transform.h"
#include "GameObjectTag.h"

class Collider: public GameComponent
{
public:
	Collider(IGameObject& parent, Vector2<int> position, Vector2<int> scale, bool is_trigger);
	virtual ~Collider(void);
	virtual void Update(const float& delta_time);
	bool IsTrigger(void);
	CRect& GetRect(void);

private:
	Vector2<int> position_;
	Vector2<int>& parent_pos_;
	CRect rect_;
	bool is_trigger_;
};

