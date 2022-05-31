#include "stdafx.h"
#include "IGameObjectFactory.h"

IGameObject* IGameObjectFactory::Create(GameScene* scene, Vector2 position, Vector2 scale)
{
	return FactoryMethod(scene, position, scale);
}