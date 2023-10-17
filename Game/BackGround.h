#pragma once
#include "Game.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Rigidbody.h"

class BackGround: public GameObject
{
public:
	BackGround(IGameScene& scene, Vector2<int> position, Vector2<int> scale);
	virtual ~BackGround(void);
	virtual void Update(const float& delta_time);

private:
	SpriteRenderer sprite_renderer_;
	Rigidbody rigidbody_;
};
