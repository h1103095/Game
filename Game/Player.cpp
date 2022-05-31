#include "stdafx.h"
#include "Player.h"

Player::Player(GameScene* game_scene, Vector2 position, Vector2 scale)
	: GameObject(game_scene, position, scale)
	, sprite_(this, IDB_BIRD_WALK1, LayerID::OTHER)
	, animator_(this)
{
}

Player::~Player(void)
{

}