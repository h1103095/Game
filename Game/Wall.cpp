#include "stdafx.h"
#include "Wall.h"

Wall::Wall(GameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_(*this, IDB_WALL, LayerID::WALL)
{

}

Wall::~Wall(void) {

}