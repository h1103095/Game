#include "stdafx.h"
#include "Animation.h"


Animation::Animation(GameObject* parent)
	: GameComponent(parent, ComponentID::ANIMATION)
{

}

Animation::~Animation(void) {

}

void Animation::AddSprite(Sprite* sprite) {
	sprites_.push_back(sprite);
}