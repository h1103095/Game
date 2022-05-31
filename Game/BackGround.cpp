#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround(GameScene* game_scene, Vector2 position, Vector2 scale)
	: GameObject(game_scene, position, scale)
	, sprite_(this, IDB_BACKGROUND, LayerID::BACKGROUND)
	, rigidbody_(this, &delta_time_, false)
	, kWidth(transform_.GetScale()->get_int_x())
{
	rigidbody_.AddForce(kXSpeed, 0.0);
}

BackGround::~BackGround(void)
{

}

void BackGround::Update(void)
{
	GameObject::Update();

	if (transform_.GetPosition()->get_int_x() <= -kWidth) {
		transform_.Move(kWidth * 2, 0.0);
	}
}