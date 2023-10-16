#include "StdAfx.h"
#include "Coin.h"


Coin::Coin(IGameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_renderer_(*this, Sprite::GetInstance(IDB_COIN), LayerID::PLAYER)
	, collider_(*this, Vector2<int>::Zero(), Vector2<int>(100, 100), true)
	, speed_(0.f)
{
	tag_ = GameObjectTag::COIN;
}

Coin::~Coin(void)
{

}

void Coin::SetSpeed(float speed) {
	speed_ = speed;
}

void Coin::Update(const float& delta_time)
{
	transform_.Translate(static_cast<int>(speed_ * delta_time), 0);
	if (transform_.GetPosition().GetX() < -sprite_renderer_.GetSprite()->GetScale().GetX()) {
		scene_.Destroy(shared_from_this());
	}
}
