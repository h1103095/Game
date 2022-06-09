#pragma once
#include <vector>

enum class LayerID
{
	BACKGROUND,
	WALL,
	GROUND,
	DEFAULT,
};


const std::vector<LayerID> v_layer{
	LayerID::BACKGROUND,
	LayerID::WALL,
	LayerID::GROUND,
	LayerID::DEFAULT,
};