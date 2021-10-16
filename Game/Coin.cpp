#include "StdAfx.h"
#include "Coin.h"


Coin::Coin(void)
	: m_nX(0)
	, m_nY(0)
{

}


Coin::~Coin(void)
{
}


Coin::Coin(int y)
{
	m_nX = 1200;
	m_nY = y;
	m_rect = CRect(m_nX, m_nY, m_nX+100, m_nY+100);
}

Coin::Coin(int x, int y)
{
	m_nX = x;
	m_nY = y;
	m_rect = CRect(m_nX, m_nY, m_nX+100, m_nY+100);
}


void Coin::move(void)
{
	m_nX -= 4;
	m_rect.SetRect(m_nX, m_nY, m_nX+100, m_nY+100);
}


CRect Coin::getRect(void)
{
	return m_rect;
}


int Coin::getX(void)
{
	return m_nX;
}
