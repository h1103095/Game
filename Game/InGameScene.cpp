#include "stdafx.h"
#include "InGameScene.h"

InGameScene::InGameScene(void) {
	
}

InGameScene::~InGameScene(void) {

}

void InGameScene::OnInitialUpdate(void) {
	GameScene::OnInitialUpdate();

	AddGameObject(std::static_pointer_cast<IGameObject>(std::make_shared<GameManager>(*this)));
	
	Instantiate(_T("BackGround"), Vector2<int>(0, 0));
	Instantiate(_T("BackGround"), Vector2<int>(2400, 0));
	Instantiate(_T("Player"), Vector2<int>(200, 450));
	Instantiate(_T("Wall"), Vector2<int>(0, 0));
}