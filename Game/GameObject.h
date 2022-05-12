#pragma once
#include <vector>
#include <map>
#include "Vector2.h"
#include "GameComponent.h"
#include "Transform.h"
#include "ComponentID.h"

class Transform;
class GameComponent;

class GameObject
{
public:
	GameObject(void);
	GameObject(int x, int y, int width, int height);
	~GameObject(void);
	void Start(void);
	void Update(void);
	Transform* GetTransform(void);
	template<typename T> T* GetComponent(void);
	/*
	template<typename T> T* GetComponent(void) {
		auto it = components.find(T::GetID());
		if (it != components.end()) {
			return static_cast<T*>(it->second);
		}
		return nullptr;
	}
	*/

protected:
	Transform transform;
	std:: map<ComponentID, GameComponent> components;
};