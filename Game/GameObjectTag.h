#pragma once
#include <vector>

enum class GameObjectTag
{
	PLAYER,
	GROUND,
	BULLET,
	ENEMY,
	DEFAULT
};

const std::vector<GameObjectTag> v_tag{
	GameObjectTag::PLAYER,
	GameObjectTag::GROUND,
	GameObjectTag::BULLET,
	GameObjectTag::ENEMY,
	GameObjectTag::DEFAULT
};
