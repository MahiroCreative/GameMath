#pragma once
#include "Dxlib.h"

class SceneMain
{
public:
	SceneMain();
	~SceneMain();

	void Init();
	void Update();
	void Draw();
private:
	int m_frameCount;

	int m_modelHandle = -1;

	int m_angle = 0;
	VECTOR m_modelPos = { 0.0f, 0.0f, 0.0f };
};

