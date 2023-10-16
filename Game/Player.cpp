#include "stdafx.h"
#include "Player.h"


Player::Player(IGameScene& game_scene, Vector2<int> position, Vector2<int> scale)
	: GameObject(game_scene, position, scale)
	, sprite_renderer_(*this, nullptr, LayerID::PLAYER)
	, animator_(*this, sprite_renderer_)
	, rigidbody_(*this, BodyType::DYNAMIC)
	, collider_(*this, Vector2<int>(40, 82), Vector2<int>(35, 15), false)
	, jump_cnt_(0)
	, is_on_ground_(false)
{
	tag_ = GameObjectTag::PLAYER;
}

Player::~Player(void)
{

}

void Player::Update(const float& delta_time) {
	if (scene_.GetInputManager().GetKeyDown(Key::SPACE)) {
		Jump();
	}
	if (scene_.GetInputManager().GetKeyDown(Key::LBUTTON)) {
		//scene_.Instantiate();
	}
}

void Player::OnCollisionEnter(Collision& collision) {
	std::shared_ptr<IGameObject> object = collision.GetGameObject();
	if (object->GetTag() == GameObjectTag::GROUND) {

		if (!is_on_ground_) {
			is_on_ground_ = true;
			jump_cnt_ = 0;
			animator_.SetAnimationByPlayerStateID(PlayerStateID::WALKING);
		}
		transform_.Translate(0, -collision.GetCollisionArea().Height());
		rigidbody_.ResetForce();
	}

	if (object->GetTag() == GameObjectTag::COIN) {
		scene_.Destroy(object);
	}
}

void Player::Jump(void) {
	if (jump_cnt_ < kNumMaxJump_) {
		is_on_ground_ = false;
		rigidbody_.SetForce(rigidbody_.GetSpeed().x, kJumpForce_);
		jump_cnt_++;
		animator_.SetAnimationByPlayerStateID(PlayerStateID::JUMPING);
	}
}