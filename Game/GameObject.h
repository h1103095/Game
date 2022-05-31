#pragma once
#include <vector>
#include <map>
#include <memory>
#include "resource.h"
#include "IGameObject.h"
#include "Vector2.h"
#include "Transform.h"
#include "ComponentID.h"
#include "GameComponent.h"
#include "GameScene.h"

class Transform;
class GameComponent;

class GameObject: public IGameObject
{
public:
	virtual ~GameObject(void);
	virtual void Start(void);
	virtual void Update(void);
	virtual void AddComponent(GameComponent* component);
	virtual GameObject* Create(GameScene* scene, Vector2 position, Vector2 normal);
	virtual Transform* GetTransform(void);
	GameComponent* GetComponent(ComponentID id);

protected:
	GameScene* scene_;
	Transform transform_;
	std::map<ComponentID, GameComponent*> components_;
	GameObject(GameScene* scene, Vector2 position, Vector2 scale);
};