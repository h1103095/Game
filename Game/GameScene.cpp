#include "stdafx.h"
#include "GameScene.h"

IMPLEMENT_DYNCREATE(GameScene, CView)

BEGIN_MESSAGE_MAP(GameScene, CView)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

GameScene::GameScene() {

}

GameScene::~GameScene() {

}


void GameScene::UpdateScene() {

}

void GameScene::DrawGameObjects(CDC* dc) {
	CDC object_dc;
	object_dc.CreateCompatibleDC(dc);

	for (const auto& layer : v_layer) {
		for (auto& sprite : sprites_[layer]) {
			object_dc.SelectObject(sprite->GetBitmap());
			Transform* transform = sprite->GetTransform();
			dc->TransparentBlt(transform->GetPosition()->get_int_x(), transform->GetPosition()->get_int_y(),
				transform->GetScale()->get_int_x(), transform->GetScale()->get_int_y(),
				&object_dc, 0, 0, transform->GetScale()->get_int_x(), transform->GetScale()->get_int_y(), RGB(255, 0, 0));
		}
	}

	object_dc.DeleteDC();
}

void GameScene::AddGameObject(GameObject* game_object) {
	game_objects_.push_back(game_object);
	Sprite* sprite = static_cast<Sprite*>(game_object->GetComponent(ComponentID::SPRITE));
	if (sprite != nullptr) {
		sprites_[sprite->GetLayerID()].push_back(sprite);
	}
}

void GameScene::OnTimer(UINT_PTR nIDEvent) {
	// 오브젝트들을 업데이트
	for (GameObject* gameObject : game_objects_) {
		gameObject->Update();
	}
}

void GameScene::OnDestroy() {
	CView::OnDestroy();
	KillTimer(0);
}

void GameScene::OnDraw(CDC* dc) {
	// 오브젝트들의 Update 함수를 호출
	// 오브젝트들로부터 sprite를 받아옴. layerID로 정렬
	// layerID 순으로 sprite를 그림

	//CDocument* pDoc = GetDocument();

	CDC buffer_dc;
	buffer_dc.CreateCompatibleDC(dc);

	// 더블 버퍼링
	CBitmap bitmap;
	CBitmap* old_bitmap;
	bitmap.CreateCompatibleBitmap(dc, WND_X, WND_Y);
	old_bitmap = buffer_dc.SelectObject(&bitmap);

	// 오브젝트 그리기
	DrawGameObjects(&buffer_dc);

	// 더블 버퍼링
	dc->BitBlt(0, 0, WND_X, WND_Y, &buffer_dc, 0, 0, SRCCOPY);
	buffer_dc.SelectObject(old_bitmap);
	buffer_dc.DeleteDC();
	bitmap.DeleteObject();
}

void GameScene::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	SetTimer(0, 15, NULL);
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
