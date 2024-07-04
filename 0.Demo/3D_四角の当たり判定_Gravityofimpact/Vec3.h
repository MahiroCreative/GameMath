#pragma once
#include<cmath>
//3�����̃x�N�g����֗��Ɏg�����߂̃N���X
class Vec3
{
public:
	float x, y, z;

	Vec3():
		x(0.0f),
		y(0.0f),
		z(0.0f)
	{}

	Vec3(float posX, float posY, float posZ):
		x(posX),
		y(posY),
		z(posZ)
	{}

	//�P�����Z�q+ Vec3 = +Vec3
	Vec3 operator+() const
	{
		return *this;
	}

	//�P�����Z�q- Vec3 = -Vec3
	Vec3 operator-() const
	{
		return Vec3{-x,-y,-z};
	}

	//�����Z
	Vec3 operator+(Vec3 vec) const
	{
		return Vec3{ x + vec.x,y + vec.y,z + vec.z };
	}

	//Vec3 += Vec3
	Vec3 operator+=(Vec3 vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}

	//�����Z
	Vec3 operator-(Vec3 vec) const
	{
		return Vec3{ x - vec.x, y - vec.y, z - vec.z };
	}

	//Vec3 -= Vec3
	Vec3 operator-=(Vec3 vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		return *this;
	}

	//�|���Z
	Vec3 operator*(Vec3 vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		return *this;
	}

	//Vec3 *= float
	Vec3 operator*=(float scale)
	{
		x *= scale;
		y *= scale;
		z *= scale;
		return *this;
	}

	//����Z
	Vec3 operator/(float scale) const
	{
		return Vec3{ x / scale,y / scale,z / scale };
	}

	//Vec3 /= float
	Vec3 operator/=(float scale)
	{
		x /= scale;
		y /= scale;
		z /= scale;
		return *this;
	}

	//�x�N�g���̒�����2������߂�
	float sqLength() const
	{
		return x * x + y * y + z * z;
	}

	//�x�N�g���̒��������߂�
	float length() const
	{
		return sqrtf(sqLength());
	}

	//���M�̐��K�����s��
	void normalize()
	{
		float len = length();
		if (len > 0.0f)
		{
			x /= len;
			y /= len;
			z /= len;
		}
		//����0�̏ꍇ�͉������Ȃ�
	}

	//���M�𐳋K�������x�N�g�����擾����
	Vec3 getNormalize() const
	{
		float len = length();
		if (len > 0.0f)
		{
			return Vec3{ x / len, y / len, z / len };
			//����0�̏ꍇ
			return Vec3{ 0.0f,0.0f,0.0f };
		}
	}
};

