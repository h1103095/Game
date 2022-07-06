#include "stdafx.h"
#include "Sprite.h"


std::map<UINT, std::shared_ptr<Sprite>> Sprite::sprite_map_;

Sprite::Sprite(UINT bitmap_id)
	: scale_(Vector2<int>::Normal())
	, image_()
	, bitmap_id_(bitmap_id)
{
	image_.LoadBitmap(bitmap_id_);
	BITMAP bitmap;
	image_.GetBitmap(&bitmap);
	scale_.SetXY(static_cast<int>(bitmap.bmWidth), static_cast<int>(bitmap.bmHeight));
}

Sprite::~Sprite(void) {

}

std::shared_ptr<Sprite> Sprite::GetInstance(UINT bitmap_id) {
	auto ret = sprite_map_.insert({ bitmap_id, nullptr });
	if (ret.second) {
		ret.first->second = std::make_shared<SpriteStruct>(bitmap_id);
	}
	return ret.first->second;
}

CBitmap& Sprite::GetBitmap(void) {
	return image_;
}

Vector2<int>& Sprite::GetScale(void) {
	return scale_;
}