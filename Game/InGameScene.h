#pragma once
#include "GameScene.h"
#include "GameManager.h"
#include "Rigidbody.h"

class GameScene;

class InGameScene: public GameScene
{
public:
	InGameScene(void);
	virtual ~InGameScene(void);
	virtual void OnInitialUpdate(void);
private:
	const float kBackgroundSpeed = -200.0f;
};
