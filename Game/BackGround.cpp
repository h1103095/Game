#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround(IGameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_renderer_(*this, Sprite::GetInstance(IDB_BACKGROUND), LayerID::BACKGROUND)
	, rigidbody_(*this, BodyType::STATIC)
{

}

BackGround::~BackGround(void)
{

}

void BackGround::Update(const float& delta_time)
{
	if (transform_.GetPosition().GetX() <= -WND_X * 2) {
		transform_.Translate(WND_X * 2, 0);
	}
}
