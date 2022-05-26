#pragma once
#include "GameObject.h"
#include "GameComponent.h"
#include "Animation.h"

class GameObject;
class Animation;

class Animator: public GameComponent
{
public:
	Animator(GameObject* parent);
	~Animator(void);
	void ChangeAnimation(Animation* current_animation, Animation* next_animation);
private:

};
