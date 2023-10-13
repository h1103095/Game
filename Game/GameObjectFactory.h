#pragma once
#include "IGameObjectFactory.h"
#include "BackGround.h"
#include "Ground.h"
#include "Player.h"
#include "Wall.h"
#include "Coin.h"

class GameScene;

template <class T>
class GameObjectFactory: public IGameObjectFactory
{
public:
	GameObjectFactory(void) {};
	virtual ~GameObjectFactory(void) {};
	virtual std::shared_ptr<IGameObject> FactoryMethod(GameScene& scene, Vector2<int> position, Vector2<int> scale)
	{
		return std::make_shared<T>(scene, position, scale);
	}
};

template class GameObjectFactory<BackGround>;
template class GameObjectFactory<Ground>;
template class GameObjectFactory<Coin>;
template class GameObjectFactory<Player>;
template class GameObjectFactory<Wall>;