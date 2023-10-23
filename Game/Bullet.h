#pragma once
#include "atltypes.h"
#include "GameObject.h"
#include "Collider.h"
#include "SpriteRenderer.h"
#include "Rigidbody.h"
#include "Game.h"


class Bullet: public GameObject
{
public:
	Bullet(IGameScene& game_scene, Vector2<int> position, Vector2<int> scale);
	virtual ~Bullet(void);
	virtual void Update(const float& delta_time);
	virtual void OnColliderEnter(Collision& collision);

private:
	SpriteRenderer sprite_renderer_;
	Collider collider_;
	Rigidbody rigidbody_;
};