#include "StdAfx.h"
#include "Bullet.h"
#include <math.h>


Bullet::Bullet(IGameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, destination_(Vector2<int>::Zero())		// 목적지
	, collider_(*this, Vector2<int>::Zero(), Vector2<int>(10, 10), true)
	, degree_(0)		// 각도 계산
{
}

Bullet::~Bullet(void)
{
}

void Bullet::Update(void) {
	Move();
}

void Bullet::OnColliderEnter(Collision& collision) {
	std::shared_ptr<IGameObject> object = collision.GetGameObject();
	if (object->GetTag() == GameObjectTag::ENEMY) {
		scene_.Destroy(object);
	}
}

void Bullet::Move(void)
{
	transform_.Translate(static_cast<int>(kSpeed * cos(degree_)), static_cast<int>(kSpeed * sin(degree_)));
	// 총알 이동
}

void Bullet::SetDestination(Vector2<int> destination) {
	destination_ = destination;
	degree_ = atan2f(static_cast<float>(destination_.y - transform_.GetPosition().y), static_cast<float>(destination_.x - transform_.GetPosition().x));
}