#pragma once
#include "atltypes.h"
#include "GameObject.h"
#include "Collider.h"

class Bullet : public GameObject
{
public:
	Bullet(IGameScene& game_scene, Vector2<int> position, Vector2<int> scale);
	virtual ~Bullet(void);
	virtual void Update(void);
	virtual void OnColliderEnter(Collision& collision);
	void Move(void);
	void SetDestination(Vector2<int> destination);

private:
	Vector2<int> destination_;
	const float kSpeed = 17;
	Collider collider_;
	double degree_;
};