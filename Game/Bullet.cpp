#include "StdAfx.h"
#include "Bullet.h"
#include <math.h>


Bullet::Bullet(GameScene* game_scene, Vector2 position, Vector2 scale)
	: GameObject(game_scene, position, scale)
	, destination_(Vector2::zero())		// ������
	, distance_(sqrt(pow(static_cast<double>(destination_.x) - static_cast<double>(position.x), 2) +
		pow(static_cast<double>(destination_.y) - static_cast<double>(position.y), 2)))	// �Ÿ� ���
	, degree_(atan2f(static_cast<float>(destination_.y - position.y), 
		static_cast<float>(destination_.x - position.x)))		// ���� ���
{
}

Bullet::~Bullet(void)
{
}

void Bullet::Move(void)
{
	transform_.Move(static_cast<float>(kSpeed * cos(degree_)), static_cast<float>(kSpeed * sin(degree_)));
	// �Ѿ� �̵�
}
