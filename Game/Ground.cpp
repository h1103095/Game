#include "StdAfx.h"
#include "Ground.h"

Ground::Ground(GameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_(*this, IDB_GROUND_SINGLE, LayerID::GROUND)
	, collider_(*this, transform_.GetPosition(), transform_.GetScale())
{
	tag_ = GameObjectTag::GROUND;
}

Ground::~Ground(void)
{
#ifdef DEBUG
	TRACE("Ground deleted\n");
#endif
}

void Ground::SetBitmap(int bitmap_id) {
	sprite_.SetBitmap(bitmap_id);
}

void Ground::Update(const float& delta_time) {
	GameObject::Update(delta_time);

	transform_.Translate(static_cast<int>(kXSpeed * delta_time), 0);
	if (transform_.GetPosition().GetX() < -transform_.GetScale().GetX()) {
		scene_.Destroy(shared_from_this());
	}
}