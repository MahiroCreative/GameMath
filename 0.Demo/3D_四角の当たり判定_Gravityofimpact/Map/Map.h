#pragma once
#include "DxLib.h"
#include "ObstructMap.h"
#include "Rect.h"
#include "Player/Player.h"

class Map
{
public:
	Map();
	virtual ~Map();

	virtual void Init();
	virtual void Update(Player& player);
	virtual void Draw(Player& player);
	virtual void End();

	//�}�b�v�I�u�W�F�N�g����
	ObstructMap* obustructmap1 = new ObstructMap();
	ObstructMap* obustructmap2 = new ObstructMap();
	ObstructMap* obustructmap3 = new ObstructMap();
	ObstructMap* obustructmap4 = new ObstructMap();
	ObstructMap* obustructmap5 = new ObstructMap();
	ObstructMap* obustructmap6 = new ObstructMap();
	ObstructMap* obustructmap7 = new ObstructMap();
	ObstructMap* obustructmap8 = new ObstructMap();
	ObstructMap* obustructmap9 = new ObstructMap();
	ObstructMap* obustructmap10 = new ObstructMap();

	//Player�������Ȃ��Ȃ�܂ł̎���
	int NotMoveTime;

	//SE�Đ��p�g���K�[
	bool PlaySe;

	//SE�p�i�[�p�ϐ�
	int SE;

	//���̃}�b�v�Ƃ̋���
	float MapdistanceX, MapdistanceY, MapdistanceZ;

	//�}�b�v�̏����ʒu
	float MapX, MapY, MapZ;

	//�}�b�v�̓����蔻�蕝
	float MapWidth, MapHeight, MapDepth;

	//�V�[���J�ڂ����邽�߂̃g���K�[
	bool Goal;
	
	//�����蔻��
	Rect m_colrect;
	Rect m_colrect2;
	Rect m_colrect3;
	Rect m_colrect4;
	Rect m_colrect5;
	Rect m_colrect6;
	Rect m_colrect7;
	Rect m_colrect8;
	Rect m_colrect9;
	Rect m_colrect10;
};

