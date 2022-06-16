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
	// vector에 오브젝트 포인터를 추가
	// GameObject의 Start 함수 호출
	// 오브젝트들로부터 sprite를 받아옴. layerID로 정렬
	game_objects_[game_object.get()->GetTag()].push_back(game_object);
	game_object->Start();

	Sprite* sprite = game_object.get()->GetSprite();
	if (sprite != nullptr) {
		sprites_[sprite->GetLayerID()].push_back(sprite);
	}

	Collider* collider = static_cast<Collider*>(game_object.get()->GetComponent(ComponentID::COLLIDER));
	if (collider != nullptr) {
		game_objects_with_collider_.push_back(game_object);
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
	// 플레이어와 발판의 충돌을 처리
	// 플레이어와 적의 충돌을 처리
	// 총알과 적의 충돌을 처리
	for (int i = 0; i < game_objects_with_collider_.size(); i++) {
		auto l_object = game_objects_with_collider_[i].lock();
		for (int j = i + 1; j < game_objects_with_collider_.size(); j++) {
			auto r_object = game_objects_with_collider_[j].lock();

			CRect collision_area;
			Collider* l_collider = static_cast<Collider*>(l_object.get()->GetComponent(ComponentID::COLLIDER));
			Collider* r_collider = static_cast<Collider*>(r_object.get()->GetComponent(ComponentID::COLLIDER));
			if (CheckCollision(collision_area, l_object, r_object)) {
				Rigidbody* l_rigidbody = static_cast<Rigidbody*>(l_object.get()->GetComponent(ComponentID::RIGIDBODY));
				Rigidbody* r_rigidbody = static_cast<Rigidbody*>(r_object.get()->GetComponent(ComponentID::RIGIDBODY));

				Collision l_collision = Collision(r_object, collision_area);
				Collision r_collision = Collision(l_object, collision_area);

				// 현재 게임 내에 충돌하는 두 오브젝트 모두 rigidbody를 갖는 경우가 존재하지 않음
				if (!(l_collider->IsTrigger() && r_collider->IsTrigger())) {
					if (l_rigidbody != nullptr || r_rigidbody != nullptr) {
						Rigidbody* rigidbody = l_rigidbody;
						if (l_rigidbody == nullptr) {
							rigidbody = r_rigidbody;
						}

						float height = static_cast<float>(collision_area.Height());
						float width = static_cast<float>(collision_area.Width());

						rigidbody->GetTransform().Translate(0, -collision_area.Height());
						rigidbody->ResetForce();

					}
					else {
						// 둘 다 rigidbody를 갖는 경우는 게임 내에 없고
						// 둘 다 rigidbody가 없으면 추가 처리 x
					}

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
	Collider* l_collider = static_cast<Collider*>(l_object.get()->GetComponent(ComponentID::COLLIDER));
	Collider* r_collider = static_cast<Collider*>(r_object.get()->GetComponent(ComponentID::COLLIDER));

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

	CheckCollisions();

	// 제거 풀에 있는 오브젝트 제거
	for (auto& game_object_to_delete : game_objects_to_delete_) {
		const auto& tag = game_object_to_delete.get()->GetTag();
		auto object_it = find(game_objects_[tag].begin(), game_objects_[tag].end(), game_object_to_delete);
		// 스프라이트 제거
		Sprite* sprite = object_it->get()->GetSprite();
		if (sprite != nullptr) {
			LayerID layer_id = sprite->GetLayerID();
			auto sprite_it = find(sprites_[layer_id].begin(), sprites_[layer_id].end(), sprite);
			sprites_[layer_id].erase(sprite_it);
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
