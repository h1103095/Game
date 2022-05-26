#pragma once

#include <vector>

enum class LayerID
{
	BACKGROUND,
	GROUND,
	OTHER,
};


const std::vector<LayerID> v_layer{
	LayerID::BACKGROUND,
	LayerID::GROUND,
	LayerID::OTHER,
};