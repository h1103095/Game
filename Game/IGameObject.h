#pragma once
#include <memory>
#include "Vector2.h"
#include "ComponentID.h"
#include "GameObjectTag.h"
#include "InputManager.h"

class GameComponent;
class GameScene;
class Transform;
class Sprite;
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
	virtual void OnCollisionEnter(const Collision& collision) = 0;
	virtual void OnTriggerEnter(const Collision& collision) = 0;
	virtual const GameObjectTag GetTag(void) const = 0;
	virtual GameComponent* GetComponent(ComponentID id) = 0;
	virtual Sprite* GetSprite(void) = 0;
	virtual Transform& GetTransform(void) = 0;
	virtual GameScene& GetGameScene(void) = 0;
};
