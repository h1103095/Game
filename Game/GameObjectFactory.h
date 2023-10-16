#pragma once
#include "IGameObjectFactory.h"
#include <map>
//#include "BackGround.h"
//#include "Ground.h"
//#include "Coin.h"
//#include "Player.h"
//#include "Wall.h"
//#include "Bullet.h"
//
//
//template<typename T> std::shared_ptr<IGameObject> CreateInstance(IGameScene& scene, Vector2<int> position, Vector2<int> scale) { return std::make_shared<T>(scene, position, scale); };
//
//typedef std::map<CString, std::shared_ptr<IGameObject>(*)(IGameScene& scene, Vector2<int> position, Vector2<int> scale)> constructor_map_type;
//
//
//static const constructor_map_type constructor_map = {
//	std::make_pair(_T("BackGround"), &CreateInstance<BackGround>),
//	std::make_pair(_T("Ground"), &CreateInstance<Ground>),
//	std::make_pair(_T("Coin"), &CreateInstance<Coin>),
//	std::make_pair(_T("Player"), &CreateInstance<Player>),
//	std::make_pair(_T("Wall"), &CreateInstance<Wall>),
//	std::make_pair(_T("Bullet"), &CreateInstance<Bullet>),
//};
 


class GameObjectFactory: public IGameObjectFactory
{
	//static void AddGameObjectConstructor(CString classname, std::shared_ptr<IGameObject>(*constructor)(IGameScene& scene, Vector2<int> position, Vector2<int> scale));

public:
	GameObjectFactory(void) {};
	virtual ~GameObjectFactory(void) {};
	/*virtual std::shared_ptr<IGameObject> FactoryMethod(const CString& classname, IGameScene& scene, Vector2<int> position, Vector2<int> scale)
	{
		auto item = constructor_map.find(classname);
		if (item != constructor_map.end()) {
			std::shared_ptr<IGameObject> game_object = item->second(scene, position, scale);
			return game_object;
		}
		else {
#ifdef DEBUG
			TRACE("%s 생성 실패\n", classname);
#endif
			AfxThrowInvalidArgException();
		}
	}*/


	/*std::shared_ptr<IGameObject> GameScene::Instantiate(CString const& classname, Vector2<int> position, Vector2<int> scale) {
		auto item = constructor_map.find(classname);
		if (item != constructor_map.end()) {
			std::shared_ptr<IGameObject> game_object = item->second(*this, position, scale);
			game_objects_to_add_.push_back(game_object);
			return game_object;
		}
		else {
#ifdef DEBUG
			TRACE("%s 생성 실패\n", classname);
#endif
			AfxThrowInvalidArgException();
		}
	}*/
};