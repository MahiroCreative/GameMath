#include "SceneMain.h"
#include "DxLib.h"
#include "Matrix4x4.h"
#include <cassert>

SceneMain::SceneMain() :
	m_frameCount(0)
{
	m_modelHandle = MV1LoadModel("Character_Gun.mv1");
	assert(m_modelHandle != -1);
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);

	SetCameraNearFar(100.0f, 2000.0f);

	SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 200.0f, -1000.0f), VGet(0.0f, 100.0f, 0.0f));

	m_modelPos = { 0.0f,200.0f,0.0f };
	MV1SetPosition(m_modelHandle, m_modelPos);
}

void SceneMain::Update()
{
	m_angle++;

	//m_modelPos = Matrix4x4::GetRotXMatrix(5) * m_modelPos;
	m_modelPos = Matrix4x4::GetRotZMatrix(3) * m_modelPos;
	// çáê¨çsóÒÇÃçÏê¨
	Matrix4x4 mat = Matrix4x4::GetRotZMatrix(3) * Matrix4x4::GetRotYMatrix(m_angle);
	m_modelPos = mat * m_modelPos;

	//MV1SetPosition(m_modelHandle, m_modelPos);
	MV1SetMatrix(m_modelHandle, mat.ConvertDxlibMatrix());

	m_frameCount++;
}

void SceneMain::Draw()
{
	MV1DrawModel(m_modelHandle);

	DrawSphere3D(VGet(0.0f, 0.0f, 0.0f), 10.0f, 8, 0xff0000, 0xff0000, true);

	DrawString(0,0,"SceneMain",0xffffff);
	DrawFormatString(0, 16, 0xffffff, "FRAME:%d", m_frameCount);
}