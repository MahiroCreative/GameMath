#pragma once
#include "Dxlib.h"

class Matrix4x4
{
public:
	Matrix4x4();
	Matrix4x4(float m00, float m01, float m02, float m03,
			  float m10, float m11, float m12, float m13,
			  float m20, float m21, float m22, float m23,
			  float m30, float m31, float m32, float m33);

	void printfMat() const;

	static Matrix4x4 GetRotXMatrix(float angle);
	static Matrix4x4 GetRotYMatrix(float angle);
	static Matrix4x4 GetRotZMatrix(float angle);

	MATRIX ConvertDxlibMatrix() const;

	float m00, m01, m02, m03,
		  m10, m11, m12, m13,
		  m20, m21, m22, m23,
		  m30, m31, m32, m33;

	Matrix4x4 operator*(Matrix4x4 m) const;
	void operator*=(Matrix4x4 m);

	VECTOR operator*(VECTOR v) const;
	void operator*=(VECTOR v);
};

