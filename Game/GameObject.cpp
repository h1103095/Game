#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(IGameScene& scene, Vector2<int> position, Vector2<int> scale)
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
	
}

void GameObject::UpdateComponents(const float& delta_time) {
	for (auto component : components_) {
		component->Update(delta_time);
	}
}

void GameObject::AddComponent(GameComponent* component) {
	components_.push_back(component);
}

void GameObject::OnCollisionEnter(Collision& collision) {
	
}

void GameObject::OnTriggerEnter(Collision& collision) {

}

const GameObjectTag GameObject::GetTag(void) const {
	return tag_;
}

Transform& GameObject::GetTransform(void){
	return transform_;
}

IGameScene& GameObject::GetGameScene(void) {
	return scene_;
}

GameObject* GameObject::Create(IGameScene& scene, Vector2<int> position, Vector2<int> scale) {
	return new GameObject(scene, position, scale);
}
