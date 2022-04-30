#pragma once
#include <vector>
#include "GameObject.h"
using std::vector;

class GameScene : public CView
{
public:
	GameScene(void);
	~GameScene(void);
	void UpdateScene(void);
	void Draw(void);
private:
	

public:

private:
	float fps;
	vector<GameObject> m_vecGameObjects;
};

