#include "stdafx.h"
#include "GameScene.h"

IMPLEMENT_DYNCREATE(GameScene, CView)

GameScene::GameScene() {

}

GameScene::~GameScene() {

}


void GameScene::UpdateScene() {

}

#ifdef _DEBUG
void GameScene::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void GameScene::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG

void GameScene::OnInitialUpdate()
{
	CView::OnInitialUpdate();
}

void GameScene::AddGameObject(GameObject* gameObject) {

}

void GameScene::OnDraw(CDC* pDC) {
	// 오브젝트들의 Update 함수를 호출
	// 오브젝트들로부터 sprite를 받아옴. layerID로 정렬
	// layerID 순으로 sprite를 그림

	//CDocument* pDoc = GetDocument();

	
}