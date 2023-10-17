#pragma once
#include "atltypes.h"
#include "GameObject.h"
#include "Collider.h"
#include "SpriteRenderer.h"
#include "Rigidbody.h"

class Bullet : public GameObject
{
public:
	Bullet(IGameScene& game_scene, Vector2<int> position, Vector2<int> scale);
	virtual ~Bullet(void);
	virtual void Update(void);
	virtual void OnColliderEnter(Collision& collision);
	void Move(void);
	void SetDestination(Vector2<int> destination);

private:
	Vector2<int> destination_;
	SpriteRenderer sprite_renderer_;
	Collider collider_;
	Rigidbody rigidbody_;
	double degree_;
	const float kSpeed = 17;
};