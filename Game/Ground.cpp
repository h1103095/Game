#include "StdAfx.h"
#include "Ground.h"


Ground::Ground(IGameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_renderer_(*this, Sprite::GetInstance(IDB_GROUND_SINGLE), LayerID::GROUND)
	, collider_(*this, Vector2<int>::Zero(), Vector2<int>(100, 10), false)
	, rigidbody_(*this, BodyType::STATIC)
{
	tag_ = GameObjectTag::GROUND;
}

Ground::~Ground(void)
{
#ifdef DEBUG
	TRACE("Ground deleted\n");
#endif
}

void Ground::Update(const float& delta_time) {
	if (transform_.GetPosition().GetX() < -sprite_renderer_.GetSprite()->GetScale().GetX()) {
		scene_.Destroy(shared_from_this());
	}
}
