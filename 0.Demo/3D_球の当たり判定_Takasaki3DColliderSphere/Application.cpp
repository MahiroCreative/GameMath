#include "Application.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include<iostream>
#include<vector>
#include"Game.h"
#include <DxLib.h>
#include <cassert>

#include"WorldTimer.h"

namespace
{
    constexpr int kScreenWidth = 1600;
    constexpr int kScreenHeight = 900;

    constexpr int kColorbitDepth = 32;
    constexpr int kIconID = 573;
}

using namespace std;

int MyLoadGraph(const TCHAR* path)
{
    int handle = LoadGraph(path);
    assert(handle != -1);
    return handle;
}

Application::Application()
{
    m_windowSize = Size{ kScreenWidth, kScreenHeight };
}

void Application::Terminate()
{
    DxLib_End();
}

int Application::GetScreenHandle()
{
    return m_screenHandle;
}

float Application::GetGravity() const
{
    return 0.5f;
}

bool Application::Init()
{
    ChangeWindowMode(true); // �E�B���h�E���[�h�ɂ��܂�
    //SetGraphMode(m_windowSize.w, m_windowSize.h, 1);
    SetWindowSizeChangeEnableFlag(TRUE, TRUE);
    SetChangeScreenModeGraphicsSystemResetFlag(false);


    SetGraphMode(kScreenWidth, kScreenHeight, kColorbitDepth);
    SetWindowSize(kScreenWidth, kScreenHeight);

    void* CallBack();


    DxLib_Init();

    SetWindowIconID(kIconID);

    SetUseASyncChangeWindowModeFunction(TRUE, NULL, NULL);

    SetWindowText("HotSpring");
    if (DxLib_Init() == -1)
    {
        return false;
    }


    SetDrawScreen(DX_SCREEN_BACK);
    return true;
}

void Application::Run()
{
    {// �X�R�[�v�������I�ɍ���Ă���

        SceneManager sceneManager;
        sceneManager.ChangeScene(std::make_shared<TitleScene>(sceneManager));


        m_screenHandle = MakeScreen(Game::kScreenWidth, Game::kScreenHeight, true);

        LONGLONG time;



        while (ProcessMessage() != -1)
        {
            // FPS�̌Œ�悤�ɊJ�n���̎��Ԃ��擾
            time = GetNowHiPerformanceCount();

            ClearDrawScreen();
            if (CheckHitKey(KEY_INPUT_ESCAPE))
            {
                ChangeWindowMode(true);
            }





            sceneManager.Update();
            sceneManager.Draw();




            ScreenFlip();

            // 60FPS�ɌŒ�
            while (16667 > GetNowHiPerformanceCount() - time) {};
        }
    }
    //Terminate();
    std::vector<VECTOR> num;

}



const Size& Application::GetWindowSize() const
{
    return m_windowSize;
}
