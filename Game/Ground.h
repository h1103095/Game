#pragma once
#include "atltypes.h"
class Ground
{
public:
	Ground(void);
	Ground(int);
	~Ground(void);
	CRect m_rect;
	void move(void);
	CRect getRect(void);
	int m_nX;
	int getX(void);
	bool isCollider(CRect);
	bool m_bCollided;
};

