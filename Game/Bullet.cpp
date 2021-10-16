#include "StdAfx.h"
#include "Bullet.h"
#include <math.h>


Bullet::Bullet(void)
	: m_pDistination(0)
	, m_pPoint(0)
	, m_dDistance(0)
	, m_dDegree(0)
{
}

Bullet::~Bullet(void)
{
}

Bullet::Bullet(CPoint playerPoint, CPoint p)
{
	m_pPoint = playerPoint;		// ���� ��ġ
	m_pDistination = p;			// ������
	m_dDistance = sqrt(pow((double)(m_pDistination.x - m_pPoint.x), 2) + pow((double)(m_pDistination.y - m_pPoint.y), 2));
	// �Ÿ� ���
	m_dDegree = atan2f((float)(m_pDistination.y - m_pPoint.y), (float)(m_pDistination.x - m_pPoint.x));
	// ���� ���
}

void Bullet::Move(void)
{
	m_pPoint.SetPoint(m_pPoint.x + (17 * cos(m_dDegree)), m_pPoint.y + (17 * sin(m_dDegree)));
	// �Ѿ� �̵�
}


CPoint Bullet::getPoint(void)
{
	return m_pPoint;
}
