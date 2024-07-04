#include "Map.h"
// �d�͉����x
#define GravitationalAcceleration 9.80665 / 2

Map::Map():
	NotMoveTime(0),
	SE(0),
	PlaySe(true),
	MapX(0.0f),
	MapY(0.0f),
	MapZ(0.0f),
	MapdistanceX(0.0f),
	MapdistanceY(0.0f),
	MapdistanceZ(0.0f),
	MapWidth(0.0f),
	MapHeight(0.0f),
	MapDepth(0.0f),
	Goal(false)
{
	
}

Map::~Map()
{
	//���������
	DeleteSoundMem(SE);
}

void Map::Init()
{
	//Map�̏������W���
	MapX = 0.0f;
	MapY = -478.0f;
	MapZ = 0.0f;

	//Map�̋K���I����
	MapdistanceX = 500.0f;
	MapdistanceY = 800.0f;
	MapdistanceZ = 500.0f;

	//Map�̓����蔻��̑傫��
	MapWidth = 450.0f;
	MapHeight = 220.0f;
	MapDepth = -450.0f;

	//SE�ǂݍ���
	SE = LoadSoundMem("BGM�ESE/���{�b�g������1.mp3");

	//�}�b�v�̈ʒu��������
	obustructmap1->SetPos(VGet(MapX, MapY, MapZ));
	obustructmap2->SetPos(VGet(MapX, MapY - MapdistanceY, MapZ + MapdistanceZ));
	obustructmap3->SetPos(VGet(MapX, MapY - MapdistanceY * 2, MapZ));
	obustructmap4->SetPos(VGet(MapX - MapdistanceX, MapY - MapdistanceY * 3, MapZ));
	obustructmap5->SetPos(VGet(MapX - MapdistanceX, MapY - MapdistanceY * 4, MapZ - MapdistanceZ));
	obustructmap6->SetPos(VGet(MapX, MapY - MapdistanceY * 5, MapZ - MapdistanceZ));
	obustructmap7->SetPos(VGet(MapX, MapY - MapdistanceY * 6, MapZ));
	obustructmap8->SetPos(VGet(MapX + MapdistanceX, MapY - MapdistanceY * 7, MapZ));
	obustructmap9->SetPos(VGet(MapX, MapY - MapdistanceY * 8, MapZ));
	obustructmap10->SetPos(VGet(MapX, MapY - MapdistanceY * 9, MapZ - MapdistanceZ));
}

void Map::Update(Player& player)
{
	

	//�}�b�v�̓����蔻����Ƃ�
	m_colrect.SetCenter(-230.0f, -220.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect2.SetCenter(-230.0f, -1023.0f, 720.0f, MapWidth, MapHeight, MapDepth);
	m_colrect3.SetCenter(-230.0f, -1822.5f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect4.SetCenter(-730.0f, -2623.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect5.SetCenter(-730.0f, -3423.0f, -280.0f, MapWidth, MapHeight, MapDepth);
	m_colrect6.SetCenter(-230.0f, -4223.0f, -280.0f, MapWidth, MapHeight, MapDepth);
	m_colrect7.SetCenter(-230.0f, -5023.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect8.SetCenter(270.0f, -5823.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect9.SetCenter(-230.0f, -6623.0f, 220.0f, MapWidth, MapHeight, MapDepth);
	m_colrect10.SetCenter(-230.0f, -7422.0f, -280.0f, MapWidth, MapHeight, MapDepth);


	//��Q������
	obustructmap1->Update();
	obustructmap2->Update();
	obustructmap3->Update();
	obustructmap4->Update();
	obustructmap5->Update();
	obustructmap6->Update();
	obustructmap7->Update();
	obustructmap8->Update();
	obustructmap9->Update();
	obustructmap10->Update();

	//�v���C���[�ɓ������Ă����
	if (m_colrect.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect2.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect3.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect4.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect5.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect6.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect7.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect8.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	else if (m_colrect9.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}
	}
	//�S�[��
	else if (m_colrect10.IsCollision(player.m_colrect) == true)
	{
		player.PlayerGravity = 0.0f;
		player.PlayerMoveFlag = true;

		NotMoveTime = 0;

		//SE�𗬂�
		if (PlaySe == false)
		{
			PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);

			PlaySe = true;
		}

		Goal = true;
	}
	//�v���C���[�ɓ������ĂȂ���
	else if (m_colrect.IsCollision(player.m_colrect) == false || m_colrect2.IsCollision(player.m_colrect) == false)
	{
		player.PlayerGravity = player.Playerweight * static_cast<float>(GravitationalAcceleration);

		NotMoveTime++;

		if (NotMoveTime >= 50)
		{
			player.PlayerMoveFlag = false;
		}
		

		//SE����悤�ɂ���
		PlaySe = false;
	}
	
}

void Map::Draw(Player& player)
{

	//��Q���`��
	obustructmap1->Draw();
	obustructmap2->Draw();
	obustructmap3->Draw();
	obustructmap4->Draw();
	obustructmap5->Draw();
	obustructmap6->Draw();
	obustructmap7->Draw();
	obustructmap8->Draw();
	obustructmap9->Draw();
	obustructmap10->Draw();
}

void Map::End()
{
	//���f���̃A�����[�h
	obustructmap1->~ObstructMap();
	obustructmap2->~ObstructMap();
	obustructmap3->~ObstructMap();
	obustructmap4->~ObstructMap();
	obustructmap5->~ObstructMap();
	obustructmap6->~ObstructMap();
	obustructmap7->~ObstructMap();
	obustructmap8->~ObstructMap();
	obustructmap9->~ObstructMap();
	obustructmap10->~ObstructMap();

}
