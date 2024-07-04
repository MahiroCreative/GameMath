#include "DxLib.h"
#include"Camera.h"
#include <cmath>
#include<iostream>

#include"Pad.h"

using namespace std;

namespace
{
	constexpr float kCameraDist = 96;
	constexpr float kCameraHeight = 32;
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// window���[�h�ݒ�
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);
	SetUseBackCulling(true);

	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);

	std::shared_ptr<Camera> camera;
	camera = std::make_shared<Camera>();

	float posX = 5;
	float moveSpeed = 0.2f;

	int sphere1R = 2;
	int sphere2R = 5;

	float colFlag = 0;

	while (ProcessMessage() == 0)
	{
		LONGLONG  time = GetNowHiPerformanceCount();
		// ��ʂ̃N���A
		ClearDrawScreen();
		posX-= moveSpeed;
		if (posX < -5)
		{
			moveSpeed = -0.2f;
		}
		if (posX > 5)
		{
			moveSpeed = 0.2f;
		}
	
		

		VECTOR sphere1Pos = VGet(posX, 0, 0);
		VECTOR sphere2Pos = VGet(-posX, 0, 0);
		
		colFlag = false;
		camera->Update();
		//���������߂�
		int Distance = sqrt((sphere2Pos.x - sphere1Pos.x) * (sphere2Pos.x - sphere1Pos.x) + (sphere2Pos.y - sphere1Pos.y) * (sphere2Pos.y - sphere1Pos.y) + (sphere2Pos.z - sphere1Pos.z) * (sphere2Pos.z - sphere1Pos.z));
		if (Distance < sphere1R + sphere2R)//���a�̍��v��苗�����Z��������
		{
			colFlag = true;
		}
		DrawSphere3D(sphere1Pos, sphere1R, 0, 0xff0000, 0xff0000, colFlag);
		DrawSphere3D(sphere2Pos, sphere2R, 0, 0x0000ff, 0x0000ff, colFlag);

		

		for (int x = -50; x <= 50; x += 10)
		{
			DrawLine3D(VGet(static_cast<float>(x), 0, -50), VGet(static_cast<float>(x), 0, 50), 0xffff00);
		}
		for (int z = -50; z <= 50; z += 10)
		{
			DrawLine3D(VGet(-50, 0, static_cast<float>(z)), VGet(50, 0, static_cast<float>(z)), 0xff0000);
		}

		//����ʂ�\��ʂ����ւ���
		ScreenFlip();

		// esc�L�[����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;

		// fps��60�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}