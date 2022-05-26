#include "StdAfx.h"
#include "Bullet.h"
#include <math.h>


Bullet::Bullet(CPoint playerPoint, CPoint dest)
	: GameObject(playerPoint.x, playerPoint.y, 1, 1)
	, destination_(dest)		// 목적지
	, distance_(sqrt(pow(static_cast<double>(destination_.x) - static_cast<double>(playerPoint.x), 2) +
		pow(static_cast<double>(destination_.y) - static_cast<double>(playerPoint.y), 2)))	// 거리 계산
	, degree_(atan2f(static_cast<float>(destination_.y - playerPoint.y), 
		static_cast<float>(destination_.x - playerPoint.x)))		// 각도 계산
{
}

Bullet::~Bullet(void)
{
}

void Bullet::Move(void)
{
	transform_.Move(static_cast<float>(kSpeed * cos(degree_)), static_cast<float>(kSpeed * sin(degree_)));
	// 총알 이동
}
