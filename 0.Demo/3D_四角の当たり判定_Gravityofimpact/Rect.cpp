#include "Rect.h"
#include<cassert>

Rect::Rect():
	X(0.0f),
	Y(0.0f),
	Z(0.0f),
	Xwidth(0.0f),
	Yheight(0.0f),
	Zdepth(0.0f)
{
	//����
	pos1 = VGet(0.0f, 0.0f, 0.0f);
	//����
	pos2 = VGet(0.0f, 0.0f, 0.0f);
	//�E��
	pos3 = VGet(0.0f, 0.0f, 0.0f);
	//�E��
	pos4 = VGet(0.0f, 0.0f, 0.0f);
	//���̍���
	pos5 = VGet(0.0f, 0.0f, 0.0f);
	//���̍���
	pos6 = VGet(0.0f, 0.0f, 0.0f);
	//���̉E��
	pos7 = VGet(0.0f, 0.0f, 0.0f);
	//���̉E��
	pos8 = VGet(0.0f, 0.0f, 0.0f);


}

Rect::~Rect()
{
}

void Rect::SetCenter(float x, float y, float z, float width, float height, float depth)
{
	//�������
	X = x;
	Y = y;
	Z = z;
	Xwidth = x + width;
	Yheight = y + height;
	Zdepth = z + depth;

	//������W
	pos1 = VGet(X, Y, Z);
	//�������W
	pos2 = VGet(X, Yheight, Z);
	//�E����W
	pos3 = VGet(Xwidth, Y, Z);
	//�E�����W
	pos4 = VGet(Xwidth, Yheight, Z);
	//���̍�����W
	pos5 = VGet(X, Y, Zdepth);
	//���̍������W
	pos6 = VGet(X, Yheight, Zdepth);
	//���̉E����W
	pos7 = VGet(Xwidth, Y, Zdepth);
	//���̉E�����W
	pos8 = VGet(Xwidth, Yheight, Zdepth);
}

bool Rect::IsCollision(const Rect& rect)
{
	//��Γ�����Ȃ��p�^�[���ȊO�͓������Ă���
	if (X > rect.Xwidth ) return false;
	if (Y > rect.Yheight) return false;
	if (Xwidth < rect.X ) return false;
	if (Yheight < rect.Y ) return false;
	if (Z < rect.Zdepth) return false;
	if (Zdepth > rect.Z) return false;

	//������Ȃ��p�^�[���ȊO�͓������Ă���
	return true;
}



void Rect::Draw(unsigned int color, bool isFill)
{
	//���ォ��E��
	DrawLine3D(pos1, pos3, color);
	//���ォ�獶��
	DrawLine3D(pos1, pos2, color);
	//���ォ����̍���
	DrawLine3D(pos1, pos5, color);
	//�E�ォ��E����
	DrawLine3D(pos3, pos4, color);
	//�E�ォ����̉E��
	DrawLine3D(pos3, pos7, color);
	//����������̍���
	DrawLine3D(pos2, pos6, color);
	//��������E��
	DrawLine3D(pos2, pos4, color);
	//�E��������̉E��
	DrawLine3D(pos4, pos8, color);
	//���̍��ォ����̉E��
	DrawLine3D(pos5, pos7, color);
	//���̍��ォ����̍���
	DrawLine3D(pos5, pos6, color);
	//���̉E��������̉E��
	DrawLine3D(pos8, pos7, color);
	//���̉E��������̍���
	DrawLine3D(pos8, pos6, color);
}
