#pragma once
#include <map>
#include <atltypes.h>
#include <WinUser.h>

enum class Key {
	// max 30 elements
	NONE = 0,
	SPACE = (1 << 0),
};

class InputManager
{
public:
	InputManager(void);
	virtual ~InputManager(void);
	void Update();
	void KeyDown(UINT key);
	void KeyUp(UINT key);
	bool GetKeyDown(Key key);
	bool GetKeyUp(Key key);

private:
	int down_keys_;
	int prev_down_keys_;
	int up_keys_;
};

