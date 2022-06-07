#include "stdafx.h"
#include "Player.h"

Player::Player(GameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_(*this, IDB_BIRD_WALK1, LayerID::OTHER)
	, animator_(*this)
{
}

Player::~Player(void)
{

}