#include "stdafx.h"
#include "Animator.h"

Animator::Animator(IGameObject& parent)
	: GameComponent(parent, ComponentID::ANIMATOR)
{

}

Animator::~Animator(void) {

}

void Animator::ChangeAnimation(Animation* currentAnimation, Animation* nextAnimation) {

}