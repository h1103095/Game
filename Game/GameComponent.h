#pragma once
#include <memory>
#include "ComponentID.h"
#include "IGameObject.h"

class GameComponent
{
public:
	GameComponent(IGameObject* parent, ComponentID id);
	virtual ~GameComponent(void);
	ComponentID GetID(void) const;
	virtual void Update(void);

protected:
	IGameObject* parent_;
	const ComponentID id_;
};

