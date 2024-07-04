#include "DxLib.h"
#include<memory>
#include "Scene/SceneManager.h"
#include "GraphMode.h"
#include "icon/icon.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	//Window�̖��O��ύX����
	SetWindowText("Gravity Impact");

	SetWindowIconID(IDI_ICON1);              //�A�C�R����ݒ�


	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//�V�[�����Ǘ�����|�C���^
	std::shared_ptr<SceneManager> pScene = std::make_shared<SceneManager>();

	std::shared_ptr<GraphMode> graph = std::make_shared<GraphMode>();

	SetWindowSize(graph->GraphModeWIDTH, graph->GraphModeHEIGHT);

	pScene->Init();

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���
		pScene->Update();

		//�Q�[���̕`��
		pScene->Draw();


		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		// esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}
	}
	pScene->End();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}