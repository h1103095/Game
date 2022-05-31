#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(GameScene* scene, Vector2 position, Vector2 scale)
	: scene_(scene)
	, transform_(Transform(position, scale))
{
	
}

GameObject::~GameObject(void) {

}

void GameObject::Start(void) {

}

void GameObject::Update(void) {
	for (auto component : components_) {
		component.second->Update();
	}
}

void GameObject::AddComponent(GameComponent* component) {
	components_.insert({ component->GetID(), component });
}

GameObject* GameObject::Create(GameScene* scene, Vector2 position, Vector2 scale) {
	return new GameObject(scene, position, scale);
}

Transform* GameObject::GetTransform(void){
	return &transform_;
}

GameComponent* GameObject::GetComponent(ComponentID id) {
	std::map<ComponentID, GameComponent*>::iterator i = components_.find(id);
	return (i == components_.end()) ? nullptr : i->second;
}


