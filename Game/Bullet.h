#pragma once
#include "atltypes.h"
class Bullet
{
public:
	Bullet(void);
	Bullet(CPoint, CPoint);
	~Bullet(void);
	CPoint m_pDistination;
	CPoint m_pPoint;
	void Move(void);
	CPoint getPoint(void);
	double m_dDistance;
	double m_dDegree;
};

