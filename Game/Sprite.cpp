#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite(IGameObject& parent, int bitmap_id, LayerID layer_id)
	: GameComponent(parent, ComponentID::SPRITE)
	, transform_(parent.GetTransform())
	, kLayerID(layer_id)
{
	SetBitmap(bitmap_id);
}

Sprite::~Sprite(void) {

}

void Sprite::SetBitmap(int bitmap_id) {
	image_ = std::make_shared<CBitmap>();
	image_->LoadBitmap(bitmap_id);
	BITMAP bitmap;
	image_->GetBitmap(&bitmap);
	transform_.SetScale(static_cast<int>(bitmap.bmWidth), static_cast<int>(bitmap.bmHeight));
}

std::shared_ptr<CBitmap> Sprite::GetBitmap(void) {
	return image_;
}

LayerID Sprite::GetLayerID(void) const {
	return kLayerID;
}

Transform& Sprite::GetTransform(void) {
	return transform_;
}