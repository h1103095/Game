#pragma once
#include "MainFrm.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Rigidbody.h"

class BackGround: public GameObject
{
public:
	BackGround(int x, int y);
	BackGround(int x, int y, int width, int height);
	virtual ~BackGround(void);

private:
	Sprite sprite_;
	Rigidbody rigidbody_;
};

