#pragma once
#include "atltypes.h"
#include "GameObject.h"

class Coin: GameObject
{
public:
	Coin(void);
	Coin(int y);
	Coin(int x, int y);
	~Coin(void);

	void move(void);
	int getX(void);
	CRect getRect(void);

private:
	CRect m_rect;
};

