#pragma once
#include "DxLib.h"
class SceneFedo
{
public:
	SceneFedo();
	virtual ~SceneFedo();

	void Init();
	void Update();
	void Draw();
	void End();

	//�t�F�[�h�C��,�t�F�[�h�A�E�g�����邽�߂̕ϐ�
	int Start;

	//�t�F�[�h�C���A�t�F�[�h�A�E�g�J�n�����邽�߂̕ϐ�
	bool Fedo;
};

