#pragma once
#include "SceneFedo.h"
#include<memory>

class SceneBase : public std::enable_shared_from_this<SceneBase>
{
public:
	SceneBase():
		SoundGame(0),
		SoundGoal(0),
		GameBack(0),
		TitleBack(0),
		GoalBack(0),
		Titlelogo(0)
	{}
	virtual ~SceneBase(){}

	//virtual�Ōp������Ăяo��

	virtual void Init() = 0;
	virtual std::shared_ptr<SceneBase> Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//�T�E���h�p�i�[�ϐ�
	int SoundGame, SoundGoal;

	//�V�[���̔w�i�摜�i�[�ϐ�
	int GameBack, TitleBack, GoalBack;

	//�^�C�g�����S�i�[�ϐ�
	int Titlelogo;

	//Scene�̃t�F�[�h���Ǘ�����|�C���^
	std::shared_ptr<SceneFedo> fedo = std::make_shared<SceneFedo>();
};

