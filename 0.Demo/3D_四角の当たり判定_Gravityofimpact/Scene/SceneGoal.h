#pragma once
#include "SceneBase.h"

class SceneGoal : public SceneBase
{
public:
	SceneGoal();
	virtual ~SceneGoal();

	virtual void Init();
	virtual std::shared_ptr<SceneBase> Update();
	virtual void Draw();
	virtual void End();

private:
	//Clear�̉摜�i�[�ϐ�
	int ClearGraph;

	//3D�̃I�u�W�F�N�g
	int Map, Player;

	//3D�̍��W
	float MapX, MapY, MapZ;
	float PlayerX, PlayerY, PlayerZ;

	//�V�[���J�ڂ����邽�߂̃t���O
	bool SceneChange;

	//�J�����̃|�W�V����
	VECTOR cameraPos = VGet(0.0f, 0.0f, 0.0f);

	//�J�����̃^�[�Q�b�g
	VECTOR cameraTarget = VGet(0.0f, 0.0f, 0.0f);

	//���f���̃|�W�V����
	VECTOR MapPos = VGet(0.0f, 0.0f, 0.0f);
	VECTOR PlayerPos = VGet(0.0f, 0.0f, 0.0f);
};

