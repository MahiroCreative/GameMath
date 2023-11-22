using UnityEngine;
using UnityEngine.UI;

/*DotPos1:�_�ƍ��W*/
//�y���z
// �I�u�W�F�N�g�̍��W�ƌ��_����̒���(����)��\������B
// �������A�X�N���v�g�̃A�^�b�`�́wDotPosManager�x�݂̂ɍs�����ƁB
//�y�𓚕��j�z
//�E�I�u�W�F�N�g�̍��W���擾
//�E���_����̒������v�Z
//�E�e�L�X�g�ɍ��W�ƌ��_����̒�����\��

public class DotAndPos1 : MonoBehaviour
{
    GameObject _posText, _circle;
    Vector3 _position;
    string _text;
    float _length;

    void Start()
    {
        //�I�u�W�F�N�g�̎擾
        _circle = GameObject.Find("Circle");

        //�����e�L�X�g�̎擾
        _posText = GameObject.Find("posText");
    }

    void Update()
    {
        //���W�̎擾
        _position = _circle.transform.position;

        //���_����̒����̎擾
        _length = _circle.transform.position.magnitude;

        //�����e�L�X�g�̍X�V
        _text = $"positon:{_position}\n";
        _text += $"length:{_length}";
        _posText.GetComponent<Text>().text = _text ;
    }

}
