#pragma once
#include <memory>
#include "Vector2.h"
#include "GameObjectTag.h"
#include "InputManager.h"

class GameComponent;
class IGameScene;
class Transform;
class Collider;
class Collision;

class IGameObject : public std::enable_shared_from_this<IGameObject>
{
public:
	virtual ~IGameObject() {};
	virtual void Start(void) = 0;
	virtual void Update(const float& delta_time) = 0;
	virtual void UpdateComponents(const float& delta_time) = 0;
	virtual void AddComponent(GameComponent* component) = 0;
	virtual void OnCollisionEnter(Collision& collision) = 0;
	virtual void OnTriggerEnter(Collision& collision) = 0;
	virtual const GameObjectTag GetTag(void) const = 0;
	virtual Transform& GetTransform(void) = 0;
	virtual IGameScene& GetGameScene(void) = 0;

	template<typename T>
	T* GetComponent() {
		for(GameComponent* component: components_) {
			T* casted_component = dynamic_cast<T*>(component);
			if (casted_component != nullptr) {
				return casted_component;
			}
		}
		return nullptr;
	}

protected:
	std::vector<GameComponent*> components_;
};