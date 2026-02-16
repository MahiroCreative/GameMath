#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"

class SceneMain
{
public:
	SceneMain();
	~SceneMain();

	void Init();
	void Update();
	void Draw();

private:
	void DrawGrid();

private:
	int m_frameCount;

	float m_angle;

	int m_modelHandle;

	Matrix4x4 m_rotationMat;

	// カメラの動かす座標
	Vector3 m_pos;

};

