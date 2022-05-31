#include "StdAfx.h"
#include "Ground.h"

Ground::Ground(GameScene* game_scene, Vector2 position, Vector2 scale)
	: GameObject(game_scene, position, scale)
	, sprite_(this, IDB_GROUND_SINGLE, LayerID::GROUND)
	, rigidbody_(this, false)
	, collider_(this)
{
}

Ground::~Ground(void)
{
	
}

void Ground::SetBitmap(int bitmap_id) {
	sprite_.SetBitmap(bitmap_id);
}