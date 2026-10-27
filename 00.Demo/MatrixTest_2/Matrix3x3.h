#pragma once
#include <array>

class Matrix3x3
{
public:
	/// <summary>
	/// デフォルトコンストラクタ(すべての成分に0が代入される)
	/// </summary>
	Matrix3x3();

	/// <summary>
	/// コンストラクタ(すべての成分に指定した値が入る)
	/// </summary>
	/// <param name="in"></param>
	Matrix3x3(float in);

	/// <summary>
	/// コンストラクタ(値を指定して代入することができる)
	/// </summary>
	/// <param name="inX0"></param>
	/// <param name="inX1"></param>
	/// <param name="inX2"></param>
	/// <param name="inY0"></param>
	/// <param name="inY1"></param>
	/// <param name="inY2"></param>
	/// <param name="inZ0"></param>
	/// <param name="inZ1"></param>
	/// <param name="inZ2"></param>
	Matrix3x3(float inX0, float inY0, float inZ0, float inX1, float inY1, float inZ1, float inX2, float inY2, float inZ2);

	void DrawAll();

	Matrix3x3 operator+(Matrix3x3 val);
	Matrix3x3 operator-(Matrix3x3 val);

	float x0;
	float x1;
	float x2;

	float y0;
	float y1;
	float y2;
	
	float z0;
	float z1;
	float z2;

};

