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
	// ������Ʈ���� Update �Լ��� ȣ��
	// ������Ʈ��κ��� sprite�� �޾ƿ�. layerID�� ����
	// layerID ������ sprite�� �׸�

	//CDocument* pDoc = GetDocument();

	
}