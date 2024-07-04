using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static UnityEditor.PlayerSettings;

public class myQ3 : MonoBehaviour
{
    float _angle;
    Vector3 _axis;
    MyQuaternion q;

    // Start is called before the first frame update
    void Start()
    {
        //��]�p�x(�p���x�łȂ����Ƃɒ���)
        _angle = -2 * Mathf.PI * 0.002f;//0.72�x

        //��]���̍쐬
        _axis = new Vector3(1, 1, 1);

        //��]����P�ʍs��ɒ���(���K������)
        _axis.Normalize();

        //��]�N�H�[�^�j�I���̍쐬
        //(w:���� , ijk:���� �Ƃ���)
        //n: ijk����̒P�ʃx�N�g��(���ƂȂ�x�N�g��)
        //q = w cos(��/2) + n sin(��/2)
        q.w = Mathf.Cos(_angle / 2.0f);//����
        q.x = _axis.x * Mathf.Sin(_angle / 2.0f);
        q.y = _axis.y * Mathf.Sin(_angle / 2.0f);
        q.z = _axis.z * Mathf.Sin(_angle / 2.0f);
    }

    private void FixedUpdate()
    {
        /*���W�ϊ�*/
        transform.position = q * transform.position;
    }
}

/// <summary>
/// �y���[�U��`�z�N�I�[�^�j�I���^
/// </summary>
public struct MyQuaternion
{
    public float w, x, y, z;

    /*�R���X�g���N�^*/
    public MyQuaternion(float w, float x, float y, float z)
    {
        this.w = w;
        this.x = x;
        this.y = y;
        this.z = z;
    }

    /*���Z�q�I�[�o�[���[�h*/
    //MyQuaternion * MyQuaternion
    public static MyQuaternion operator *(MyQuaternion lQ, MyQuaternion rQ)
    {
        MyQuaternion tempQ;

        /*�N�I�[�^�j�I���̊|���Z*/
        //�����ʂ�ł��B
        tempQ.w = lQ.w * rQ.w - lQ.x * rQ.x - lQ.y * rQ.y - lQ.z * rQ.z;//����
        tempQ.x = lQ.w * rQ.x + lQ.x * rQ.w + lQ.y * rQ.z - lQ.z * rQ.y;//����x
        tempQ.y = lQ.w * rQ.y + lQ.y * rQ.w + lQ.z * rQ.x - lQ.x * rQ.z;//����y
        tempQ.z = lQ.w * rQ.z + lQ.z * rQ.w + lQ.x * rQ.y - lQ.y * rQ.x;//����z

        return tempQ;
    }
    //MyQuaternion * Vector3
    public static Vector3 operator *(MyQuaternion qRot, Vector3 right)
    {
        MyQuaternion qPos, qInv;
        Vector3 vPos;

        //3�������W���N�I�[�^�j�I���ɕϊ�
        qPos.w = 1.0f;
        qPos.x = right.x;
        qPos.y = right.y;
        qPos.z = right.z;

        //��]�N�H�[�^�j�I���̃C���o�[�X�̍쐬
        //�t�N�H�[�^�j�I�����o���̂͑�ςȂ̂ŁA
        //3�������Ɠ����l�ɂȂ鋤���N�I�[�^�j�I���ō쐬(���������}�C�i�X���])
        qInv = new MyQuaternion(qRot.w, -qRot.x, -qRot.y, -qRot.z);

        //��]��̃N�I�[�^�j�I���̍쐬
        qPos = qRot * qPos * qInv;

        //�R�������W�ɖ߂�
        vPos.x = qPos.x;
        vPos.y = qPos.y;
        vPos.z = qPos.z;

        return vPos;
    }
}