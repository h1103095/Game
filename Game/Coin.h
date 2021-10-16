#pragma once
#include "atltypes.h"
class Coin
{
public:
	Coin(void);
	~Coin(void);
	int m_nX;
	int m_nY;
	CRect m_rect;
	Coin(int y);
	Coin(int x, int y);
	void move(void);
	CRect getRect(void);
	int getX(void);
};

