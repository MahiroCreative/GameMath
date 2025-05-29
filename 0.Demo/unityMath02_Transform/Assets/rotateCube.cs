using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class rotateCube : MonoBehaviour
{
    Vector3 v3Position;
    Matrix4x4 matTransform;
    GameObject target;


    // Start is called before the first frame update
    void Start()
    {
        target = GameObject.Find("Sphere");

        v3Position = transform.position;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        Vector3 v3Side, v3Up, v3Forward;

        /*�ϊ��x�N�g���̍쐬*/
        /*�ϊ��p��z���̍쐬*/
        //�e������ꏊ�����ʂł���B
        //���ʂƂ́Az���Ȃ̂ŁB���_����e����������Ɍ������x�N�g����z���ł�B
        //�Ȃ̂ŁA�e�̏ꏊ�܂ł̃x�N�g�����o���āA�����P�ʃx�N�g���ɂ��Ă���B
        v3Forward = Vector3.Normalize(target.transform.position);

        /*�ϊ��p��x���̍쐬*/
        //���̏����
        v3Up = new Vector3(0.0f, 0.0f, 1.0f);
        //��L��z���̊O�ς�z���Ɛ����ȃx�N�g�����o��
        v3Side = Vector3.Cross(v3Up, v3Forward);
        //������m�[�}���C�Y���āAx�������̃x�N�g���쐬
        v3Side = Vector3.Normalize(v3Side);

        /*�ϊ��p��y���̍쐬*/
        v3Up = Vector3.Cross(v3Forward, v3Side);

        /*�ϊ��s��̍쐬*/
        // �P�ʍs��
        matTransform = Matrix4x4.identity;
        // ��]�̍s��
        //z���̊��x�N�g���̑}��
        matTransform.m02 = v3Forward.x;
        matTransform.m12 = v3Forward.y;
        matTransform.m22 = v3Forward.z;
        //x���̊��x�N�g���̑}��
        matTransform.m00 = v3Side.x;
        matTransform.m10 = v3Side.y;
        matTransform.m20 = v3Side.z;
        //y���̊��x�N�g���̑}��
        matTransform.m01 = v3Up.x;
        matTransform.m11 = v3Up.y;
        matTransform.m21 = v3Up.z;

        /*�s��ϊ�*/
        transform.position = matTransform * v3Position;

        //�p�x���^�[�Q�b�g�Ɍ����āA�F��ς��Ă���
        transform.LookAt(target.transform.position, new Vector3(0.0f, 0.0f, 1.0f));
    }
}
