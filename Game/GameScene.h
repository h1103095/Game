#pragma once
#include <vector>
#include <memory>
#include <map>

#include "afxwin.h"
#include "Game.h"
#include "GameDoc.h"
#include "GameScene.h"
#include "IGameObject.h"
#include "IGameObjectFactory.h"
#include "Sprite.h"
#include "Collider.h"
#include "LayerID.h"
#include "GameObjectTag.h"


class GameScene : public CView {
	DECLARE_DYNCREATE(GameScene);

public:
	GameScene(void);
	virtual ~GameScene(void);
	void UpdateScene(void);
	void DrawGameObjects(CDC* dc);
	void AddGameObject(std::shared_ptr<IGameObject> game_object);
	std::shared_ptr<IGameObject> Instantiate(IGameObjectFactory& factory, Vector2<int> position = Vector2<int>::Zero(), Vector2<int> scale = Vector2<int>::Normal());
	void Destroy(std::shared_ptr<IGameObject> game_object);

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();

	virtual void OnDraw(CDC* dc);
	virtual void OnInitialUpdate();
	virtual BOOL OnEraseBkgnd(CDC* pDC);
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
	std::map<GameObjectTag, std::vector<std::shared_ptr<IGameObject>>> game_objects_;
	std::map<GameObjectTag, std::vector<std::shared_ptr<IGameObject>>> game_objects_to_delete_;
	std::map<GameObjectTag, std::vector<std::shared_ptr<IGameObject>>> game_objects_to_add_;
	std::map<LayerID, std::vector<Sprite*>> sprites_;
	const int kTimerCycle = 15;
};
