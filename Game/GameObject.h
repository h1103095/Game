#pragma once
#include <vector>
#include <map>
#include <memory>
#include "resource.h"
#include "IGameObject.h"
#include "Vector2.h"
#include "Transform.h"
#include "GameComponent.h"
#include "GameScene.h"

class Transform;
class GameComponent;
class GameScene;

class GameObject: public IGameObject
{
public:
	virtual ~GameObject(void);
	virtual void Start(void);
	virtual void Update(const float& delta_time);
	virtual void AddComponent(GameComponent* component);
	virtual const GameObjectTag GetTag(void) const;
	virtual GameComponent* GetComponent(ComponentID id);
	virtual Sprite* GetSprite(void);
	virtual Transform& GetTransform(void);
	virtual GameScene& GetGameScene(void);

	GameObject* Create(GameScene& scene, Vector2<int> position, Vector2<int> normal);

protected:
	GameObjectTag tag_;
	GameScene& scene_;
	Transform transform_;
	std::map<ComponentID, GameComponent*> components_;
	GameObject(GameScene& scene, Vector2<int> position=Vector2<int>::Zero(), Vector2<int> scale=Vector2<int>::Normal());
};
