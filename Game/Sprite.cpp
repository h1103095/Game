#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite(GameObject* parent, int ID, LayerID layerID)
	:GameComponent(parent, ComponentID::SPRITE)
{
	this->transform = parent->GetTransform();
	this->layerID = layerID;
	image.LoadBitmap(ID);
}

Sprite::~Sprite(void) {

}

LayerID Sprite::GetLayerID(void) {
	return layerID;
}

CBitmap* Sprite::GetImage(void) {
	return &image;
}

Transform* Sprite::GetTransform(void) {
	return transform;
}