#include "DxLib.h"
#include<memory>
#include "Scene/SceneManager.h"
#include "GraphMode.h"
#include "icon/icon.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	//Windowの名前を変更する
	SetWindowText("Gravity Impact");

	SetWindowIconID(IDI_ICON1);              //アイコンを設定


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//シーンを管理するポインタ
	std::shared_ptr<SceneManager> pScene = std::make_shared<SceneManager>();

	std::shared_ptr<GraphMode> graph = std::make_shared<GraphMode>();

	SetWindowSize(graph->GraphModeWIDTH, graph->GraphModeHEIGHT);

	pScene->Init();

	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理
		pScene->Update();

		//ゲームの描画
		pScene->Draw();


		// 画面が切り替わるのを待つ
		ScreenFlip();

		// escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60に固定する
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66ミリ秒(16667マイクロ秒)経過するまで待つ
		}
	}
	pScene->End();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}