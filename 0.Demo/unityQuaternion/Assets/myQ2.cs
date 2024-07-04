using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class myQ2 : MonoBehaviour
{
    float _angle;
    Vector3 _axis, _vPos;
    Quaternion qPos, qRot;

    // Start is called before the first frame update
    void Start()
    {
        //��]�p�x(�p���x�łȂ����Ƃɒ���)
        _angle = 2 * Mathf.PI * 0.002f;//0.72�x

        //��]���̍쐬
        _axis = new Vector3(1, 1, 1);

        //��]����P�ʍs��ɒ���(���K������)
        _axis.Normalize();

        //��]�N�H�[�^�j�I���̍쐬
        //(w:���� , ijk:���� �Ƃ���)
        //n: ijk����̒P�ʃx�N�g��(���ƂȂ�x�N�g��)
        //q = w cos(��/2) + n sin(��/2)
        qRot.w = Mathf.Cos(_angle / 2.0f);//����
        qRot.x = _axis.x * Mathf.Sin(_angle / 2.0f);
        qRot.y = _axis.y * Mathf.Sin(_angle / 2.0f);
        qRot.z = _axis.z * Mathf.Sin(_angle / 2.0f);
    }

    // Update is called once per frame
    private void FixedUpdate()
    {
        /*���W�ϊ�*/
        //transform.position = q * transform.position;
        //��L�̌v�Z���I�[�o�[���[�h�ɗ��炸�Ɍv�Z����B

        //���݂̍��W���擾
        _vPos = transform.position;
        
        //�R�������W���N�I�[�^�j�I���ɕϊ�
        qPos.w = 1.0f;//������1�ɂ���Ή�]���Ȃ��B
        qPos.x = _vPos.x;
        qPos.y = _vPos.y;
        qPos.z = _vPos.z;

        //��]��̃N�I�[�^�j�I���̍쐬
        //[��]��̃N�I�[�^�j�I��] =
        //[��]�N�I�[�^�j�I��] * [���݂̃N�I�[�^�j�I��] * [��]�N�I�[�^�j�I���̃C���o�[�X]
        qPos = qRot * qPos * Quaternion.Inverse(qRot);

        //�R�������W�ɖ߂�
        _vPos.x = qPos.x;
        _vPos.y = qPos.y;
        _vPos.z = qPos.z;

        //���W�ϊ�
        transform.position = _vPos;
    }
}
