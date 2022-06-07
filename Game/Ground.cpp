#include "StdAfx.h"
#include "Ground.h"

Ground::Ground(GameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_(*this, IDB_GROUND_SINGLE, LayerID::GROUND)
	, rigidbody_(*this, delta_time_, false)
	, collider_(*this)
{
	rigidbody_.AddForce(kXSpeed, 0.0f);
}

Ground::~Ground(void)
{
	
}

void Ground::SetBitmap(int bitmap_id) {
	sprite_.SetBitmap(bitmap_id);
}