#pragma once
#include <memory>
#include <vector>
#include "Sprite.h"


class Animation
{
public:
	Animation(bool loop, float time_interval);
	//Animation(std::vector<UINT> bitmap_id_vec, bool loop, float time_interval);
	std::shared_ptr<Sprite> GetNextSprite(void);
	const float GetTimeInterval(void) const;
	const bool GetLoop(void) const;
	void Init(void);
protected:
	std::vector<std::shared_ptr<Sprite>> sprites_;
	bool loop_;
	float time_interval_;
	static int cur_idx_;
};

