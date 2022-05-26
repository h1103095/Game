#pragma once
#include <vector>
#include "GameObject.h"
#include "GameComponent.h"
#include "Sprite.h"

class Sprite;

class Animation: public GameComponent
{
public:
	Animation(GameObject* parent);
	~Animation(void);
	void AddSprite(Sprite* sprite);
private:
	std::vector<Sprite*> sprites_;
};
