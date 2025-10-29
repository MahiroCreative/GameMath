using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    // ターゲット
    [SerializeField]
    private GameObject _target;

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

    // 扇の角度（euler）
    [SerializeField, Range(0.01f, 359.99f)]
    private float _fanAngle = 150.0f;

    // 扇の半径
    [SerializeField, Range(1, 100)]
    private float _fanRadius = 10.0f;

    private float _sightThreshold;      // 視野角チェック用の内積値
    private bool _isFound = false;      // ターゲット検知フラグ

    // 扇の角度を取得（オイラー角）
    public float GetFanAngle()
    {
        return Mathf.Clamp((float)_fanAngle, 0.0f, 360);
    }

    // 扇の半径を取得
    public float GetFanRadius()
    {
        return Mathf.Max(0.0f, _fanRadius);
    }

    // 視野チェックフラグ取得
    public bool GetFindFlag()
    {
        return _isFound;
    }

    // Start is called before the first frame update
    void Start()
    {
         _isFound = false;
        _prevPos = transform.position;
        
        _target = GameObject.Find("Player");
        Debug.Assert(_target != null);

        // 視野角チェック用の内積値をあらかじめ計算
        float angle = Mathf.Deg2Rad * _fanAngle / 2.0f;
        _sightThreshold = Mathf.Cos(angle);
    }

    // Update is called once per frame
    void Update()
    {
        // ターゲットが視界に入ったかどうかをチェック
        _isFound = CheckTarget();

        // 検知したらターゲットへ移動
        if ( _isFound )
        {
            // 移動
            Vector3 dir = (_target.transform.position - transform.position).normalized;
            transform.position += (_speed * Time.deltaTime) * dir;

            // 移動量が閾値オーバーであれば向きを変える
            Vector3 diff = transform.position - _prevPos;
            if (diff.magnitude > _diff_threshold)
            {
                Quaternion rot = Quaternion.LookRotation(diff);
                transform.rotation = Quaternion.Slerp(transform.rotation, rot, _rotateSpeed * Time.deltaTime);
            }
        }

        // 前回ポジション
        _prevPos = transform.position;
    }

    // ターゲットが視野内かどうか（対称な扇限定）
    // 全方位版
    private bool CheckTarget()
    {
        // 敵からターゲットへの方向（ワールド系）
        Vector3 p = _target.transform.position - transform.position;

        // 扇の半径外なら即終了（視野外）
        if (p.magnitude > _fanRadius) return false;

        // 敵の向きと敵からプレイヤへの向きとの内積（評価値）を計算
        float eval = Vector3.Dot(p.normalized, transform.forward);

        // 視野内かどうかを判定する
        return eval >= _sightThreshold;     // 評価値判定
    }
}
