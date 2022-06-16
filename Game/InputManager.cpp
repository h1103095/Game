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
	if (GetKeyState(VK_SPACE) & 0x8000) {
		KeyDown(VK_SPACE);
	}
}

void InputManager::KeyDown(UINT key) {
	switch (key) {
	case VK_SPACE:
		down_keys_ |= static_cast<int>(Key::SPACE);
		break;
	}
}

void InputManager::KeyUp(UINT key) {
	switch (key) {
	case VK_SPACE:
		up_keys_ |= static_cast<int>(Key::SPACE);
		break;
	}
}

bool InputManager::GetKeyDown(Key key) {
	int key_val = static_cast<int>(key);
	return (down_keys_ & key_val) && (prev_down_keys_ ^ key_val);
}

bool InputManager::GetKeyUp(Key key) {
	return up_keys_ & static_cast<int>(key);
}