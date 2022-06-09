#include "stdafx.h"
#include "Player.h"

Player::Player(GameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_(*this, IDB_BIRD_WALK1, LayerID::DEFAULT)
	, animator_(*this)
	, rigidbody_(*this, true)
	, collider_(*this, transform_.GetPosition() + Vector2<int>(40, 25), Vector2<int>(30, 70))
{
	tag_ = GameObjectTag::PLAYER;
}

Player::~Player(void)
{

}