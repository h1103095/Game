#include "stdafx.h"
#include "PlayerJumpingAnimation.h"

PlayerJumpingAnimation::PlayerJumpingAnimation(bool loop, float time_interval)
	: Animation(loop, time_interval)
{
	sprites_.push_back(Sprite::GetInstance(IDB_BIRD_JUMP1));
	sprites_.push_back(Sprite::GetInstance(IDB_BIRD_JUMP2));
}