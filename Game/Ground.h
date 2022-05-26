#pragma once
#include <vector>
#include <cassert>
#include "MainFrm.h"
#include "atltypes.h"
#include "GameObject.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "Sprite.h"

class Rigidbody;

class Ground: public GameObject
{
public:
	Ground(int x, int y, int bitmapID);
	Ground(int x, int y, int width, int height, int bitmapID);
	virtual ~Ground(void);
	static std::vector<Ground*> CreateGround(int x, int y, int num);

private:
	Sprite sprite_;
	Collider collider_;
	Rigidbody rigidbody_;
};

