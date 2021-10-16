#pragma once
#include "atltypes.h"
class Enemy
{
public:
	Enemy(void);
	~Enemy(void);
	int m_nX;
	CRect m_rect;
	CRect getRect(void);
	int m_nY;
	void move(void);
	int getX(void);
};

