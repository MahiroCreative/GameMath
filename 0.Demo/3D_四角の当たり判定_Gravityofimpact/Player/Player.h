#pragma once
#include "PlayerBase.h"
#include "Rect.h"

class Player : public PlayerBase
{
public:
	Player();
	virtual ~Player();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	//Player�̏d��
	float Playerweight;

	//Player�̏d��
	float PlayerGravity;

	//Plyaer�̃��X�|�[���l
	float PlayerRespawn;

	//Player�̃|�W�V����
	VECTOR Playerpos = VGet(0.0f, 10.0f, 0.0f);

	//Player�̃A���O��
	VECTOR PlayerAngle = VGet(0.0f, 0.0f, 0.0f);

	//�����蔻��
	Rect m_colrect;
};

