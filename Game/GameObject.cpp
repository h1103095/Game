#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(void) {
	transform = Transform(Vector2(0, 0), Vector2(1, 1));
}

GameObject::GameObject(int x, int y, int width, int height) {
	transform = Transform(Vector2(x, y), Vector2(width, height));
}

GameObject::~GameObject(void) {

}

void GameObject::Start(void) {

}

void GameObject::Update(void) {

}

Transform* GameObject::GetTransform(void) {
	return &transform;
}

template<typename T> T* GameObject::GetComponent(void) {
	for (int i = 0; i < components.size(); i++) {
		if (typeid(T).name().compare(typeid(components[i]).name()) == 0) {
			return static_cast<T*>(&components[i]);
			//return &components[i];
		}
	}
	return nullptr;
}
