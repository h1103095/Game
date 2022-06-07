#pragma once
#include <memory>
#include "Vector2.h"
#include "GameComponent.h"
#include "LayerID.h"
#include "Transform.h"

class Transform;

class Sprite: public GameComponent {

public:
	Sprite(IGameObject& parent, int bitmap_id, LayerID layer_id);
	virtual ~Sprite(void);
	void SetBitmap(int bitmap_id);
	std::shared_ptr<CBitmap> GetBitmap(void);
	LayerID GetLayerID(void) const;
	Transform& GetTransform(void);
private:
	const LayerID kLayerID;
	Transform& transform_;
	std::shared_ptr<CBitmap> image_ = nullptr;
};

