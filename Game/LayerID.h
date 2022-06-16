#pragma once
#include <vector>

enum class LayerID
{
	DEFAULT,
	BACKGROUND,
	WALL,
	GROUND,
	PLAYER,
};


static const std::vector<LayerID> v_layer{
	LayerID::DEFAULT,
	LayerID::BACKGROUND,
	LayerID::WALL,
	LayerID::GROUND,
	LayerID::PLAYER,
};