#include "Vector3.h"

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float inX, float inY, float inZ)
{
	x = inX;
	y = inY;
	z = inZ;
}

VECTOR Vector3::ToDxLibVector() const
{
	return VGet(x, y, z);
}
