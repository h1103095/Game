#include "StdAfx.h"
#include "Ground.h"


Ground::Ground(int x, int y, int bitmapID)
	: GameObject(x, y)
	, sprite_(this, bitmapID, LayerID::GROUND)
	, rigidbody_(this, false)
	, collider_(this)
{
	AddComponent(&sprite_);
}

Ground::Ground(int x, int y, int width, int height, int bitmapID)
	: GameObject(x, y, width, height)
	, sprite_(this, bitmapID, LayerID::GROUND)
	, rigidbody_(this, false)
	, collider_(this)
{
	AddComponent(&sprite_);
}

Ground::~Ground(void)
{
	
}

std::vector<Ground*> Ground::CreateGround(int x, int y, int num)
{
	assert(num > 0);

	std::vector<Ground*> return_vec;
	if (num == 1) {
		return_vec.push_back(new Ground(x, y, IDB_GROUND_SINGLE));
	}
	else {
		Ground* first_ground = new Ground(x, y, IDB_GROUND_LEFT);
		return_vec.push_back(first_ground);
		int width = static_cast<Sprite*>(first_ground->GetComponent(ComponentID::SPRITE))->GetTransform()->GetScale()->get_int_y();
		for (int i = 1; i < num - 1; i++) {
			return_vec.push_back(new Ground(x + i * width, y, IDB_GROUND_MID));
		}
		return_vec.push_back(new Ground(x + (num - 1) * width, y, IDB_GROUND_RIGHT));
	}

	return return_vec;
}
