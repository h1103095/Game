#include "stdafx.h"
#include "Wall.h"

//Sprite Wall::kWallSprite_(IDB_WALL);

Wall::Wall(IGameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_renderer_(*this, Sprite::GetInstance(IDB_WALL), LayerID::WALL)
{

}

Wall::~Wall(void) {

}