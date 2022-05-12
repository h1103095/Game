#pragma once
#include "Vector2.h"
#include "GameObject.h"
#include "GameComponent.h"
#include "Transform.h"
#include "LayerID.h"

class GameObject;
class GameComponent;
class Transform;

class Sprite: public GameComponent {

public:
	Sprite(GameObject* parent, int ID, LayerID layerID);
	~Sprite(void);
	LayerID GetLayerID(void);
	CBitmap* GetImage(void);
	Transform* GetTransform(void);
private:
	LayerID layerID;
	Transform* transform;
	CBitmap image;
};

