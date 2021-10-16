#include "StdAfx.h"
#include "Enemy.h"
#include <random>


Enemy::Enemy(void)
	: m_nX(0)
	, m_nY(0)
{
	m_nX = 1200;
	m_nY = (int)rand() % 400 + 200;
	m_rect = CRect(m_nX, m_nY, m_nX+100, m_nY + 97); 
}


Enemy::~Enemy(void)
{
	
}


CRect Enemy::getRect(void)
{
	return m_rect;
}


void Enemy::move(void)
{
	m_nX -= 10;
	m_rect.SetRect(m_nX, m_nY, m_nX+100, m_nY+97);
}


int Enemy::getX(void)
{
	return m_nX;
}
