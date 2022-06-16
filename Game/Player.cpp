#include "stdafx.h"
#include "Player.h"

Player::Player(GameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_(*this, IDB_BIRD_WALK1, LayerID::PLAYER)
	, animator_(*this)
	, rigidbody_(*this, true)
	, collider_(*this, Vector2<int>(40, 82), Vector2<int>(35, 15), false)
{
	tag_ = GameObjectTag::PLAYER;
}

Player::~Player(void)
{

}

void Player::Update(const float& delta_time) {

	TRACE("%d\n", transform_.GetPosition().GetY());
	
	if (scene_.GetInputManager().GetKeyDown(Key::SPACE)) {
#ifdef DEBUG
		TRACE("JUMP!\n");
#endif
		Jump();
	}
}

void Player::Jump(void) {
	rigidbody_.SetForce(rigidbody_.GetSpeed().x, kJumpForce_);
}