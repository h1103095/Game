#include "StdAfx.h"
#include "Coin.h"


Coin::Coin(int x, int y) 
	: GameObject(x, y, 100, 100), rigidbody(this, false)
{
	sprite = new Sprite(this, IDB_COIN, LayerID::OTHER);
}

Coin::~Coin(void)
{
	delete sprite;
}
