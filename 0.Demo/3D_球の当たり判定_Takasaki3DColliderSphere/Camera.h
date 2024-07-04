#pragma once

#include "DxLib.h"

class Player;

class Camera
{
public:
	Camera();							// �R���X�g���N�^.
	~Camera();							// �f�X�g���N�^.

	void Update();	// �X�V.

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }

private:
	VECTOR	pos;			// �|�W�V����.

	float cameraAngle = -DX_PI_F / 2;

};