#include "Matrix3x3.h"
#include "Dxlib.h"

Matrix3x3::Matrix3x3():
    m00(0.0f),m01(0.0f),m02(0.0f),
    m10(0.0f),m11(0.0f),m12(0.0f),
    m20(0.0f),m21(0.0f),m22(0.0f)
{
}

Matrix3x3::Matrix3x3(float m00, float m01,float m02, float m10, float m11, float m12, float m20, float m21, float m22)
{
}

void Matrix3x3::printfMat()
{
    printfDx("%.2f,%.2f,%.2f\n%.2f,%.2f,%.2f\n%.2f,%.2f,%.2f", m00, m01, m02, m10, m11, m12, m20, m21, m22);
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& mat) const
{
    Matrix3x3 ans;

    ans.m00 = m00 + mat.m00;
    ans.m01 = m01 + mat.m01;
    ans.m02 = m02 + mat.m02;

    ans.m10 = m10 + mat.m10;
    ans.m11 = m11 + mat.m11;
    ans.m12 = m12 + mat.m12;
    
    ans.m20 = m20 + mat.m20;
    ans.m21 = m21 + mat.m21;
    ans.m22 + m22 + mat.m22;

    return ans;
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& mat) const
{
    Matrix3x3 ans;

    ans.m00 = m00 - mat.m00;
    ans.m01 = m01 - mat.m01;
    ans.m02 = m02 - mat.m02;

    ans.m10 = m10 - mat.m10;
    ans.m11 = m11 - mat.m11;
    ans.m12 = m12 - mat.m12;

    ans.m20 = m20 - mat.m20;
    ans.m21 = m21 - mat.m21;
    ans.m22 - m22 - mat.m22;

    return ans;
}
