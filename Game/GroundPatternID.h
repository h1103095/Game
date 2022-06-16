#pragma once
#include <vector>

enum class GroundPatternID
{
	STRAIGHT	=	0,
	HOLE		=	1,
	HOLES_EASY1	=	2,
	HOLES_EASY2	=	3,
	HOLES_HARD1	=	4,
	HOLES_HARD2	=	5,
	STAIRS		=	6,
};

static const std::vector<GroundPatternID> v_ground_pattern_id{
	GroundPatternID::STRAIGHT,
	GroundPatternID::HOLE,
	GroundPatternID::HOLES_EASY1,
	GroundPatternID::HOLES_EASY2,
	GroundPatternID::HOLES_HARD1,
	GroundPatternID::HOLES_HARD2,
	GroundPatternID::STAIRS,
};

