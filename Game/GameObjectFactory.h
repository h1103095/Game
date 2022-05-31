#pragma once
#include "IGameObjectFactory.h"
#include "BackGround.h"
#include "Ground.h"
#include "Player.h"

class GameScene;

template <class T>
class GameObjectFactory: public IGameObjectFactory
{
public:
	GameObjectFactory(void) {};
	virtual ~GameObjectFactory(void) {};
	virtual IGameObject* FactoryMethod(GameScene* scene, Vector2 position, Vector2 scale)
	{
		return new T(scene, position, scale);
	}
};

template class GameObjectFactory<BackGround>;
template class GameObjectFactory<Ground>;
template class GameObjectFactory<Player>;