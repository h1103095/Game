#include "StdAfx.h"
#include "Bullet.h"
#include <math.h>


Bullet::Bullet(IGameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_renderer_(*this, Sprite::GetInstance(IDB_BULLET), LayerID::PLAYER)
	, collider_(*this, Vector2<int>::Zero(), Vector2<int>(10, 10), true)
	, rigidbody_(*this, BodyType::STATIC)
{
	tag_ = GameObjectTag::BULLET;
}

Bullet::~Bullet(void)
{
}

void Bullet::Update(const float& delta_time) {
	int& x = transform_.GetPosition().x;
	int& y = transform_.GetPosition().y;
	if (x < 0 || x > WND_X || y < 0 || y > WND_Y) {
		scene_.Destroy(shared_from_this());
	}
}

void Bullet::OnColliderEnter(Collision& collision) {
	std::shared_ptr<IGameObject> object = collision.GetGameObject();
	if (object->GetTag() == GameObjectTag::ENEMY) {
		scene_.Destroy(object);
	}
}