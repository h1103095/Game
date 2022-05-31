#pragma once
#include "GameScene.h"
//#include "IGameObjectFactory.h"
#include "GameObjectFactory.h"

class GameScene;

class InGameScene: public GameScene
{
public:
	InGameScene(void);
	virtual ~InGameScene(void);
	virtual void OnInitialUpdate(void);

private:
	
};
