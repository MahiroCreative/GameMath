#include <DxLib.h>
#include <cassert>
#include "Application.h"
#include "SceneManager.h"
#include "GamePlayingScene.h"
#include "GameOverScene.h"
#include"Game.h"
#include"TitleScene.h"
#include"Pad.h"
#include"ClearScene.h"
#include"WorldTimer.h"

#include"GameManager.h"

namespace
{
	constexpr int kFadeFrameMax = 60;
	constexpr int kStandByFrame = 120;

	constexpr int kLightningFrameMax = 200;
}

GamePlayingScene::GamePlayingScene(SceneManager& manager) :
	Scene(manager),
	m_gameManager(make_shared<GameManager>())
{
	m_updateFunc = &GamePlayingScene::FadeInUpdate;
	m_drawFunc = &GamePlayingScene::FadeDraw;
}

GamePlayingScene::~GamePlayingScene()
{
}

void GamePlayingScene::Update()
{

	(this->*m_updateFunc)();


	Pad::Update();
}

void GamePlayingScene::Draw()
{

	(this->*m_drawFunc)();

	if (m_isTitle) {
		ChangeScene(std::make_shared<TitleScene>(m_manager));
	}
	else if (m_isContinue) {
		ChangeScene(std::make_shared<GamePlayingScene>(m_manager));
	}
	else if (m_isGameOver) {
		ChangeScene(std::make_shared<GameOverScene>(m_manager));

		WorldTimer::Reset();
	}
	else if (m_isClear)
	{
		ChangeScene(std::make_shared<ClearScene>(m_manager));

		WorldTimer::Reset();
	}
}

void GamePlayingScene::FadeInUpdate()
{
	m_fps = GetFPS();
	m_gameManager->Update();
	m_frame--;
	if (m_frame <= 0)
	{
		m_updateFunc = &GamePlayingScene::NormalUpdate;
		m_drawFunc = &GamePlayingScene::NormalDraw;
	}
}

void GamePlayingScene::NormalUpdate()
{
	m_fps = GetFPS();
	m_btnFrame++;
	m_gameManager->Update();

	m_isGameOver = m_gameManager->GetGameOver();
	m_isClear = m_gameManager->GetClear();
}

void GamePlayingScene::FadeOutUpdate()
{

	m_fps = GetFPS();
	m_frame++;
	m_gameManager->Update();
}

void GamePlayingScene::ChangeScene(std::shared_ptr<Scene> nextScene)
{
	m_manager.ChangeScene(nextScene);
}

void GamePlayingScene::FadeDraw()
{
	m_gameManager->Draw();
	DrawString(10, 100, "GamePlayingScene", 0xffffff);
	int alpha = static_cast<int>(255 * (static_cast<float>(m_frame) / kFadeFrameMax));
	SetDrawBlendMode(DX_BLENDMODE_MULA, alpha);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void GamePlayingScene::NormalDraw()
{
	m_gameManager->Draw();
	DrawString(10, 100, "GamePlayingScene", 0xffffff);
	//DrawFormatString(10, 10, 0xffffff, "fps = %2.2f", m_fps);
}
