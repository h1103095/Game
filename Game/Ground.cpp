#include "StdAfx.h"
#include "Ground.h"


Ground::Ground(int x, int y, int width, int height)
	: GameObject(x, y, width, height), rigidbody(this, false), collider(this)
{

}

Ground::~Ground(void)
{
	
}
