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

GameScene::GameScene(void)
	: input_manager_()
{

}

GameScene::~GameScene(void) {

}

InputManager& GameScene::GetInputManager(void) {
	return input_manager_;
}

void GameScene::DrawGameObjects(CDC* dc) {
	// layerID 순으로 sprite를 그림
	CDC object_dc;
	object_dc.CreateCompatibleDC(dc);

	for (const auto& layer : v_layer) {
		for (auto& sprite_renderer : sprite_renderers_[layer]) {
			std::shared_ptr<Sprite> sprite = sprite_renderer->GetSprite();
			if (sprite != nullptr) {
				object_dc.SelectObject(sprite->GetBitmap());
				Transform& transform = sprite_renderer->GetTransform();
				Vector2<int>& scale = sprite->GetScale();
				Vector2<int>& position = transform.GetPosition();
				dc->TransparentBlt(position.GetX(), position.GetY(), scale.GetX(), scale.GetY(),
					&object_dc, 0, 0, scale.GetX(), scale.GetY(), RGB(255, 0, 255));
			}
		}
	}

	object_dc.DeleteDC();
}

void GameScene::AddGameObject(std::shared_ptr<IGameObject> game_object) {
	// vector에 오브젝트 포인터를 추가
	// GameObject의 Start 함수 호출
	// 오브젝트들로부터 sprite를 받아옴. layerID로 정렬
	game_objects_[game_object.get()->GetTag()].push_back(game_object);
	game_object->Start();

	SpriteRenderer* sprite_renderer = game_object.get()->GetComponent<SpriteRenderer>();
	if (sprite_renderer != nullptr) {
		sprite_renderers_[sprite_renderer->GetLayerID()].push_back(sprite_renderer);
	}

	// Collider을 가진 객체 모아두기
	if (game_object.get()->GetComponent<Collider>() != nullptr) {
		game_objects_with_collider_.push_back(game_object);
	}

	// Rigidbody를 가진 객체 모아두기
	if (game_object.get()->GetComponent<Rigidbody>() != nullptr) {
		game_objects_with_Rigidbody_.push_back(game_object);
	}
}

std::shared_ptr<IGameObject> GameScene::Instantiate(IGameObjectFactory& factory, Vector2<int> position, Vector2<int> scale)
{
	std::shared_ptr<IGameObject> game_object = factory.Create(*this, position, scale);

	game_objects_to_add_.push_back(game_object);
	return game_object;
}

void GameScene::Destroy(std::shared_ptr<IGameObject> game_object) {
	game_objects_to_delete_.push_back(game_object);
}

void GameScene::CheckCollisions(void) {
	for (int i = 0; i < game_objects_with_Rigidbody_.size(); i++) {
		auto l_object = game_objects_with_Rigidbody_[i].lock();
		Collider* l_collider = l_object.get()->GetComponent<Collider>();
		if (l_collider == nullptr) {
			continue;
		}
		for (int j = i + 1; j < game_objects_with_collider_.size(); j++) {
			auto r_object = game_objects_with_collider_[j].lock();
			if (l_object == r_object) {
				continue;
			}

			CRect collision_area;
			Collider* r_collider = r_object.get()->GetComponent<Collider>();
			if (CheckCollision(collision_area, l_object, r_object)) {
				Collision l_collision = Collision(r_object, collision_area);
				Collision r_collision = Collision(l_object, collision_area);

				// 둘 다 trigger가 아닌 경우
				if (!(l_collider->IsTrigger() && r_collider->IsTrigger())) {
					l_object.get()->OnCollisionEnter(l_collision);
					r_object.get()->OnCollisionEnter(r_collision);
				}
				else {
					l_object.get()->OnTriggerEnter(l_collision);
					r_object.get()->OnTriggerEnter(r_collision);
				}

			}
		}
	}
}

const bool GameScene::CheckCollision(CRect& collision_area, std::shared_ptr<IGameObject>& l_object, std::shared_ptr<IGameObject>& r_object) {
	Collider* l_collider = l_object.get()->GetComponent<Collider>();
	Collider* r_collider = r_object.get()->GetComponent<Collider>();

	assert(l_collider != nullptr && r_collider != nullptr);

	CRect& l_rect = l_collider->GetRect();
	CRect& r_rect = r_collider->GetRect();

	return collision_area.IntersectRect(l_rect, r_rect);
}

void GameScene::OnTimer(UINT_PTR nIDEvent) {
	CView::OnTimer(nIDEvent);

	static ULONGLONG prev_time = GetTickCount64();

	ULONGLONG cur_time = GetTickCount64();
	float delta_time = (cur_time - prev_time) * 0.001f;
	prev_time = cur_time;

	// 입력 검사
	input_manager_.Update();

	// 오브젝트들을 업데이트
	int object_idx = 0;
	for (const auto& tag : v_tag) {
		for (auto& game_object : game_objects_[tag]) {
			game_object.get()->Update(delta_time);
			game_object.get()->UpdateComponents(delta_time);
		}
	}

	// 충돌 검사
	CheckCollisions();
	
	// 제거 풀에 있는 오브젝트 제거
	for (auto& game_object_to_delete : game_objects_to_delete_) {
		const auto& tag = game_object_to_delete.get()->GetTag();
		auto object_it = find(game_objects_[tag].begin(), game_objects_[tag].end(), game_object_to_delete);
		// 스프라이트 제거
		SpriteRenderer* sprite_renderer = object_it->get()->GetComponent<SpriteRenderer>();
		if (sprite_renderer != nullptr) {
			LayerID layer_id = sprite_renderer->GetLayerID();
			auto sprite_renderer_it = find(sprite_renderers_[layer_id].begin(), sprite_renderers_[layer_id].end(), sprite_renderer);
			sprite_renderers_[layer_id].erase(sprite_renderer_it);
		}

		// shared_ptr 해제 및 제거
		object_it->reset();
		game_objects_[tag].erase(object_it);
		game_object_to_delete.reset();
	}
	// 제거 풀 비우기
	std::vector<std::shared_ptr<IGameObject>>().swap(game_objects_to_delete_);

	// collider pool에 있는 게임 오브젝트 weak_ptr 제거
	for (int i = 0; i < game_objects_with_collider_.size(); i++) {
		std::shared_ptr<IGameObject> object_with_collider = game_objects_with_collider_[i].lock();
		if (!object_with_collider) {
			game_objects_with_collider_.erase(game_objects_with_collider_.begin() + i);
			i--;
		}
	}

	// 화면 그리기
	Invalidate();

	// 생성 풀에 있는 오브젝트 추가
	for (auto& game_object_to_add : game_objects_to_add_) {
		AddGameObject(game_object_to_add);
	}
	// 생성 풀 비우기
	std::vector<std::shared_ptr<IGameObject>>().swap(game_objects_to_add_);
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
