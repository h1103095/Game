#pragma once
#include "atltypes.h"
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet(CPoint playerPoint, CPoint dest);
	virtual ~Bullet(void);
	void Move(void);

private:
	CPoint destination_;
	const float kSpeed = 17;
	double distance_;
	double degree_;
};

