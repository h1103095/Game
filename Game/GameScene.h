#pragma once
#include <vector>
#include <memory>
#include <map>

#include "afxwin.h"
#include "Game.h"
#include "GameDoc.h"
#include "IGameObject.h"
#include "IGameObjectFactory.h"
#include "Sprite.h"
#include "Collider.h"
#include "LayerID.h"


class GameScene : public CView {
	DECLARE_DYNCREATE(GameScene);

public:
	GameScene(void);
	virtual ~GameScene(void);
	void UpdateScene(void);
	void DrawGameObjects(CDC* dc);
	void AddGameObject(IGameObject* game_object);
	void Instantiate(IGameObjectFactory* factory, Vector2 position = Vector2::zero(), Vector2 scale = Vector2::normal());

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
	std::vector<IGameObject*> game_objects_;
	std::map<LayerID, std::vector<Sprite*>> sprites_;
	const int kTimerCycle = 15;
};
