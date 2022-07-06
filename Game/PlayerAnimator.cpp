#include "stdafx.h"
#include "PlayerAnimator.h"


std::map<PlayerStateID, std::shared_ptr<Animation>> PlayerAnimator::animations_;

PlayerAnimator::PlayerAnimator(IGameObject& parent, SpriteRenderer& sprite_renderer)
	: Animator(parent, sprite_renderer)
{
	animations_.insert({ PlayerStateID::WALKING,
		std::static_pointer_cast<Animation>(std::make_shared<PlayerWalkingAnimation>(true, 0.1f)) });
	animations_.insert({ PlayerStateID::JUMPING,
		std::static_pointer_cast<Animation>(std::make_shared<PlayerJumpingAnimation>(true, 0.1f)) });
	SetAnimationByPlayerStateID(PlayerStateID::WALKING);
}

PlayerAnimator::~PlayerAnimator(void) {

}


void PlayerAnimator::SetAnimationByPlayerStateID(PlayerStateID id) {
	SetAnimation(animations_[id]);
}