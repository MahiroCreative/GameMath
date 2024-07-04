#include "SceneGame.h"
#include "SceneGoal.h"
#include "DxLib.h"

SceneGame::SceneGame()
{
}

SceneGame::~SceneGame()
{
	//���������
	DeleteSoundMem(SoundGame);
}

void SceneGame::Init()
{
	player->Init();

	camera->Init();

	map->Init();

	//�w�i�̉摜�ǂݍ���
	GameBack = LoadGraph("data/cloudy.png");

	//�w�iBGM�ǂݍ���
	SoundGame = LoadSoundMem("BGM�ESE/Garden_Farm.mp3");
}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	player->Update();

	camera->Update(*player);

	map->Update(*player);

	//�T�E���h�Đ�
	PlaySoundMem(SoundGame, DX_PLAYTYPE_LOOP, FALSE);

	//�S�[���V�[���ɑJ�ڂ���
	if (map->Goal == true)
	{
		return std::make_shared<SceneGoal>();
	}

	return shared_from_this();
}

void SceneGame::Draw()
{
	//�w�i��`��
	DrawGraph(0, 0, GameBack, false);

	map->Draw(*player);

	player->Draw();

	camera->Draw();
}

void SceneGame::End()
{
	//�ǂݍ��񂾉摜�f�[�^���
	DeleteGraph(GameBack);

	map->End();

	player->End();

	camera->End();
}
