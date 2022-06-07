#include "StdAfx.h"
#include "Coin.h"


Coin::Coin(GameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
{
	//sprite = new Sprite(this, IDB_COIN, LayerID::OTHER);
}

Coin::~Coin(void)
{

}
