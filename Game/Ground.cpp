#include "StdAfx.h"
#include "Ground.h"


Ground::Ground(IGameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_renderer_(*this, Sprite::GetInstance(IDB_GROUND_SINGLE), LayerID::GROUND)
	, collider_(*this, Vector2<int>::Zero(), Vector2<int>(100, 10), false)
	, speed_(0.f)
{
	tag_ = GameObjectTag::GROUND;
}

Ground::~Ground(void)
{
#ifdef DEBUG
	TRACE("Ground deleted\n");
#endif
}

void Ground::SetSpeed(float speed) {
	speed_ = speed;
}

void Ground::Update(const float& delta_time) {
	transform_.Translate(static_cast<int>(speed_ * delta_time), 0);
	if (transform_.GetPosition().GetX() < -sprite_renderer_.GetSprite()->GetScale().GetX()) {
		scene_.Destroy(shared_from_this());
	}
}
