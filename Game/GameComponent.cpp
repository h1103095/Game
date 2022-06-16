#include "stdafx.h"
#include "GameComponent.h"

GameComponent::GameComponent(IGameObject& parent, ComponentID id) 
	:parent_(parent), kComponentID_(id)
{
	parent.AddComponent(this);
}

GameComponent::~GameComponent(void) {

}

ComponentID GameComponent::GetID(void) const {
	return kComponentID_;
}

void GameComponent::Update(const float& delta_time) {

}