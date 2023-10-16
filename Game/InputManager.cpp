#include "stdafx.h"
#include "InputManager.h"


InputManager::InputManager(void)
	: down_keys_(0)
	, prev_down_keys_(0)
	, up_keys_(0)
{

}

InputManager::~InputManager(void) {

}

void InputManager::Update(void) {
	prev_down_keys_ = down_keys_;
	down_keys_ = 0;
	up_keys_ = 0;

	for (auto const& pair : key_map) {
		if (GetKeyState(pair.first) & 0x8000) {
			KeyDown(pair.second);
		}
	}
}

void InputManager::KeyDown(Key key) {
	down_keys_ |= static_cast<int>(key);
}

void InputManager::KeyUp(Key key) {
	up_keys_ |= static_cast<int>(key);
}

bool InputManager::GetKeyDown(Key key) {
	int key_val = static_cast<int>(key);
	return (down_keys_ & key_val) && (prev_down_keys_ ^ key_val);
}

bool InputManager::GetKeyUp(Key key) {
	return up_keys_ & static_cast<int>(key);
}