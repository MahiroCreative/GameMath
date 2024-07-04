#include "Player.h"
#include<math.h>
//�d�͉����x
#define GravitationalAcceleration 9.80665 / 2

#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player():
	PlayerGravity(0.0f),
	Playerweight(0.0f),
	PlayerRespawn(0.0f)
{
}

Player::~Player()
{
	MV1DeleteModel(PlayerGraph);
}

void Player::Init()
{
	//Player�̏������W
	PlayerX = 0.0f;
	PlayerY = 30.0f;
	PlayerZ = 0.0f;

	//Player�̏d��
	Playerweight = 1.0f;

	//Player�̏d��
	PlayerGravity = Playerweight * static_cast<float>(GravitationalAcceleration);

	//Player�̏����ʒu
	Playerpos = VGet(PlayerX, PlayerY, PlayerZ);

	//Player�̉�]��ԏ�����
	PlayerAngle = VGet(-1.55f, D2R(0.0f), 0.0f);

	//3D���f����ǂݍ���
	PlayerGraph = MV1LoadModel("data/Sword.mv1");

	//Player�̑傫����ς���
	MV1SetScale(PlayerGraph, VGet(0.05f, 0.05f, 0.05f));

	//Player�̃X�s�[�h�ݒ�
	PlayerSpeed = 1.0f;

	//Player�����X�|�[���ł���n�_
	PlayerRespawn = -7500.0f;

	//Player��������悤�ɏ�����
	PlayerMoveFlag = true;
}

void Player::Update()
{
	//Player�������t���O��True�Ȃ�
	if (PlayerMoveFlag == true)
	{
		//�O�ɐi��
		if (CheckHitKey(KEY_INPUT_W))
		{
			Playerpos.z += PlayerSpeed;

		}
		//���ɐi��
		if (CheckHitKey(KEY_INPUT_S))
		{
			Playerpos.z -= PlayerSpeed;

		}
		//�E�ɐi��
		if (CheckHitKey(KEY_INPUT_D))
		{
			Playerpos.x += PlayerSpeed;
		}
		//���ɐi��
		if (CheckHitKey(KEY_INPUT_A))
		{
			Playerpos.x -= PlayerSpeed;
		}
	}

	//Player�ɏd�͂�^��������
	Playerpos.y -= PlayerGravity;

	//Player�������������珉���ʒu�ɖ߂�
	if (Playerpos.y <= PlayerRespawn)
	{
		Playerpos.x = 0.0f;
		Playerpos.y = 30.0f;
		Playerpos.z = 0.0f;
	}

	m_colrect.SetCenter(Playerpos.x - static_cast<float>(5), Playerpos.y, Playerpos.z + static_cast<float>(5), 10.0f, 1.0f, -60.0f);
}

void Player::Draw()
{
	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(PlayerGraph, Playerpos);

	//3D���f���̉�]�n���Z�b�g����
	MV1SetRotationXYZ(PlayerGraph, PlayerAngle);

	//3D���f����`�悷��
	MV1DrawModel(PlayerGraph);
}

void Player::End()
{
}
