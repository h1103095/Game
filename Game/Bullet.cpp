#include "StdAfx.h"
#include "Bullet.h"
#include <math.h>


Bullet::Bullet(GameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, destination_(Vector2<int>::Zero())		// 목적지
	, distance_(sqrt(pow(static_cast<double>(destination_.x) - static_cast<double>(position.x), 2) +
		pow(static_cast<double>(destination_.y) - static_cast<double>(position.y), 2)))	// 거리 계산
	, degree_(atan2f(static_cast<float>(destination_.y - position.y), 
		static_cast<float>(destination_.x - position.x)))		// 각도 계산
{
}

Bullet::~Bullet(void)
{
}

void Bullet::Move(void)
{
	transform_.Translate(static_cast<int>(kSpeed * cos(degree_)), static_cast<int>(kSpeed * sin(degree_)));
	// 총알 이동
}
