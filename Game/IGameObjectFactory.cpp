#include "stdafx.h"
#include "IGameObjectFactory.h"

std::shared_ptr<IGameObject> IGameObjectFactory::Create(GameScene& scene, Vector2<int> position, Vector2<int> scale)
{
	return FactoryMethod(scene, position, scale);
}