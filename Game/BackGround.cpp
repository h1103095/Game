#include "stdafx.h"
#include "BackGround.h"

//Sprite BackGround::background_sprite_(IDB_BACKGROUND);


BackGround::BackGround(GameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_renderer_(*this, Sprite::GetInstance(IDB_BACKGROUND), LayerID::BACKGROUND)
	, rigidbody_(*this, false)
	, kWidth(2400)
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

//Sprite BackGround::background_sprite_(IDB_BACKGROUND);
