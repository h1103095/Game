#pragma once
#include "ComponentID.h"
#include "GameObject.h"

class GameObject;

class GameComponent
{
public:
	GameComponent(GameObject* parent, ComponentID id);
	~GameComponent(void);
	ComponentID GetID(void);

protected:
	GameObject* parent;
	ComponentID id;
};

