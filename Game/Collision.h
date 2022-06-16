#pragma once
#include <memory>
#include "IGameObject.h"
#include "GameObjectTag.h"

class Collision
{
public:
	Collision(std::shared_ptr<IGameObject> game_object, CRect collision_area);
	virtual ~Collision(void);
	std::shared_ptr<IGameObject> GetGameObject(void);
	const CRect& GetCollisionArea(void);
	const GameObjectTag& GetTag(void);

private:
	std::shared_ptr<IGameObject> game_object_;
	CRect collision_area_;
	GameObjectTag tag_;
};

