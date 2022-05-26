#pragma once
#include "Animation.h"
#include "Animator.h"

class PlayerAnimator: public Animator
{
public:
	PlayerAnimator(GameObject* parent);
	~PlayerAnimator(void);
private:
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

