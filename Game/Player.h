#pragma once
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "PlayerAnimator.h"
#include "Rigidbody.h"
#include "Collider.h"

class Player: public GameObject
{
public:
	Player(IGameScene& game_scene, Vector2<int> position, Vector2<int> scale);
	virtual ~Player(void);
	virtual void Update(const float& delta_time);
	virtual void OnCollisionEnter(Collision& collision);
	void Jump(void);

private:
	SpriteRenderer sprite_renderer_;
	PlayerAnimator animator_;
	Rigidbody rigidbody_;
	Collider collider_;
	const float kNumMaxJump_ = 2;
	const float kJumpForce_ = -500.0f;
	float jump_cnt_;
	bool is_on_ground_;
};

