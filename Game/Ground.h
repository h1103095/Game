#pragma once
#include "atltypes.h"
#include "GameObject.h"
#include "Collider.h"
#include "Rigidbody.h"

class Rigidbody;

class Ground: GameObject
{
public:
	Ground(int x, int y, int width, int height);
	~Ground(void);

private:
	Collider collider;
	Rigidbody rigidbody;
};

