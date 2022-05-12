#include "stdafx.h"
#include "Animator.h"

Animator::Animator(GameObject* parent)
	: GameComponent(parent, ComponentID::ANIMATOR)
{

}

Animator::~Animator(void) {

}

void Animator::ChangeAnimation(Animation* currentAnimation, Animation* nextAnimation) {

}