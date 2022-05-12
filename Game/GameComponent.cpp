#include "stdafx.h"
#include "GameComponent.h"

GameComponent::GameComponent(GameObject* parent, ComponentID id) {
	this->parent = parent, this->id = id;
}

GameComponent::~GameComponent(void) {

}

ComponentID GameComponent::GetID(void) {
	return id;
}