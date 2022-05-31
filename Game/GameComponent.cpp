#include "stdafx.h"
#include "GameComponent.h"

GameComponent::GameComponent(IGameObject* parent, ComponentID id) 
	:parent_(parent), id_(id)
{
	parent->AddComponent(this);
}

GameComponent::~GameComponent(void) {

}

ComponentID GameComponent::GetID(void) const {
	return id_;
}

void GameComponent::Update(void) {

}