#pragma once
#include <vector>
#include <memory>
#include <map>
#include <cassert>

#include "afxwin.h"
#include "Game.h"
#include "GameDoc.h"
#include "GameScene.h"
#include "IGameObject.h"
#include "IGameObjectFactory.h"
#include "SpriteRenderer.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "LayerID.h"
#include "GameObjectTag.h"
#include "Collision.h"
#include "InputManager.h"


class GameScene : public CView {
	DECLARE_DYNCREATE(GameScene);

public:
	GameScene(void);
	virtual ~GameScene(void);
	InputManager& GetInputManager(void);
	void DrawGameObjects(CDC* dc);
	void AddGameObject(std::shared_ptr<IGameObject> game_object);
	std::shared_ptr<IGameObject> Instantiate(IGameObjectFactory& factory, Vector2<int> position = Vector2<int>::Zero(), Vector2<int> scale = Vector2<int>::Normal());
	void Destroy(std::shared_ptr<IGameObject> game_object);
	void CheckCollisions(void);
	const bool CheckCollision(CRect& collision_area, std::shared_ptr<IGameObject>& l_object, std::shared_ptr<IGameObject>& r_object);

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();

	virtual void OnDraw(CDC* dc);
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
	std::vector<std::weak_ptr<IGameObject>> game_objects_with_collider_;
	std::map<LayerID, std::vector<SpriteRenderer*>> sprite_renderers_;
	const int kTimerCycle = 15;
	InputManager input_manager_;
};
