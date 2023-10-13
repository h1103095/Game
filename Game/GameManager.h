#pragma once
#include <cstdlib>
#include "GameScene.h"
#include "GameObject.h"
#include "GameObjectFactory.h"
#include "GroundPatternID.h"
#include "Vector2.h"

class GameManager: public GameObject
{
public:
	GameManager(GameScene& game_scene);
	virtual ~GameManager(void);
	virtual void Update(const float& delta_time);
	std::shared_ptr<Ground> CreateGround(Vector2<int> position);
	std::shared_ptr<Coin> CreateCoin(Vector2<int> position);
	void CreateStraightGround(int num_ground, Vector2<int> position, int interval=100);
	void CreateStraightCoin(int num_ground, Vector2<int> position, int interval=100);
	void CreateGroundPattern(GroundPatternID pattern_id);

private:
	static bool instantiated_;
	GameObjectFactory<Ground> ground_factory_;
	GameObjectFactory<Coin> coin_factory_;
	ULONGLONG last_spawn_time_;
	ULONGLONG time_between_spawn_;
	int remain_ground_length_;
	int cur_ground_height_;
	bool ground_in_high_pos_;
	const int kNumInitGrounds = 12;
	const float kGroundSpeed = -300.0f;
	const Vector2<int> kGroundScale = Vector2<int>(100, 100);
	const Vector2<int> kCoinScale = Vector2<int>(100, 100);
};
