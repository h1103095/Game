#pragma once
#include "GameObject.h"
#include "GameComponent.h"
#include "Animation.h"

class GameObject;
class Animation;

class Animator: GameComponent
{
public:
	Animator(GameObject* parent);
	~Animator(void);
	void ChangeAnimation(Animation* currentAnimation, Animation* nextAnimation);
private:

};
