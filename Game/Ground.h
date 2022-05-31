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
	Ground(GameScene* scene, Vector2 position, Vector2 scale);
	virtual ~Ground(void);
	void SetBitmap(int bitmap_id);

private:
	Sprite sprite_;
	Collider collider_;
	Rigidbody rigidbody_;
};

