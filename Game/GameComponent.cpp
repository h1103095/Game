#include "stdafx.h"
#include "GameComponent.h"

GameComponent::GameComponent(IGameObject& parent) 
	:parent_(parent)
{
	parent.AddComponent(this);
}

GameComponent::~GameComponent(void) {

}

void GameComponent::Update(const float& delta_time) {

}