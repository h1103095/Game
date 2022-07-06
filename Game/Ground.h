#pragma once
#include <vector>
#include <cassert>
#include "GameObject.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "Sprite.h"


class Ground: public GameObject
{
public:
	Ground(GameScene& scene, Vector2<int> position, Vector2<int> scale);
	virtual ~Ground(void);
	virtual void Update(const float& delta_time);

private:
	SpriteRenderer sprite_renderer_;
	Collider collider_;
	const float kXSpeed = -200.0f;
	//static Sprite kGroundSingleSprite_;
};