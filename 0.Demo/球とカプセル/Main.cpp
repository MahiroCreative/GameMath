#include "DxLib.h"
#include <cmath>


VECTOR Closs(VECTOR pos, VECTOR target)
{
	return VGet(pos.y * target.z - pos.z * target.y,
		pos.z * target.x - pos.x * target.z,
		pos.x * target.y - pos.y * target.x);
}

float Lange(VECTOR normal, VECTOR temp)
{
	float size = VSize(normal);

	return (normal.x * temp.x + normal.y * temp.y + normal.z * temp.z) / size;
}


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// ����ʂɕ`����s��
	SetDrawScreen(DX_SCREEN_BACK);

	SetCameraNearFar(100.0f, 1.0f);
	SetCameraPositionAndTarget_UpVecY(VGet(0, 8, -20), VGet(0, 0, 0));


	int lightHandle = CreatePointLightHandle(VGet(0, 8, -20), 10000, 0.0f, 0.002f, 0.0f);
	SetLightPositionHandle(lightHandle, VGet(0, 8, -20));


	float lange = 0;

	// �ړ����Ȃ��W���J�v�Z�����W�Ɛ����x�N�g��
	VECTOR targetPos_End = VGet(3, 1, 10);
	VECTOR targetPos_Start = VGet(-3,-1, 10);
	VECTOR targetVec = VSub(targetPos_End, targetPos_Start);

	// ���̍��W
	VECTOR movePos = VGet(12, 0,10);

	float r = 3.0f;

	bool isMove = false;

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// �t���[���J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A�ɂ���
		ClearDrawScreen();

		// �Q�[���̏���

		// �ړ�
		if (!isMove)
		{
			movePos.x -= 0.3f;
		}
		else
		{
			movePos.x += 0.3f;
		}

		if (movePos.x > 15.0f)
		{
			isMove = false;
		}
		if (movePos.x < -15.0f)
		{
			isMove = true;
		}


		// �����蔻��v�Z
		VECTOR Cap1ToSph = VSub(movePos, targetPos_Start);
		VECTOR Cap1ToCap2 = VSub(targetPos_End, targetPos_Start);
		VECTOR normal = VNorm(Cap1ToCap2);
		float s = VDot(Cap1ToSph, normal);
		// ������J�v�Z���ւ̐���ŋߓ_
		VECTOR point = VGet(targetPos_Start.x + (normal.x * s), targetPos_Start.y + (normal.y * s), targetPos_Start.z + (normal.z * s));

		float temp = VSize(VSub(point, targetPos_Start)) / VSize(VSub(targetPos_End, targetPos_Start));

		float distance;


		if (temp < 0) // ������J�v�Z�������ɐ��������낹���AtargetPos_Start�ɋ߂��ꏊ
		{
			distance = VSize(VSub(point, targetPos_Start));
		}
		else if (temp > 1) // ������J�v�Z�������ɐ��������낹���AtargetPos_End�ɋ߂��ꏊ
		{
			distance = VSize(VSub(point, targetPos_End));
		}
		else // ������J�v�Z�������ɐ��������낹��
		{
			distance = VSize(VSub(point, movePos));
		}



		// �`��
		// �J�v�Z���`��
		DrawCapsule3D(targetPos_Start, targetPos_End, r, 32, 0xffffff,0xffffff,true);
		// ���`��
		if (distance < r * 2) // �������Ă���Ƃ�
		{
			DrawSphere3D(movePos, r, 32, 0xff0000, 0xff0000, true);
		}
		else // �������Ă��Ȃ��Ƃ�
		{
			DrawSphere3D(movePos, r, 32, 0xffffff, 0xff0000, true);
		}


		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		// esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS��60�ɌŒ�
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16,66�~���b(16667�}�C�N���b)�o�߂܂ő҂�
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}


