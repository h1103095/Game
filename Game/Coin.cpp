#include "StdAfx.h"
#include "Coin.h"


Coin::Coin(void) {
	position = Vector2(0, 0);
	scale = Vector2(100, 100);
}


Coin::~Coin(void)
{
}


Coin::Coin(int y) {
	position = Vector2(0, y);
	m_rect = CRect(position.get_x(), position.get_y(), position.get_x() + scale.get_x(), position.get_y() + scale.get_y());
}

Coin::Coin(int x, int y)
{
	position = Vector2(x, y);
	m_rect = CRect(position.get_x(), position.get_y(), position.get_x() + scale.get_x(), position.get_y() + scale.get_y());
}


void Coin::move(void)
{
	position.x -= 4;
	m_rect = CRect(position.get_x(), position.get_y(), position.get_x() + scale.get_x(), position.get_y() + scale.get_y());
}


CRect Coin::getRect(void)
{
	return m_rect;
}


int Coin::getX(void)
{
	return position.get_x();
}
