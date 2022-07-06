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
	//static std::map<PlayerStateID, std::vector<UINT>> bitmap_ids_;
	/*
	Animation walkAnimation;
	Animation flyAnimation;
	Animation attackAnimation;
	Animation dieAnimation;
	bool isWalk;
	bool isFly;
	bool isAttack;
	bool isDead;
	*/
};


// ���⿡ animation ���� ��ü�� ���� update�� �ش� �ִϸ��̼��� ����
// spriteó�� ���⿡ static���� �ִϸ��̼ǵ��� ����� ����