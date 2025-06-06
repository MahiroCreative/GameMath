#include "SceneGame.h"
#include "SceneGoal.h"
#include "DxLib.h"

SceneGame::SceneGame()
{
}

SceneGame::~SceneGame()
{
	//メモリ解放
	DeleteSoundMem(SoundGame);
}

void SceneGame::Init()
{
	player->Init();

	camera->Init();

	map->Init();

	//背景の画像読み込み
	GameBack = LoadGraph("data/cloudy.png");

	//背景BGM読み込み
	SoundGame = LoadSoundMem("BGM・SE/Garden_Farm.mp3");
}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	player->Update();

	camera->Update(*player);

	map->Update(*player);

	//サウンド再生
	PlaySoundMem(SoundGame, DX_PLAYTYPE_LOOP, FALSE);

	//ゴールシーンに遷移する
	if (map->Goal == true)
	{
		return std::make_shared<SceneGoal>();
	}

	return shared_from_this();
}

void SceneGame::Draw()
{
	//背景を描画
	DrawGraph(0, 0, GameBack, false);

	map->Draw(*player);

	player->Draw();

	camera->Draw();
}

void SceneGame::End()
{
	//読み込んだ画像データ解放
	DeleteGraph(GameBack);

	map->End();

	player->End();

	camera->End();
}
