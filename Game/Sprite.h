#pragma once
#include <memory>
#include <map>
#include "Vector2.h"
#include "LayerID.h"
#include "resource.h"


class Sprite {

public:
	//Sprite(UINT bitmap_id);
	static std::shared_ptr<Sprite> GetInstance(UINT bitmap_id);
	virtual ~Sprite(void);
	CBitmap& GetBitmap(void);
	Vector2<int>& GetScale(void);

private:
	const UINT bitmap_id_;
	Vector2<int> scale_;
	CBitmap image_;
	static std::map<UINT, std::shared_ptr<Sprite>> sprite_map_;

protected:
	Sprite(UINT bitmap_id);
};


struct SpriteStruct : public Sprite {
	SpriteStruct(UINT bitmap_id)
		: Sprite(bitmap_id)
	{

	}
};