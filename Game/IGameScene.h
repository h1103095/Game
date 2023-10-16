#pragma once
#include <memory>
#include "Vector2.h"

class IGameObject;
class InputManager;


class IGameScene : public CView {
public:
	virtual InputManager& GetInputManager(void) = 0;
	virtual void DrawGameObjects(CDC* dc) = 0;
	virtual void AddGameObject(std::shared_ptr<IGameObject> game_object) = 0;
	virtual void Destroy(std::shared_ptr<IGameObject> game_object) = 0;
	virtual void CheckCollisions(void) = 0;
	virtual const bool CheckCollision(CRect& collision_area, std::shared_ptr<IGameObject>& l_object, std::shared_ptr<IGameObject>& r_object) = 0;
	virtual std::shared_ptr<IGameObject> Instantiate(CString const& classname, Vector2<int> position, Vector2<int> scale = Vector2<int>::Normal()) = 0;
	virtual afx_msg void OnTimer(UINT_PTR nIDEvent) = 0;
	virtual afx_msg void OnDestroy() = 0;
	virtual afx_msg BOOL OnEraseBkgnd(CDC* pDC) = 0;
};

