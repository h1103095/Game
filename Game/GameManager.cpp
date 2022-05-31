#include "stdafx.h"
#include "GameManager.h"


GameManager::GameManager(GameScene* game_scene, Vector2 position, Vector2 scale) 
	: GameObject(game_scene, position, scale)
{
	assert(!instantiated_);
	instantiated_ = true;
}

GameManager::~GameManager(void) {
	instantiated_ = false;
}

void GameManager::GenerateGround(void) {
	/*
	static DWORD dwTime = GetTickCount();
	DWORD dwCurTime = GetTickCount();
	static DWORD dwTime2 = GetTickCount();
	DWORD dwCurTime2 = GetTickCount();

	if (dwTime < dwCurTime)
	{
		if (m_bRaceMode == JUMP_MODE)
		{
			int nJump = 0, nDistance = 0;
			int nBlock = rand() % 5;

			if (rand() % 5 == 0 || rand() % 5 == 4) nJump = TWO_BLOCK;
			else nJump = ONE_BLOCK;

			for (int i = 0; i <= nBlock; i++)
			{
				m_vGrounds.push_back(Ground(1200 + 100 * i));
				if (nBlock < 4)
					m_vCoins.push_back(Coin(1200 + 100 * i, 500));
				else if (nBlock == 4)
				{
					m_vCoins.push_back(Coin(1200, 500));
					m_vCoins.push_back(Coin(1300, 400));
					m_vCoins.push_back(Coin(1400, 300));
					m_vCoins.push_back(Coin(1500, 400));
					m_vCoins.push_back(Coin(1600, 500));
				}
			}

			nDistance = (nBlock + 1) * 400 + nJump;

			dwTime = dwCurTime + nDistance;

			if (nJump == TWO_BLOCK)
			{
				m_nCoinY = 50;
			}
			else if (nJump == ONE_BLOCK)
			{
				m_nCoinY = 300;
			}

			int n;
			if (nJump == ONE_BLOCK)
				n = 100;
			else if (nJump == TWO_BLOCK)
				n = 200;
			m_nCoinX = 1200 + 100 * (nBlock + 1) + n;

			m_vCoins.push_back(Coin(m_nCoinX, m_nCoinY));
		}
		else if (m_bRaceMode == RUN_MODE)
		{
			m_vGrounds.push_back(Ground(1200));
			dwTime = dwCurTime + 380;

			if (m_nTransMode <= 8)
			{
				int n = rand() % 5;
				if (n == 0)
					m_nCoinY = 50;
				else if (n == 4)
					m_nCoinY = 300;
				else
					m_nCoinY = 400;
			}
			else
			{
				m_nCoinY = 500;
			}
			m_vCoins.push_back(Coin(m_nCoinY));
		}
		TransMode();
	}

	if (dwTime2 < dwCurTime2)
	{
		dwTime2 = dwCurTime2 + 1000;
		m_vEnemys.push_back(Enemy());
	}

	m_nMapMove++;
	//	m_nScore++;
	if (nIDEvent == 0)
	{
		if (m_nMapMove >= 2400)
			m_nMapMove = 0;
	}
	*/
}