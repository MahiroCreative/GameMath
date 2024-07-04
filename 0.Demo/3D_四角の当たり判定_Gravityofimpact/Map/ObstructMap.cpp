#include "ObstructMap.h"

ObstructMap::ObstructMap()
{
	//3D���f���̓ǂݍ���
	modelHandle = MV1LoadModel("data/MapCube.mv1");
	if (modelHandle < 0)
	{
		printfDx("ObstructMap�f�[�^�ǂݍ��ݎ��s");
	}

	//Map�̑傫���ݒ�
	float MapScale = 12.0f;

	//Map�̑傫����ς���
	MV1SetScale(modelHandle, VGet(MapScale, MapScale, MapScale));

	pos = VGet(0, 0, 0);
}

ObstructMap::~ObstructMap()
{
	//���f���̃A�����[�h
	MV1DeleteModel(modelHandle);
}

void ObstructMap::Update()
{
	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);
}

void ObstructMap::Draw()
{
	//3D���f���̕`��
	MV1DrawModel(modelHandle);
}
