#pragma once
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Rigidbody.h"

class BackGround: public GameObject
{
public:
	BackGround(GameScene& scene, Vector2<int> position, Vector2<int> scale);
	virtual ~BackGround(void);
	virtual void Update(const float& delta_time);

private:
	SpriteRenderer sprite_renderer_;
	const int kWidth;
	const float kXSpeed = -200.0f;
};
