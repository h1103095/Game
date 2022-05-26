#include "StdAfx.h"
#include "Coin.h"


Coin::Coin(int x, int y) 
	: GameObject(x, y, 100, 100)
{
	//sprite = new Sprite(this, IDB_COIN, LayerID::OTHER);
}

Coin::~Coin(void)
{

}
