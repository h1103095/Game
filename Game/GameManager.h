#pragma once
#include <cstdlib>
#include "GameScene.h"
#include "GameObject.h"
#include "GameObjectFactory.h"
#include "GroundPatternID.h"


class GameManager: public GameObject
{
public:
	GameManager(GameScene& game_scene);
	virtual ~GameManager(void);
	virtual void Update(const float& delta_time);
	std::shared_ptr<Ground> CreateGround(Vector2<int> position);
	void CreateStraightGround(int num_ground, Vector2<int> position);
	void CreateGroundPattern(GroundPatternID pattern_id);

private:
	static bool instantiated_;
	GameObjectFactory<Ground> ground_factory_;
	ULONGLONG last_spawn_time_;
	ULONGLONG time_between_spawn_;
	int cur_ground_height_;
	bool ground_in_high_pos_;
	const int kNumInitGrounds = 20;
};
