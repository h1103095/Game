#include "stdafx.h"
#include "Animation.h"

int Animation::cur_idx_ = 0;

Animation::Animation(bool loop, float time_interval)
	: loop_(loop)
	, time_interval_(time_interval)
{

}

std::shared_ptr<Sprite> Animation::GetNextSprite(void) {
	cur_idx_++;
	if (cur_idx_ % sprites_.size() == 0) {
		cur_idx_ = 0;
	}
	return sprites_[cur_idx_];
}

const float Animation::GetTimeInterval(void) const {
	return time_interval_;
}

const bool Animation::GetLoop(void) const {
	return loop_;
}

void Animation::Init(void) {
	cur_idx_ = 0;
}