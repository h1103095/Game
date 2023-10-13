#pragma once
#include <vector>

enum class LayerID
{
	DEFAULT,
	BACKGROUND,
	GROUND,
	WALL,
	PLAYER,
};


static const std::vector<LayerID> v_layer{
	LayerID::DEFAULT,
	LayerID::BACKGROUND,
	LayerID::GROUND,
	LayerID::WALL,
	LayerID::PLAYER,
};