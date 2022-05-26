#include "stdafx.h"
#include "GameComponent.h"

GameComponent::GameComponent(GameObject* pParent, ComponentID id) 
	:parent_(pParent), id_(id)
{
}

GameComponent::~GameComponent(void) {

}

ComponentID GameComponent::GetID(void) const {
	return id_;
}