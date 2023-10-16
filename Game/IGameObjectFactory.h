#pragma once
#include <memory>
#include "Vector2.h"

class IGameObject;
class IGameScene;

class IGameObjectFactory
{
public:
	virtual std::shared_ptr<IGameObject> FactoryMethod(const CString& classname, IGameScene& scene, Vector2<int> position, Vector2<int> scale);

	std::shared_ptr<IGameObject> Instantiate(const CString& classname, IGameScene& scene, Vector2<int> position=Vector2<int>::Zero(), Vector2<int> scale=Vector2<int>::Normal());
	
};
