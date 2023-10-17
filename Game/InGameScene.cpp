#include "stdafx.h"
#include "InGameScene.h"

InGameScene::InGameScene(void) {
	
}

InGameScene::~InGameScene(void) {

}

void InGameScene::OnInitialUpdate(void) {
	GameScene::OnInitialUpdate();

	AddGameObject(std::static_pointer_cast<IGameObject>(std::make_shared<GameManager>(*this)));
	
	std::shared_ptr<IGameObject> background = Instantiate(_T("BackGround"), Vector2<int>(0, 0));
	background->GetComponent<Rigidbody>()->SetForce(kBackgroundSpeed, 0.f);
	background = Instantiate(_T("BackGround"), Vector2<int>(WND_X * 2, 0));
	background->GetComponent<Rigidbody>()->SetForce(kBackgroundSpeed, 0.f);
	Instantiate(_T("Player"), Vector2<int>(200, 450));
	Instantiate(_T("Wall"), Vector2<int>(0, 0));
}