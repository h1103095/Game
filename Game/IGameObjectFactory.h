#pragma once
#include <memory>
#include "Vector2.h"

class IGameObject;
class GameScene;

class IGameObjectFactory
{
public:
	virtual std::shared_ptr<IGameObject> FactoryMethod(GameScene& scene, Vector2<int> position, Vector2<int> scale) = 0;

	std::shared_ptr<IGameObject> Create(GameScene& scene, Vector2<int> position=Vector2<int>::zero(), Vector2<int> scale=Vector2<int>::normal());
	
};
