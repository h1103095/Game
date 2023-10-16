#pragma once
#include "Animator.h"
#include "PlayerWalkingAnimation.h"
#include "PlayerJumpingAnimation.h"
#include "PlayerStateID.h"

class PlayerWalkingAnimation;
class PlayerJumpingAnimation;
class PlayerAttackingAnimation;
class PlayerDyingAnimation;


class PlayerAnimator: public Animator
{
public:
	PlayerAnimator(IGameObject& parent, SpriteRenderer& sprite_renderer);
	virtual ~PlayerAnimator(void);
	void SetAnimationByPlayerStateID(PlayerStateID id);
private:
	static std::map<PlayerStateID, std::shared_ptr<Animation>> animations_;
};
