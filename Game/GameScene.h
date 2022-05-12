#pragma once
#include <vector>

#include "afxwin.h"
#include "GameObject.h"
#include "Game.h"
#include "MainFrm.h"
#include "GameDoc.h"

class GameScene : public CView {
	DECLARE_DYNCREATE(GameScene);

public:
	GameScene(void);
	~GameScene(void);
	void UpdateScene(void);
	virtual void OnDraw(CDC* pDC);
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

	virtual void OnInitialUpdate();

	void AddGameObject(GameObject* gameObject);

protected:
	float fps;
	std::vector<GameObject> gameObjects;
};
