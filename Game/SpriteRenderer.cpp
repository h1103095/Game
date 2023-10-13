#include "stdafx.h"
#include "SpriteRenderer.h"


SpriteRenderer::SpriteRenderer(IGameObject& parent, std::shared_ptr<Sprite> sprite, const LayerID layer_id)
	: GameComponent(parent)
	, kLayerID(layer_id)
	, transform_(parent.GetTransform())
	, sprite_(sprite)
{

}

SpriteRenderer::~SpriteRenderer(void) {

}

void SpriteRenderer::SetSprite(std::shared_ptr<Sprite> sprite) {
	sprite_ = sprite;
}

std::shared_ptr<Sprite> SpriteRenderer::GetSprite(void) {
	return sprite_;
}

const LayerID SpriteRenderer::GetLayerID(void) const {
	return kLayerID;
}

Transform SpriteRenderer::GetTransform(void) {
	return transform_;
}