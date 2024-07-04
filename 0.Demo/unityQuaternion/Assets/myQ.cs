using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class myQ : MonoBehaviour
{
    float _angle;
    Vector3 _axis;
    Quaternion q;

    // Start is called before the first frame update
    void Start()
    {
        //��]�p�x(�p���x�łȂ����Ƃɒ���)
        _angle = 2 * Mathf.PI * 0.002f;//0.72�x

        //��]���̍쐬
        _axis = new Vector3(-1, 1, 1);

        //��]����P�ʃx�N�g���ɒ���(���K������)
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

    // Update is called once per frame
    private void FixedUpdate()
    {
        /*���W�ϊ�*/
        //(1frame����_angle��])
        transform.position = q * transform.position;
    }
}
