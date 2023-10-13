#include "stdafx.h"
#include "GameManager.h"

bool GameManager::instantiated_ = false;

GameManager::GameManager(GameScene& game_scene)
	: GameObject(game_scene)
	, remain_ground_length_(100)
	, last_spawn_time_(GetTickCount64() - 500)
	, time_between_spawn_(7000ULL)
	, cur_ground_height_(600)
	, ground_in_high_pos_(false)
{
	assert(!instantiated_);
	instantiated_ = true;
	CreateStraightGround(kNumInitGrounds, Vector2<int>(100, cur_ground_height_));
	srand(static_cast<unsigned int>(time(NULL)));
}

GameManager::~GameManager(void) {
	instantiated_ = false;
}

void GameManager::Update(const float& delta_time) {
	// Ground 이동
	remain_ground_length_ -= static_cast<int>(delta_time * -kGroundSpeed);
#ifdef DEBUG
	TRACE("Remain ground length: %d\n", remain_ground_length_);
#endif

	// Ground 생성
	if (remain_ground_length_ < 100) {
		GroundPatternID pattern = v_ground_pattern_id[rand() % v_ground_pattern_id.size()];
		CreateGroundPattern(pattern);
		TRACE("Ground pattern id: %d\n", pattern);
	}

	if (GetTickCount64() > last_spawn_time_ + time_between_spawn_) {
		last_spawn_time_ = GetTickCount64();
		// 총알 생성
		
#ifdef DEBUG
		// TRACE("last spawn time: %u\t\t pattern id: %d\n", last_spawn_time_, pattern);
#endif
	}
}

std::shared_ptr<Ground> GameManager::CreateGround(Vector2<int> position) {
	std::shared_ptr<Ground> ground = std::static_pointer_cast<Ground>(scene_.Instantiate(ground_factory_, position));
	ground->SetSpeed(kGroundSpeed);
	return ground;
}

std::shared_ptr<Coin> GameManager::CreateCoin(Vector2<int> position)
{
	std::shared_ptr<Coin> coin = std::static_pointer_cast<Coin>(scene_.Instantiate(coin_factory_, position));
	coin->SetSpeed(kGroundSpeed);
	return coin;
}

void GameManager::CreateStraightGround(int num_ground, Vector2<int> position, int interval) {
	assert(num_ground >= 1);

	std::shared_ptr<Ground> ground;
	int i = 1;

	// 왼쪽 Ground sprite
	ground = CreateGround(position);
	if (num_ground == 1) {
		return;
	} else {
		ground.get()->GetComponent<SpriteRenderer>()->SetSprite(Sprite::GetInstance(IDB_GROUND_LEFT));
	}

	// 가운데 Ground sprite
	for (; i < num_ground - 1; i++) {
		ground = CreateGround(position + Vector2<int>(i * interval, 0));
		ground.get()->GetComponent<SpriteRenderer>()->SetSprite(Sprite::GetInstance(IDB_GROUND_MID));
	}

	// 오른쪽 Ground sprite
	ground = CreateGround(position + Vector2<int>(i * interval, 0));
	ground.get()->GetComponent<SpriteRenderer>()->SetSprite(Sprite::GetInstance(IDB_GROUND_RIGHT));
}

void GameManager::CreateStraightCoin(int num_ground, Vector2<int> position, int interval) {
	assert(num_ground >= 1);

	std::shared_ptr<Coin> coin;

	for (int i=0; i < num_ground; i++) {
		coin = CreateCoin(position + Vector2<int>(i * interval, 0));

	}
}

void GameManager::CreateGroundPattern(GroundPatternID pattern_id) {
	int start_x_pos = WND_X + remain_ground_length_;
	int new_ground_length = 0;

	if (ground_in_high_pos_) {
		if (rand() % 3 == 0) {
			cur_ground_height_ += 300;
			ground_in_high_pos_ = !ground_in_high_pos_;
		}
	}

	switch (pattern_id) {
	case GroundPatternID::STRAIGHT:
		//   ㅇㅇㅇㅇㅇㅇㅇㅇㅇ
		// ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ
		CreateStraightGround(11, Vector2<int>(start_x_pos, cur_ground_height_));
		CreateStraightCoin(9, Vector2<int>(start_x_pos + 100, cur_ground_height_ - 100));
		new_ground_length = 1200;
		break;
	case GroundPatternID::HOLE:
		//           ㅇ
		//         ㅇ  ㅇ
		//        ㅇ    ㅇ
		// ㅁㅁㅁㅁ      ㅁㅁㅁㅁ
		CreateStraightGround(4, Vector2<int>(start_x_pos, cur_ground_height_));
		CreateStraightGround(4, Vector2<int>(start_x_pos + 700, cur_ground_height_));
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 350, cur_ground_height_ - 100), 300);
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 400, cur_ground_height_ - 200), 200);
		CreateStraightCoin(1, Vector2<int>(start_x_pos + 500, cur_ground_height_ - 300));
		new_ground_length = 1100;
		break;
	case GroundPatternID::HOLES_EASY1:
		//        ㅇㅇ  ㅇㅇ
		//        
		// ㅁㅁㅁㅁ   ㅁ   ㅁㅁㅁㅁ
		CreateStraightGround(3, Vector2<int>(start_x_pos, cur_ground_height_));
		CreateStraightGround(1, Vector2<int>(start_x_pos + 550, cur_ground_height_));
		CreateStraightGround(3, Vector2<int>(start_x_pos + 800, cur_ground_height_));
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 400, cur_ground_height_ - 200), 125);
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 650, cur_ground_height_ - 200), 125);
		new_ground_length = 1100;
		break;
	case GroundPatternID::HOLES_EASY2:
		//   ㅇㅇ  ㅇㅇ  ㅇㅇ
		//   
		// ㅁ    ㅁ    ㅁ    ㅁ
		CreateStraightGround(4, Vector2<int>(start_x_pos, cur_ground_height_), 300);
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 100, cur_ground_height_ - 200));
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 400, cur_ground_height_ - 200));
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 700, cur_ground_height_ - 200));
		new_ground_length = 1300;
		break;
	case GroundPatternID::HOLES_HARD1:
		//
		// ㅁ        ㅁ        ㅁ  
		CreateStraightGround(1, Vector2<int>(start_x_pos, cur_ground_height_));
		CreateStraightGround(1, Vector2<int>(start_x_pos + 500, cur_ground_height_));
		CreateStraightGround(1, Vector2<int>(start_x_pos + 1000, cur_ground_height_));
		new_ground_length = 1100;
		break;
	case GroundPatternID::HOLES_HARD2:
		//
		//
		CreateStraightGround(1, Vector2<int>(start_x_pos, cur_ground_height_));
		CreateStraightGround(1, Vector2<int>(start_x_pos + 400, cur_ground_height_ - 100));
		CreateStraightGround(1, Vector2<int>(start_x_pos + 800, cur_ground_height_ - 200));
		CreateStraightGround(1, Vector2<int>(start_x_pos + 1000, cur_ground_height_));
		new_ground_length = 1100;
		break;
	case GroundPatternID::STAIRS:
		if (!ground_in_high_pos_) {
			//                 ㅁㅁ
			//         ㅁㅁ
			// ㅁㅁ
			CreateStraightGround(2, Vector2<int>(start_x_pos, cur_ground_height_));
			CreateStraightGround(2, Vector2<int>(start_x_pos + 400, cur_ground_height_ - 150));
			CreateStraightGround(2, Vector2<int>(start_x_pos + 800, cur_ground_height_ - 300));
			cur_ground_height_ -= 300;
			new_ground_length = 1000;
		}
		else {
			// ㅁㅁ
			//         
			//             ㅁㅁ
			CreateStraightGround(2, Vector2<int>(start_x_pos, cur_ground_height_));
			CreateStraightGround(2, Vector2<int>(start_x_pos + 600, cur_ground_height_ + 300));
			cur_ground_height_ += 300;
			new_ground_length = 800;
		}
		ground_in_high_pos_ = !ground_in_high_pos_;
		break;
	}
	remain_ground_length_ += new_ground_length;

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
