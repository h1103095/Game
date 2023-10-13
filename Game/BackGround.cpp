#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround(GameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_renderer_(*this, Sprite::GetInstance(IDB_BACKGROUND), LayerID::BACKGROUND)
	, kWidth(2400)
{

}

BackGround::~BackGround(void)
{

}

void BackGround::Update(const float& delta_time)
{
	transform_.Translate(static_cast<int>(kXSpeed * delta_time), 0);
	if (transform_.GetPosition().GetX() <= -kWidth) {
		transform_.Translate(kWidth * 2, 0);
	}
}
