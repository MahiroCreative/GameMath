#include "Matrix3x3.h"
#include "DxLib.h"

Matrix3x3::Matrix3x3()
{
    x0 = 0.0f;
    x1 = 0.0f;
    x2 = 0.0f;

    y0 = 0.0f;
    y1 = 0.0f;
    y2 = 0.0f;
    
    z0 = 0.0f;
    z1 = 0.0f;
    z2 = 0.0f;
}

Matrix3x3::Matrix3x3(float in)
{
    x0 = in;
    x1 = in;
    x2 = in;

    y0 = in;
    y1 = in;
    y2 = in;

    z0 = in;
    z1 = in;
    z2 = in;
}

Matrix3x3::Matrix3x3(float inX0, float inY0, float inZ0, float inX1, float inY1, float inZ1, float inX2, float inY2, float inZ2)
{
    x0 = inX0;
    x1 = inX1;
    x2 = inX2;

    y0 = inY0;
    y1 = inY1;
    y2 = inY2;

    z0 = inZ0;
    z1 = inZ1;
    z2 = inZ2;
}

void Matrix3x3::DrawAll()
{
    DrawFormatString(0, 32, 0xffffff, "x0:%f, y0:%f, z0:%f", x0, y0, z0);
    DrawFormatString(0, 48, 0xffffff, "x1:%f, y1:%f, z1:%f", x1, y1, z1);
    DrawFormatString(0, 64, 0xffffff, "x2:%f, y2:%f, z2:%f", x2, y2, z2);
}

Matrix3x3 Matrix3x3::operator+(Matrix3x3 val)
{
    Matrix3x3 ret;

    ret.x0 = x0 + val.x0;
    ret.x1 = x1 + val.x1;
    ret.x2 = x2 + val.x2;
    
    ret.y0 = y0 + val.y0;
    ret.y1 = y1 + val.y1;
    ret.y2 = y2 + val.y2;
    
    ret.z0 = z0 + val.z0;
    ret.z1 = z1 + val.z1;
    ret.z2 = z2 + val.z2;
    
    return ret;
}

Matrix3x3 Matrix3x3::operator-(Matrix3x3 val)
{
    Matrix3x3 ret;

    ret.x0 = x0 - val.x0;
    ret.x1 = x1 - val.x1;
    ret.x2 = x2 - val.x2;
                
    ret.y0 = y0 - val.y0;
    ret.y1 = y1 - val.y1;
    ret.y2 = y2 - val.y2;
                
    ret.z0 = z0 - val.z0;
    ret.z1 = z1 - val.z1;
    ret.z2 = z2 - val.z2;

    return ret;
}
