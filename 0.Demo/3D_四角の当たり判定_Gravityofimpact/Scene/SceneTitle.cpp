#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneGame.h"

SceneTitle::SceneTitle()
{
}

SceneTitle::~SceneTitle()
{
	//������������
	DeleteGraph(TitleBack);
	DeleteGraph(Titlelogo);
	DeleteSoundMem(SoundGame);
}

void SceneTitle::Init()
{
	fedo->Init();

	//�w�iBGM�ǂݍ���
	SoundGame = LoadSoundMem("BGM�ESE/Garden_Farm.mp3");

	//�w�i�摜�ǂݍ���
	TitleBack = LoadGraph("data/cloudy.png");

	//�^�C�g�����S��ǂݍ���
	Titlelogo = LoadGraph("data/GravityImpact���S.png");
}

std::shared_ptr<SceneBase> SceneTitle::Update()
{
	//�t�F�[�h�J�n
	fedo->Update();

	//�T�E���h�Đ�
	PlaySoundMem(SoundGame, DX_PLAYTYPE_LOOP, FALSE);

	//���͂ŃV�[���J��
	if (fedo->Start >= 255)
	{
		if (CheckHitKeyAll())
		{
			return std::make_shared<SceneGame>();
		}
	}
	

	return shared_from_this();  //���g�̃|�C���^��Ԃ�
}

void SceneTitle::Draw()
{
	fedo->Draw();

	DrawGraph(0, 0, TitleBack, false);

	//�^�C�g�����S�̏����ʒu
	int Titlelogox, Titlelogoy;

	Titlelogox = 0;
	Titlelogoy = -100;

	DrawString(205, 300, "Push Any Button", GetColor(255, 255, 255));

	//�^�C�g�����S������
	DrawGraph(Titlelogox, Titlelogoy, Titlelogo, true);
}

void SceneTitle::End()
{
}
