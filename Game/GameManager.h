#pragma once
#include "GameScene.h"
#include "GameObject.h"
#include "GameObjectFactory.h"
#include "GroundPatternID.h"


class GameManager: public GameObject
{
public:
	GameManager(GameScene& game_scene);
	virtual ~GameManager(void);
	std::shared_ptr<Ground> CreateGround(Vector2<int> position);
	void CreateStraightGround(int num_ground, Vector2<int> position);
	void CreateGroundPattern(GroundPatternID pattern_id, Vector2<int>  position);

private:
	//GameScene& scene_;
	static bool instantiated_;
	int cur_ground_length_;
	int cur_ground_height_;
	bool ground_in_high_pos_;
	const int kNumInitGrounds = 15;
};
