#pragma once
#include <vector>
#include <memory>

#include "afxwin.h"
#include "Game.h"
#include "GameDoc.h"
#include "GameObject.h"
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
	void AddGameObject(GameObject* game_object);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();

	virtual void OnDraw(CDC* dc);
	virtual void OnInitialUpdate();
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
	std::vector<GameObject*> game_objects_;
	std::map<LayerID, std::vector<Sprite*>> sprites_;
};
