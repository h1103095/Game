#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Rigidbody.h"

class BackGround: public GameObject
{
public:
	BackGround(GameScene& scene, Vector2<int> position, Vector2<int> scale);
	virtual ~BackGround(void);
	virtual void Update(const float& delta_time);

private:
	Sprite sprite_;
	Rigidbody rigidbody_;
	const int kWidth;
	const float kXSpeed = -100.0f;
};
