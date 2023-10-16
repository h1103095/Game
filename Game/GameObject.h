#pragma once
#include <vector>
#include <map>
#include <memory>
#include "resource.h"
#include "IGameObject.h"
#include "Vector2.h"
#include "Transform.h"
#include "GameComponent.h"
#include "IGameScene.h"
#include "Collision.h"

class Transform;
class GameComponent;

class GameObject: public IGameObject
{
public:
	virtual ~GameObject(void);
	virtual void Start(void);
	virtual void Update(const float& delta_time);
	virtual void OnCollisionEnter(Collision& collision);
	virtual void OnTriggerEnter(Collision& collision);
	
	void AddComponent(GameComponent* component);
	void UpdateComponents(const float& delta_time);
	const GameObjectTag GetTag(void) const;
	Transform& GetTransform(void);
	IGameScene& GetGameScene(void);

	GameObject* Create(IGameScene& scene, Vector2<int> position, Vector2<int> normal);
protected:
	GameObjectTag tag_;
	IGameScene& scene_;
	Transform transform_;
	GameObject(IGameScene& scene, Vector2<int> position=Vector2<int>::Zero(), Vector2<int> scale=Vector2<int>::Normal());
};
