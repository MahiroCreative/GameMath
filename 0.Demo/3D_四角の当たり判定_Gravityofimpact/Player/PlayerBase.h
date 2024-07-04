#pragma once
#include "DxLib.h"
#include<memory>

class PlayerBase
{
public:
	PlayerBase():
		PlayerSpeed(0.0f),
		PlayerGraph(0),
		PlayerMoveFlag(true),
		PlayerX(0.0f),
		PlayerY(0.0f),
		PlayerZ(0.0f)
	{}
	virtual ~PlayerBase(){}

	//virtual�Ōp������Ăяo��

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//Player�̃X�s�[�h
	float PlayerSpeed;
	//Player��3D���f���n���h��
	int PlayerGraph;

	//Player��������t���O
	bool PlayerMoveFlag;

	//Player��X,Y,Z���W
	float PlayerX, PlayerY, PlayerZ;
};

