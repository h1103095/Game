#include "stdafx.h"
#include "Animation.h"


Animation::Animation(IGameObject* parent)
	: GameComponent(parent, ComponentID::ANIMATION)
{

}

Animation::~Animation(void) {

}

void Animation::AddSprite(Sprite* sprite) {
	sprites_.push_back(sprite);
}