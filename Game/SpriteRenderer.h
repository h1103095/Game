#pragma once
#include <memory>
#include "Sprite.h"
#include "Transform.h"
#include "GameComponent.h"
#include "LayerID.h"

class SpriteRenderer: public GameComponent
{
public:
	SpriteRenderer(IGameObject& parent, std::shared_ptr<Sprite> sprite, LayerID layer_id);
	virtual ~SpriteRenderer(void);
	void SetSprite(std::shared_ptr<Sprite> sprite);
	std::shared_ptr<Sprite> GetSprite(void);
	Transform GetTransform(void);
	const LayerID GetLayerID(void) const;

private:
	const LayerID kLayerID;
	Transform& transform_;
	std::shared_ptr<Sprite> sprite_;
};

