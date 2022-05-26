#pragma once
#include <memory>
#include "Vector2.h"
#include "GameComponent.h"
#include "LayerID.h"

class GameObject;
class Transform;

class Sprite: public GameComponent {

public:
	Sprite(GameObject* parent, int bitmapID, LayerID layerID);
	virtual ~Sprite(void);
	LayerID GetLayerID(void) const;
	CBitmap* GetBitmap(void);
	Transform* GetTransform(void);
private:
	const LayerID kLayerID;
	std::tr1::shared_ptr<Transform> transform_;
	CBitmap image_;
};

