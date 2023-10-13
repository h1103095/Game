#include "stdafx.h"
#include "GameManager.h"

bool GameManager::instantiated_ = false;

GameManager::GameManager(GameScene& game_scene)
	: GameObject(game_scene)
	, remain_ground_length_(200)
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
	std::shared_ptr<Ground> ground = std::static_pointer_cast<Ground>(scene_.Instantiate(ground_factory_, position, kGroundScale));
	ground->SetSpeed(kGroundSpeed);
	return ground;
}

std::shared_ptr<Coin> GameManager::CreateCoin(Vector2<int> position)
{
	std::shared_ptr<Coin> coin = std::static_pointer_cast<Coin>(scene_.Instantiate(coin_factory_, position, kCoinScale));
	coin->SetSpeed(kGroundSpeed);
	return coin;
}

void GameManager::CreateStraightGround(int num_ground, Vector2<int> position, int interval) {
	assert(num_ground >= 1);

	std::shared_ptr<Ground> ground;

	if (num_ground == 1) {
		ground = CreateGround(position);
	} else {
		if (interval <= kGroundScale.x) {
			// 왼쪽 Ground sprite
			ground = CreateGround(position);
			ground.get()->GetComponent<SpriteRenderer>()->SetSprite(Sprite::GetInstance(IDB_GROUND_LEFT));

			// 가운데 Ground sprite
			int i = 1;
			for (; i < num_ground - 1; i++) {
				ground = CreateGround(position + Vector2<int>(i * interval, 0));
				ground.get()->GetComponent<SpriteRenderer>()->SetSprite(Sprite::GetInstance(IDB_GROUND_MID));
			}

			// 오른쪽 Ground sprite
			ground = CreateGround(position + Vector2<int>(i * interval, 0));
			ground.get()->GetComponent<SpriteRenderer>()->SetSprite(Sprite::GetInstance(IDB_GROUND_RIGHT));
		}
		else {
			for (int i=0; i < num_ground; i++) {
				ground = CreateGround(position + Vector2<int>(i * interval, 0));
			}
		}
	}

	
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
			cur_ground_height_ += 200;
			ground_in_high_pos_ = !ground_in_high_pos_;
		}
	}

	switch (pattern_id) {
	case GroundPatternID::STRAIGHT:
		//  ㅇ  ㅇ  ㅇ  ㅇ  ㅇ
		//  ㅇ  ㅇ  ㅇ  ㅇ  ㅇ
		// ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ
		CreateStraightGround(11, Vector2<int>(start_x_pos, cur_ground_height_));
		CreateStraightCoin(5, Vector2<int>(start_x_pos + 100, cur_ground_height_ - 250), 200);
		CreateStraightCoin(5, Vector2<int>(start_x_pos + 100, cur_ground_height_ - 150), 200);
		new_ground_length = 1300;
		break;
	case GroundPatternID::HOLE:
		//           ㅇ
		//         ㅇ  ㅇ
		//        ㅇ    ㅇ
		// ㅁㅁㅁㅁ      ㅁㅁㅁㅁ
		CreateStraightGround(4, Vector2<int>(start_x_pos, cur_ground_height_));
		CreateStraightGround(4, Vector2<int>(start_x_pos + 700, cur_ground_height_));
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 350, cur_ground_height_ - 150), 300);
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 400, cur_ground_height_ - 250), 200);
		CreateStraightCoin(1, Vector2<int>(start_x_pos + 500, cur_ground_height_ - 300));
		new_ground_length = 1300;
		break;
	case GroundPatternID::HOLES_EASY1:
		//      ㅇㅇ  ㅇㅇ
		//        
		// ㅁㅁㅁ   ㅁ   ㅁㅁㅁ
		CreateStraightGround(3, Vector2<int>(start_x_pos, cur_ground_height_));
		CreateStraightGround(1, Vector2<int>(start_x_pos + 550, cur_ground_height_));
		CreateStraightGround(3, Vector2<int>(start_x_pos + 900, cur_ground_height_));
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 325, cur_ground_height_ - 250));
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 675, cur_ground_height_ - 250));
		new_ground_length = 1500;
		break;
	case GroundPatternID::HOLES_EASY2:
		//     ㅇㅇ    ㅇㅇ    ㅇㅇ
		//   
		// ㅁㅁ    ㅁㅁ    ㅁㅁ    ㅁㅁ
		CreateStraightGround(2, Vector2<int>(start_x_pos, cur_ground_height_));
		CreateStraightGround(2, Vector2<int>(start_x_pos + 400, cur_ground_height_));
		CreateStraightGround(2, Vector2<int>(start_x_pos + 800, cur_ground_height_));
		CreateStraightGround(2, Vector2<int>(start_x_pos + 1200, cur_ground_height_));
		CreateStraightCoin(3, Vector2<int>(start_x_pos + 200, cur_ground_height_ - 250), 400);
		CreateStraightCoin(3, Vector2<int>(start_x_pos + 300, cur_ground_height_ - 250), 400);
		new_ground_length = 1600;
		break;
	case GroundPatternID::HOLES_HARD1:
		//      ㅇㅇ      ㅇㅇ
		//    ㅇ        ㅇ
		//   
		// ㅁ        ㅁ        ㅁ  
		CreateStraightGround(1, Vector2<int>(start_x_pos, cur_ground_height_));
		CreateStraightGround(1, Vector2<int>(start_x_pos + 500, cur_ground_height_));
		CreateStraightGround(1, Vector2<int>(start_x_pos + 1000, cur_ground_height_));
		CreateStraightCoin(1, Vector2<int>(start_x_pos + 150, cur_ground_height_ - 200));
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 250, cur_ground_height_ - 300));
		CreateStraightCoin(1, Vector2<int>(start_x_pos + 600, cur_ground_height_ - 200));
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 700, cur_ground_height_ - 300));
		new_ground_length = 1300;
		break;
	case GroundPatternID::HOLES_HARD2:
		//            ㅇㅇ
		//    ㅇㅇ
		//                 ㅁ
		//         ㅁ
		// ㅁ
		CreateStraightGround(1, Vector2<int>(start_x_pos, cur_ground_height_));
		CreateStraightGround(1, Vector2<int>(start_x_pos + 400, cur_ground_height_ - 100));
		CreateStraightGround(1, Vector2<int>(start_x_pos + 800, cur_ground_height_ - 200));
		CreateStraightGround(1, Vector2<int>(start_x_pos + 1000, cur_ground_height_));
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 150, cur_ground_height_ - 300));
		CreateStraightCoin(2, Vector2<int>(start_x_pos + 550, cur_ground_height_ - 400));
		new_ground_length = 1350;
		break;
	case GroundPatternID::STAIRS:
		if (!ground_in_high_pos_) {
			//                 ㅁㅁ
			//         ㅁㅁ
			// ㅁㅁ
			CreateStraightGround(2, Vector2<int>(start_x_pos, cur_ground_height_));
			CreateStraightGround(2, Vector2<int>(start_x_pos + 400, cur_ground_height_ - 100));
			CreateStraightGround(2, Vector2<int>(start_x_pos + 800, cur_ground_height_ - 200));
			cur_ground_height_ -= 200;
			new_ground_length = 1200;
		}
		else {
			  
			//       ㅇx3
			//     ㅇ     ㅇ
			//             ㅇ
			// ㅁㅁ        
			//         
			//             ㅁㅁ
			CreateStraightGround(2, Vector2<int>(start_x_pos, cur_ground_height_));
			CreateStraightGround(2, Vector2<int>(start_x_pos + 600, cur_ground_height_ + 200));
			CreateStraightCoin(2, Vector2<int>(start_x_pos + 300, cur_ground_height_ - 250), 250);
			CreateStraightCoin(3, Vector2<int>(start_x_pos + 400, cur_ground_height_ - 350), 50);
			CreateStraightCoin(1, Vector2<int>(start_x_pos + 600, cur_ground_height_ - 200));
			cur_ground_height_ += 200;
			new_ground_length = 1000;
		}
		ground_in_high_pos_ = !ground_in_high_pos_;
		break;
	}
	remain_ground_length_ += new_ground_length;
}
