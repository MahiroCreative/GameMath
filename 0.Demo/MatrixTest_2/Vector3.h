#pragma once
#include "DxLib.h"

class Vector3
{
public:
	Vector3();
	Vector3(float inX, float inY, float inZ);

	float x;
	float y;
	float z;

	VECTOR ToDxLibVector() const;

};

