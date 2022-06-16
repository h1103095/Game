#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround(GameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_(*this, IDB_BACKGROUND, LayerID::BACKGROUND)
	, rigidbody_(*this, false)
	, kWidth(transform_.GetScale().GetX())
{
	rigidbody_.AddForce(kXSpeed, 0.0f);
}

BackGround::~BackGround(void)
{

}

void BackGround::Update(const float& delta_time)
{
	if (transform_.GetPosition().GetX() <= -kWidth) {
		transform_.Translate(kWidth * 2, 0);
	}
}