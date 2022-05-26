#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround(int x, int y)
	: GameObject(x, y)
	, sprite_(this, IDB_BACKGROUND, LayerID::BACKGROUND)
	, rigidbody_(this, false)
{
	AddComponent(&sprite_);
}

BackGround::BackGround(int x, int y, int width, int height)
	: GameObject(x, y, width, height)
	, sprite_(this, IDB_BACKGROUND, LayerID::BACKGROUND)
	, rigidbody_(this, false)
{
	AddComponent(&sprite_);
}

BackGround::~BackGround(void)
{

}