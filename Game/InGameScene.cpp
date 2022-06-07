#include "stdafx.h"
#include "InGameScene.h"

InGameScene::InGameScene(void) {
	
}

InGameScene::~InGameScene(void) {

}

void InGameScene::OnInitialUpdate(void) {
	GameScene::OnInitialUpdate();

	AddGameObject(std::static_pointer_cast<IGameObject>(std::make_shared<GameManager>(*this)));
	Instantiate(new GameObjectFactory<BackGround>(), Vector2<int>(0, 0));
	Instantiate(new GameObjectFactory<BackGround>(), Vector2<int>(2400, 0));
	
}