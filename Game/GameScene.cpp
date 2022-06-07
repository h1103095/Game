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

GameScene::GameScene()
{

}

GameScene::~GameScene() {

}


void GameScene::UpdateScene() {

}

void GameScene::DrawGameObjects(CDC* dc) {
	// layerID 순으로 sprite를 그림
	CDC object_dc;
	object_dc.CreateCompatibleDC(dc);

	for (const auto& layer : v_layer) {
		for (auto& sprite : sprites_[layer]) {
			object_dc.SelectObject(sprite->GetBitmap().get());
			Transform& transform = sprite->GetTransform();
			Vector2<int>& position = transform.GetPosition();
			Vector2<int>& scale = transform.GetScale();
			dc->TransparentBlt(position.get_x(), position.get_y(), scale.get_x(), scale.get_y(),
				&object_dc, 0, 0, scale.get_x(), scale.get_y(), RGB(255, 0, 255));
			TRACE("transform: %f, %f\n", position.get_x(), position.get_y());
			TRACE("transform: %d, %d\n", position.get_x(), position.get_y());
		}
	}

	object_dc.DeleteDC();
}

void GameScene::AddGameObject(std::shared_ptr<IGameObject> game_object) {
	// vector에 오브젝트 포인터를 추가
	// GameObject의 Start 함수 호출
	// 오브젝트들로부터 sprite를 받아옴. layerID로 정렬
	game_objects_.push_back(game_object);
	game_object->Start();

	Sprite* sprite = game_object.get()->GetSprite();
	if (sprite != nullptr) {
		sprites_[sprite->GetLayerID()].push_back(sprite);
	}
}

std::shared_ptr<IGameObject> GameScene::Instantiate(IGameObjectFactory* factory, Vector2<int> position, Vector2<int> scale)
{
	std::shared_ptr<IGameObject> game_object = factory->Create(*this, position, scale);

	AddGameObject(game_object);
	return game_object;
}

const int GameScene::GetTimerCycle(void)
{
	return kTimerCycle;
}

void GameScene::OnTimer(UINT_PTR nIDEvent) {
	CView::OnTimer(nIDEvent);

	static ULONGLONG prev_time = GetTickCount64();

	ULONGLONG cur_time = GetTickCount64();
	float delta_time = (cur_time - prev_time) * 0.001f;
	prev_time = cur_time;

	// 오브젝트들을 업데이트
	for (auto gameObject : game_objects_) {
		gameObject.get()->Update(delta_time);
	}

	// 화면 그리기
	Invalidate();
}

void GameScene::OnDestroy() {
	CView::OnDestroy();
	KillTimer(0);
}

void GameScene::OnDraw(CDC* dc) {
	CDC buffer_dc;
	buffer_dc.CreateCompatibleDC(dc);

	// 더블 버퍼링
	CBitmap bitmap;
	CBitmap* old_bitmap;
	bitmap.CreateCompatibleBitmap(dc, WND_X, WND_Y);
	old_bitmap = buffer_dc.SelectObject(&bitmap);

	buffer_dc.PatBlt(0, 0, WND_X, WND_Y, BLACKNESS);

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
	SetTimer(0, kTimerCycle, NULL);
}

BOOL GameScene::OnEraseBkgnd(CDC* pDC) {
	return TRUE;
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
