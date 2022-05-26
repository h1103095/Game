#pragma once
#include <memory>
#include "ComponentID.h"
#include "GameObject.h"

class GameObject;

class GameComponent
{
public:
	GameComponent(GameObject* parent, ComponentID id);
	virtual ~GameComponent(void);
	ComponentID GetID(void) const;

protected:
	std::tr1::shared_ptr<GameObject> parent_;
	const ComponentID id_;
};

