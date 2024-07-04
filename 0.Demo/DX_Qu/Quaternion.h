#pragma once
#include "DxLib.h"
#include <cmath>

class Quaternion
{
public:
	Quaternion()
	{
		Qu.w = 1;
		Qu.x = 0;
		Qu.y = 0;
		Qu.z = 0;
	};
	Quaternion(float _w,float _x,float _y,float _z) 
	{
		Qu.w = _w;
		Qu.x = _x;
		Qu.y = _y;
		Qu.z = _z;
	};
	virtual ~Quaternion(){}

private:
	struct Q
	{
		float w;
		float x;
		float y;
		float z;
		
		Q operator * (const Q& _q) const
		{
			Q tempQ;

			/*�N�I�[�^�j�I���̊|���Z*/
			//�����ʂ�ł��B
			tempQ.w = w * _q.w - x * _q.x - y * _q.y - z * _q.z;//����
			tempQ.x = w * _q.x + x * _q.w + y * _q.z - z * _q.y;//����x
			tempQ.y = w * _q.y + y * _q.w + z * _q.x - x * _q.z;//����y
			tempQ.z = w * _q.z + z * _q.w + x * _q.y - y * _q.x;//����z

			return tempQ;
		}
	};

	Q Qu;

public:

	

	void SetMove(float& _angle, VECTOR& _axis)
	{
		Qu.w = cos(_angle / 2.0f);//����
		Qu.x = _axis.x * sin(_angle / 2.0f);
		Qu.y = _axis.y * sin(_angle / 2.0f);
		Qu.z = _axis.z * sin(_angle / 2.0f);
	}

	VECTOR Move(VECTOR& _pos, VECTOR& _vec)
	{
		Q qPos, qInv;
		VECTOR vPos;

		//3�������W���N�I�[�^�j�I���ɕϊ�
		qPos.w = 1.0f;
		qPos.x = _pos.x;
		qPos.y = _pos.y;
		qPos.z = _pos.z;

		//��]�N�H�[�^�j�I���̃C���o�[�X�̍쐬
		//�t�N�H�[�^�j�I�����o���̂͑�ςȂ̂ŁA
		//3�������Ɠ����l�ɂȂ鋤���N�I�[�^�j�I���ō쐬(���������}�C�i�X���])
		qInv.w = Qu.w;
		qInv.x = -Qu.x;
		qInv.y = -Qu.y;
		qInv.z = -Qu.z;

		//��]��̃N�I�[�^�j�I���̍쐬
		qPos = Qu * qPos * qInv;

		//�R�������W�ɖ߂�
		vPos.x = qPos.x;
		vPos.y = qPos.y;
		vPos.z = qPos.z;

		// ��]��Ɉړ�
		vPos.x += _vec.x;
		vPos.y += _vec.y;
		vPos.z += _vec.z;

		return vPos;
	}
};

