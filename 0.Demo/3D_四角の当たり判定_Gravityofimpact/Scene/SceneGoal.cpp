#include "SceneGoal.h"
#include "SceneTitle.h"
#include "DxLib.h"

SceneGoal::SceneGoal():
	ClearGraph(0),
	Map(0),
	Player(0),
	MapX(0.0f),
	MapY(0.0f),
	MapZ(0.0f),
	PlayerX(0.0f),
	PlayerY(0.0f),
	PlayerZ(0.0f),
	SceneChange(false)
{
}

SceneGoal::~SceneGoal()
{
	//���������
	DeleteGraph(GoalBack);
	DeleteGraph(ClearGraph);
	DeleteSoundMem(SoundGoal);

}

void SceneGoal::Init()
{
	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);
	SetUseBackCulling(true);

	//���W�̏�����
	MapX = 0.0f;
	MapY = 50.0f;
	MapZ = 0.0f;
	PlayerX = 0.0f;
	PlayerY = 300.0f;
	PlayerZ = 5.0f;

	//�t�F�[�h�̏�����
	fedo->Init();

	//�w�iBGM�ǂݍ���
	SoundGoal = LoadSoundMem("BGM�ESE/�h���̃S�[��.mp3");

	//Clear�̉摜�ǂݍ���
	ClearGraph = LoadGraph("data/Clear.png");

	//�w�i�摜�ǂݍ���
	GoalBack = LoadGraph("data/cloudy.png");

	//3D���f���̓ǂݍ���
	Map = MV1LoadModel("data/MapCube.mv1");
	Player = MV1LoadModel("data/Sword.mv1");

	//Player�̑傫����ς���
	MV1SetScale(Player, VGet(0.05f, 0.05f, 0.05f));

	//Player�̏����ʒu
	PlayerPos = VGet(PlayerX, PlayerY, PlayerZ);

	//�|�W�V�����ݒ�
	MapPos = VGet(0.0f, 50.0f, 0.0f);

	//��ƂȂ�J�����̍��W
	cameraPos = VGet(0.0f, 100.0f, -30.0f);

	//�J�����̃^�[�Q�b�g���W������
	cameraTarget = VGet(0.0f, 5.0f, 0.0f);
}

std::shared_ptr<SceneBase> SceneGoal::Update()
{
	//�t�F�[�h���s��
	fedo->Update();

	//�T�E���h�Đ�
	PlaySoundMem(SoundGoal, DX_PLAYTYPE_LOOP, TRUE);

	//���͂ŃV�[���J��
	if (CheckHitKeyAll())
	{
		//�t�F�[�h�A�E�g���s��
		fedo->Fedo = true;

		SceneChange = true;
	}

	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(Map, MapPos);
	MV1SetPosition(Player, PlayerPos);

	if (PlayerPos.y >= 70.0f)
	{
		PlayerPos.y -= 5.0f;
	}

	//�����_�̍��W�̓^�[�Q�b�g�̏�����
	cameraTarget = VAdd(MapPos, VGet(0.0f, 50.0f, 0.0f));

	SetCameraPositionAndTarget_UpVecY(cameraPos, cameraTarget);

	//�V�[���J��
	if (fedo->Start <= 0 && SceneChange == true)
	{
		return std::make_shared<SceneTitle>();
	}

	return shared_from_this();  //���g�̃|�C���^��Ԃ�
}

void SceneGoal::Draw()
{
	//�w�i�摜�`��
	DrawGraph(0, 0, GoalBack, false);

	DrawGraph(0, 0, ClearGraph, true);

	//3D���f���`��
	MV1DrawModel(Map);
	MV1DrawModel(Player);

	//�t�F�[�h
	fedo->Draw();
}

void SceneGoal::End()
{
	//���������
	DeleteGraph(GoalBack);
	DeleteGraph(ClearGraph);
}
