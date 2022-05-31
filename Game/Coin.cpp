#include "StdAfx.h"
#include "Coin.h"


Coin::Coin(GameScene* game_scene, Vector2 position, Vector2 scale) 
	: GameObject(game_scene, position, scale)
{
	//sprite = new Sprite(this, IDB_COIN, LayerID::OTHER);
}

Coin::~Coin(void)
{

}
