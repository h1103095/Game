#pragma once
#include "Vector2.h"

class IGameObject;
class GameScene;

class IGameObjectFactory
{
public:
	virtual IGameObject* FactoryMethod(GameScene* scene, Vector2 position, Vector2 scale) = 0;

	IGameObject* Create(GameScene* scene, Vector2 position=Vector2::zero(), Vector2 scale=Vector2::normal());
	
};
