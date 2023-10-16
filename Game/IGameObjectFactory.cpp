#include "stdafx.h"
#include "IGameObjectFactory.h"

std::shared_ptr<IGameObject> IGameObjectFactory::Instantiate(const CString& classname, IGameScene& scene, Vector2<int> position, Vector2<int> scale)
{
	return FactoryMethod(classname, scene, position, scale);
}