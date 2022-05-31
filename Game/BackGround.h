#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Rigidbody.h"

class BackGround: public GameObject
{
public:
	BackGround(GameScene* scene, Vector2 position, Vector2 scale);
	virtual ~BackGround(void);
	virtual void Update(void);

private:
	Sprite sprite_;
	Rigidbody rigidbody_;
	const float kWidth;
	const float kXSpeed = -100.0;
	
};
