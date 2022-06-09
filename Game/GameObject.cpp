#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(GameScene& scene, Vector2<int> position, Vector2<int> scale)
	: tag_(GameObjectTag::DEFAULT)
	, scene_(scene)
	, transform_(Transform(position, scale))
{
	
}

GameObject::~GameObject(void) {

}

void GameObject::Start(void) {

}

void GameObject::Update(const float& delta_time) {
	for (auto component : components_) {
		component.second->Update(delta_time);
	}
}

void GameObject::AddComponent(GameComponent* component) {
	components_.insert({ component->GetID(), component });
}

const GameObjectTag GameObject::GetTag(void) const {
	return tag_;
}

GameComponent* GameObject::GetComponent(ComponentID id) {
	std::map<ComponentID, GameComponent*>::iterator i = components_.find(id);
	return (i == components_.end()) ? nullptr : i->second;
}

Sprite* GameObject::GetSprite(void) {
	return static_cast<Sprite*>(GetComponent(ComponentID::SPRITE));
}

Transform& GameObject::GetTransform(void){
	return transform_;
}

GameScene& GameObject::GetGameScene(void) {
	return scene_;
}

GameObject* GameObject::Create(GameScene& scene, Vector2<int> position, Vector2<int> scale) {
	return new GameObject(scene, position, scale);
}
