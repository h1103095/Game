#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite(GameObject* parent, int bitmapID, LayerID layerID)
	: GameComponent(parent, ComponentID::SPRITE)
	, transform_(parent->GetTransform())
	, kLayerID(layerID)
{
	image_.LoadBitmap(bitmapID);
	BITMAP bitmap;
	image_.GetBitmap(&bitmap);
	transform_->SetScale(static_cast<int>(bitmap.bmWidth), static_cast<int>(bitmap.bmHeight));
}

Sprite::~Sprite(void) {

}

LayerID Sprite::GetLayerID(void) const {
	return kLayerID;
}

CBitmap* Sprite::GetBitmap(void) {
	return &image_;
}

Transform* Sprite::GetTransform(void) {
	return transform_.get();
}