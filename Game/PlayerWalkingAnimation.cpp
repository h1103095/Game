#include "stdafx.h"
#include "PlayerWalkingAnimation.h"

PlayerWalkingAnimation::PlayerWalkingAnimation(bool loop, float time_interval)
	: Animation(loop, time_interval)
{
	sprites_.push_back(Sprite::GetInstance(IDB_BIRD_WALK1));
	sprites_.push_back(Sprite::GetInstance(IDB_BIRD_WALK2));
	sprites_.push_back(Sprite::GetInstance(IDB_BIRD_WALK3));
	sprites_.push_back(Sprite::GetInstance(IDB_BIRD_WALK4));
}