#pragma once
#define _OBSTRUCT_MAP_H_

#include "DxLib.h"

class ObstructMap
{
public:
	ObstructMap();   //�R���X�g���N�^
	virtual ~ObstructMap();   //�f�X�g���N�^

	void Update();    //�X�V
	void Draw();      //�`��

	//���f���n���h���̎擾
	int GetModelHandle() { return modelHandle; }

	//�|�W�V������getter/setter
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

private:
	int modelHandle;  //���f���n���h��
	VECTOR pos;       //�|�W�V����
};
