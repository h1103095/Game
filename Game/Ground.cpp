#include "StdAfx.h"
#include "Ground.h"


Ground::Ground(void)
	: m_nX(0)
	, m_bCollided(false)
{
	m_nX = 1300;
	m_rect = CRect(m_nX, 600, m_nX+100, 700); 
}

Ground::Ground(int x)
{
	m_bCollided = false;
	m_nX = x;
	m_rect = CRect(m_nX, 600, m_nX+100, 700); 
}


Ground::~Ground(void)
{
	
}

// ??? ???


void Ground::move(void)
{
	m_nX -= 4;
	m_rect.SetRect(m_nX, 600, m_nX+100, 700);
}


CRect Ground::getRect(void)
{
	return m_rect;
}

int Ground::getX(void)
{
	return m_nX;
}


bool Ground::isCollider(CRect pRect)
{
	CRect rct;
	if(pRect.right >= m_rect.left && pRect.left <= m_rect.right &&
			pRect.bottom <= m_rect.top && pRect.bottom >= m_rect.top - 20)
	//if(IntersectRect(&rct, pRect, m_rect))
	{
		m_bCollided = true;
		return true;
	}
	return false;
}
