#pragma once
#include <vector>
#include <map>
#include <memory>
#include "Vector2.h"
#include "Transform.h"
#include "ComponentID.h"
#include "GameComponent.h"

class Transform;
class GameComponent;

class GameObject
{
public:
	GameObject(void);
	GameObject(int x, int y);
	GameObject(int x, int y, int width, int height);
	virtual ~GameObject(void);
	void Start(void);
	void Update(void);
	void AddComponent(GameComponent* component);
	Transform* GetTransform(void);
	GameComponent* GetComponent(ComponentID id);

protected:
	Transform transform_;
	std::map<ComponentID, GameComponent*> components_;
};