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
	// layerID ������ sprite�� �׸�
	CDC object_dc;
	object_dc.CreateCompatibleDC(dc);

	for (const auto& layer : v_layer) {
		for (auto& sprite : sprites_[layer]) {
			object_dc.SelectObject(sprite->GetBitmap().get());
			Transform& transform = sprite->GetTransform();
			Vector2<int>& position = transform.GetPosition();
			Vector2<int>& scale = transform.GetScale();
			dc->TransparentBlt(position.GetX(), position.GetY(), scale.GetX(), scale.GetY(),
				&object_dc, 0, 0, scale.GetX(), scale.GetY(), RGB(255, 0, 255));
		}
	}

	object_dc.DeleteDC();
}

void GameScene::AddGameObject(std::shared_ptr<IGameObject> game_object) {
	// vector�� ������Ʈ �����͸� �߰�
	// GameObject�� Start �Լ� ȣ��
	// ������Ʈ��κ��� sprite�� �޾ƿ�. layerID�� ����
	game_objects_[game_object.get()->GetTag()].push_back(game_object);
	game_object->Start();

	Sprite* sprite = game_object.get()->GetSprite();
	if (sprite != nullptr) {
		sprites_[sprite->GetLayerID()].push_back(sprite);
	}
}

std::shared_ptr<IGameObject> GameScene::Instantiate(IGameObjectFactory& factory, Vector2<int> position, Vector2<int> scale)
{
	/*std::shared_ptr<IGameObject> game_object = factory->Create(*this, position, scale);

	AddGameObject(game_object);*/

	std::shared_ptr<IGameObject> game_object = factory.Create(*this, position, scale);

	game_objects_to_add_[game_object.get()->GetTag()].push_back(game_object);
	return game_object;
}

void GameScene::Destroy(std::shared_ptr<IGameObject> game_object) {
	game_objects_to_delete_[game_object.get()->GetTag()].push_back(game_object);
}

void GameScene::OnTimer(UINT_PTR nIDEvent) {
	CView::OnTimer(nIDEvent);

	static ULONGLONG prev_time = GetTickCount64();

	ULONGLONG cur_time = GetTickCount64();
	float delta_time = (cur_time - prev_time) * 0.001f;
	prev_time = cur_time;

	// ������Ʈ���� ������Ʈ
	int object_idx = 0;
	for (const auto& tag : v_tag) {
		for (auto& game_object : game_objects_[tag]) {
			game_object.get()->Update(delta_time);
		}
	}

	// ���� Ǯ�� �ִ� ������Ʈ ����
	for (const auto& tag : v_tag) {
		for (auto& game_object_to_delete : game_objects_to_delete_[tag]) {
			auto object_it = find(game_objects_[tag].begin(), game_objects_[tag].end(), game_object_to_delete);
			// ��������Ʈ ����
			Sprite* sprite = object_it->get()->GetSprite();
			if (sprite != nullptr) {
				LayerID layer_id = sprite->GetLayerID();
				auto sprite_it = find(sprites_[layer_id].begin(), sprites_[layer_id].end(), sprite);
				sprites_[layer_id].erase(sprite_it);
			}

			object_it->reset();
			game_objects_[tag].erase(object_it);
			game_object_to_delete.reset();
		}
		// ���� Ǯ ����
		std::vector<std::shared_ptr<IGameObject>>().swap(game_objects_to_delete_[tag]);
	}

	// ȭ�� �׸���
	Invalidate();

	// ���� Ǯ�� �ִ� ������Ʈ �߰�
	for (const auto& tag : v_tag) {
		for (auto& game_object_to_add : game_objects_to_add_[tag]) {
			AddGameObject(game_object_to_add);
		}
		// ���� Ǯ ����
		std::vector<std::shared_ptr<IGameObject>>().swap(game_objects_to_add_[tag]);
	}
}

void GameScene::OnDestroy() {
	CView::OnDestroy();
	KillTimer(0);
}

void GameScene::OnDraw(CDC* dc) {
	CDC buffer_dc;
	buffer_dc.CreateCompatibleDC(dc);

	// ���� ���۸�
	CBitmap bitmap;
	CBitmap* old_bitmap;
	bitmap.CreateCompatibleBitmap(dc, WND_X, WND_Y);
	old_bitmap = buffer_dc.SelectObject(&bitmap);

	buffer_dc.PatBlt(0, 0, WND_X, WND_Y, BLACKNESS);

	// ������Ʈ �׸���
	DrawGameObjects(&buffer_dc);

	// ���� ���۸�
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
