#pragma once
#include <vector>
#include <memory>
#include <cassert>

#include "afxwin.h"
#include "Game.h"
#include "GameDoc.h"
#include "IGameScene.h"
#include "IGameObject.h"
#include "SpriteRenderer.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "LayerID.h"
#include "GameObjectTag.h"
#include "Collision.h"
#include "InputManager.h"
#include "GameObjectFactory.h"
#include "BackGround.h"
#include "Ground.h"
#include "Coin.h"
#include "Player.h"
#include "Wall.h"
#include "Bullet.h"


template<typename T> std::shared_ptr<IGameObject> CreateInstance(IGameScene& scene, Vector2<int> position, Vector2<int> scale) { return std::make_shared<T>(scene, position, scale); };

typedef std::map<CString, std::shared_ptr<IGameObject>(*)(IGameScene& scene, Vector2<int> position, Vector2<int> scale)> constructor_map_type;

static const constructor_map_type constructor_map = {
	std::make_pair(_T("BackGround"), &CreateInstance<BackGround>),
	std::make_pair(_T("Ground"), &CreateInstance<Ground>),
	std::make_pair(_T("Coin"), &CreateInstance<Coin>),
	std::make_pair(_T("Player"), &CreateInstance<Player>),
	std::make_pair(_T("Wall"), &CreateInstance<Wall>),
	std::make_pair(_T("Bullet"), &CreateInstance<Bullet>),
};


class GameScene : public IGameScene {
	DECLARE_DYNCREATE(GameScene);

public:
	GameScene(void);
	virtual ~GameScene(void);
	virtual InputManager& GetInputManager(void);
	virtual void DrawGameObjects(CDC* dc);
	virtual void AddGameObject(std::shared_ptr<IGameObject> game_object);
	virtual void Destroy(std::shared_ptr<IGameObject> game_object);
	virtual void CheckCollisions(void);
	virtual const bool CheckCollision(CRect& collision_area, std::shared_ptr<IGameObject>& l_object, std::shared_ptr<IGameObject>& r_object);
	virtual std::shared_ptr<IGameObject> Instantiate(CString const& classname, Vector2<int> position, Vector2<int> scale = Vector2<int>::Normal());
	virtual afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual afx_msg void OnDestroy();

	virtual void OnDraw(CDC* pDC);
	virtual void OnInitialUpdate();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
	std::map<GameObjectTag, std::vector<std::shared_ptr<IGameObject>>> game_objects_;
	std::vector<std::shared_ptr<IGameObject>> game_objects_to_delete_;
	std::vector<std::shared_ptr<IGameObject>> game_objects_to_add_;
	std::vector<std::weak_ptr<IGameObject>> game_objects_with_rigidbody_;
	std::vector<std::weak_ptr<IGameObject>> game_objects_with_collider_;
	std::map<LayerID, std::vector<SpriteRenderer*>> sprite_renderers_;
	const int kTimerCycle = 15;
	InputManager input_manager_;
};