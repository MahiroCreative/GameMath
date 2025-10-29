using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    // カメラオブジェクト
    [SerializeField]
    Camera _camera;

    // 移動スピード
    [SerializeField, Range(0.1f, 100.0f)]
    private float _speed = 8.0f;

    // 向きを変えるときの移動閾値
    [SerializeField, Range(0.01f, 1.0f)]
    private float _diff_threshold = 0.01f;

    // 向きの回転スピード
    [SerializeField, Range(0.1f, 30.0f)]
    private float _rotateSpeed = 10.0f;

    // 前回のポジション
    private Vector3 _prevPos;

    // Start is called before the first frame update
    void Start()
    {
        _prevPos = transform.position;
        _camera = Camera.main;
        Debug.Assert(_camera != null);
    }

    // Update is called once per frame
    void Update()
    {
        // 移動
        float iv = Input.GetKey(KeyCode.UpArrow) ? 1.0f : Input.GetKey(KeyCode.DownArrow) ? -1.0f : Input.GetAxis("Vertical2");
        float ih = Input.GetKey(KeyCode.RightArrow) ? 1.0f : Input.GetKey(KeyCode.LeftArrow) ? -1.0f : Input.GetAxis("Horizontal2");

        Vector3 v = Vector3.Scale(_camera.transform.forward, new Vector3(1.0f, 0.0f, 1.0f)) * iv
            + Vector3.Scale(_camera.transform.right, new Vector3(1.0f, 0.0f, 1.0f)) * ih;

        transform.position += (_speed * Time.deltaTime) * v.normalized;

        // 移動量が閾値オーバーであれば向きを変える
        Vector3 diff = transform.position - _prevPos;
        if (diff.magnitude > _diff_threshold)
        {
            Quaternion rot = Quaternion.LookRotation(diff);
            transform.rotation = Quaternion.Slerp(transform.rotation, rot, _rotateSpeed * Time.deltaTime);
        }
        
        _prevPos = transform.position;
    }
}
