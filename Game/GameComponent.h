#pragma once
#include <memory>
#include "IGameObject.h"

class GameComponent
{
public:
	GameComponent(IGameObject& parent);
	virtual ~GameComponent(void);
	virtual void Update(const float& delta_time);

protected:
	IGameObject& parent_;
};

