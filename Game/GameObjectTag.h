#pragma once
#include <vector>

enum class GameObjectTag
{
	DEFAULT,
	PLAYER,
	GROUND,
	COIN,
	BULLET,
	ENEMY,
};

static const std::vector<GameObjectTag> v_tag{
	GameObjectTag::DEFAULT,
	GameObjectTag::PLAYER,
	GameObjectTag::GROUND,
	GameObjectTag::COIN,
	GameObjectTag::BULLET,
	GameObjectTag::ENEMY
};
