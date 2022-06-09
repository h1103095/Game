#include "stdafx.h"
#include "InGameScene.h"

InGameScene::InGameScene(void) {
	
}

InGameScene::~InGameScene(void) {

}

void InGameScene::OnInitialUpdate(void) {
	GameScene::OnInitialUpdate();

	GameObjectFactory<BackGround> back_ground_factory;
	GameObjectFactory<Player> player_factory;
	GameObjectFactory<Wall> wall_factory;

	AddGameObject(std::static_pointer_cast<IGameObject>(std::make_shared<GameManager>(*this)));
	Instantiate(back_ground_factory, Vector2<int>(0, 0));
	Instantiate(back_ground_factory, Vector2<int>(2400, 0));
	Instantiate(player_factory, Vector2<int>(100, 450));
	Instantiate(wall_factory, Vector2<int>(0, 0));
}