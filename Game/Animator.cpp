#include "stdafx.h"
#include "Animator.h"

Animator::Animator(IGameObject& parent, SpriteRenderer& sprite_renderer)
	: GameComponent(parent)
	, sprite_renderer_(sprite_renderer)
	, cur_ani_time_interval_(10.0f)
	, cur_ani_loop_(false)
{
	
}

Animator::~Animator(void) {

}


void Animator::NextSprite(void) {
	cur_sprite_ = cur_animation_->GetNextSprite();
}

void Animator::SetAnimation(std::shared_ptr<Animation> next_animation) {
	cur_animation_ = next_animation;
	cur_animation_->Init();
	cur_ani_time_interval_ = cur_animation_->GetTimeInterval();
	cur_ani_loop_ = cur_animation_->GetLoop();
	cur_sprite_ = cur_animation_->GetNextSprite();
}

void Animator::Update(const float& delta_time) {
	static float time = 0;
	time += delta_time;

	if (time >= cur_ani_time_interval_) {
		time -= cur_ani_time_interval_;
		NextSprite();
		sprite_renderer_.SetSprite(cur_sprite_);
	}
}