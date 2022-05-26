#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(void)
	: transform_(Transform(Vector2(0, 0), Vector2(1, 1)))
{
	
}

GameObject::GameObject(int x, int y)
	: transform_(Transform(Vector2(x, y), Vector2(1, 1)))
{

}

GameObject::GameObject(int x, int y, int width, int height)
	: transform_(Transform(Vector2(x, y), Vector2(width, height)))
{
	
}

GameObject::~GameObject(void) {

}

void GameObject::Start(void) {

}

void GameObject::Update(void) {

}

void GameObject::AddComponent(GameComponent* component) {
	components_.insert({ component->GetID(), component });
}

Transform* GameObject::GetTransform(void){
	return &transform_;
}

GameComponent* GameObject::GetComponent(ComponentID id) {
	std::map<ComponentID, GameComponent*>::iterator i = components_.find(id);
	return i == components_.end() ? nullptr : i->second;
}


