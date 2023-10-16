#pragma once
#include "GameScene.h"
#include "GameManager.h"

class GameScene;

class InGameScene: public GameScene
{
public:
	InGameScene(void);
	virtual ~InGameScene(void);
	virtual void OnInitialUpdate(void);
};
