#include "stdafx.h"
#include "Collision.h"

Collision::Collision(std::shared_ptr<IGameObject> game_object, CRect collision_area)
	: game_object_(game_object)
	, collision_area_(collision_area)
	, tag_(game_object->GetTag())
{

}

Collision::~Collision(void) {

}

std::shared_ptr<IGameObject> Collision::GetGameObject(void) {
	return game_object_;
}

const CRect& Collision::GetCollisionArea(void) {
	return collision_area_;
}

const GameObjectTag& Collision::GetTag(void) {
	return tag_;
}