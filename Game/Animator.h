#pragma once
#include "IGameObject.h"
#include "GameComponent.h"
#include "Animation.h"
#include "SpriteRenderer.h"

class Animator: public GameComponent
{
public:
	Animator(IGameObject& parent, SpriteRenderer& sprite_renderer);
	~Animator(void);
	void NextSprite(void);
	void SetAnimation(std::shared_ptr<Animation> next_animation);
	virtual void Update(const float& delta_time);
protected:
	std::shared_ptr<Animation> cur_animation_;
	std::shared_ptr<Sprite> cur_sprite_;
	SpriteRenderer& sprite_renderer_;
	float cur_ani_time_interval_;
	bool cur_ani_loop_;
};
