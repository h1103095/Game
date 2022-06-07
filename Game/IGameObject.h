#pragma once
#include "Vector2.h"
#include "ComponentID.h"

class GameComponent;
class GameScene;
class Transform;
class Sprite;

class IGameObject
{
public:
	virtual ~IGameObject() {};
	virtual void AddComponent(GameComponent* component) = 0;
	virtual void Start(void) = 0;
	virtual void Update(const float& delta_time) = 0;
	virtual GameComponent* GetComponent(ComponentID id) = 0;
	virtual Sprite* GetSprite(void) = 0;
	virtual Transform& GetTransform(void) = 0;
	virtual GameScene& GetGameScene(void) = 0;
};
