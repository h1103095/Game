#include "stdafx.h"
#include "InGameScene.h"

InGameScene::InGameScene(void) {
	
}

InGameScene::~InGameScene(void) {

}

void InGameScene::OnInitialUpdate(void) {
	GameScene::OnInitialUpdate();

	// ���� GameManager�� BackgroundManager���� �����ϱ�
	//AddGameObject(new BackGroundManager());

	//AddGameObject(new Player(100, 400));

	//GameObjectFactory<Ground>* ground_factory = new GameObjectFactory<Ground>();
	//ground_factory->Create(Vector2(100, 400));
	//ground_factory->FactoryMethod(Vector2(400, 100), Vector2::normal());
	Instantiate(new GameObjectFactory<BackGround>(), Vector2(0, 0));
	Instantiate(new GameObjectFactory<BackGround>(), Vector2(2400, 0));
	Instantiate(new GameObjectFactory<Ground>(), Vector2(100, 600));
	

	//for (auto ground : Ground::CreateGround(Vector2(100, 600), 10)) {
	//	AddGameObject(ground);
	//}
	
}