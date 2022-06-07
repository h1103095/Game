#pragma once
#include "atltypes.h"
#include "GameObject.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Sprite.h"
#include "Game.h"

class Coin: public GameObject
{
public:
	Coin(GameScene& game_scene, Vector2<int> position, Vector2<int> scale);
	virtual ~Coin(void);
};

