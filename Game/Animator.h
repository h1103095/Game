#pragma once
#include "IGameObject.h"
#include "GameComponent.h"
#include "Animation.h"

class Animator: public GameComponent
{
public:
	Animator(IGameObject& parent);
	~Animator(void);
	void ChangeAnimation(Animation* current_animation, Animation* next_animation);
private:

};
