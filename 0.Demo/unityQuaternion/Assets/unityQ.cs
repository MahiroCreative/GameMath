using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class unityQ : MonoBehaviour
{
    float _angle;
    Vector3 _axis;
    Quaternion q;

    private void Start()
    {
        //�p���x[/s]
        _angle = 2 * Mathf.PI * 0.1f;//36�x

        //��]���̍쐬
        _axis = new Vector3(1,1,1);

        //_axis��������e���x_angle�ŉ�]�����]�N�H�[�^�j�I��
        //(�p���x��n���Ă���̂ŁA1�b�Ԃ�_angle��])
        q = Quaternion.AngleAxis(_angle,_axis);
    }

    private void FixedUpdate()
    {
        /*���W�ϊ�*/
        //[��]��̍��W] = [��]�N�I�[�^�j�I��]*[���݂̍��W]
        //�E�ӂ�[�N�I�[�^�j�I��]*[vector3]���s���Ă��邪�A
        //���ʂ�vector3�ɂȂ��Ă��鎖�ɒ���(�I�[�o�[���[�h�ł��̂悤�ɒ�`)�B
        transform.position = q * transform.position;
    }
}
