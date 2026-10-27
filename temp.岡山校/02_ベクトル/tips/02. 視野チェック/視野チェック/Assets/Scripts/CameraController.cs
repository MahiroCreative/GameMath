using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour
{
    // ターゲット
    [SerializeField]
    private GameObject _target;

    private Vector3 _targetPrevPos;

    // Start is called before the first frame update
    void Start()
    {
        _target = GameObject.Find("Player");
        if (_target == null)
        {
            Debug.Break();
            //Assert(_target != null);
        }

        _targetPrevPos = _target.transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        // 移動
        transform.position += _target.transform.position - _targetPrevPos;

        // ターゲット方向を見る
        transform.LookAt(_target.transform, Vector3.up);

        // ターゲットの前回ポジション
        _targetPrevPos = _target.transform.position;
    }
}
