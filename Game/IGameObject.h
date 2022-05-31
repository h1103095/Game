#pragma once
#include "Vector2.h"
#include "ComponentID.h"

class GameComponent;
class Transform;

class IGameObject
{
public:
	virtual ~IGameObject() {};
	virtual void AddComponent(GameComponent* component) = 0;
	virtual void Start(void) = 0;
	virtual void Update(void) = 0;
	virtual GameComponent* GetComponent(ComponentID id) = 0;
	virtual Transform* GetTransform(void) = 0;
};

