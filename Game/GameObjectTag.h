#pragma once
#include <vector>

enum class GameObjectTag
{
	DEFAULT,
	PLAYER,
	GROUND,
	BULLET,
	ENEMY,
};

static const std::vector<GameObjectTag> v_tag{
	GameObjectTag::DEFAULT,
	GameObjectTag::PLAYER,
	GameObjectTag::GROUND,
	GameObjectTag::BULLET,
	GameObjectTag::ENEMY
};
