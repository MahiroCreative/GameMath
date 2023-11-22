using UnityEngine;
using UnityEngine.UI;

/*DotPos1:点と座標*/
//【問題】
// オブジェクトの座標と原点からの長さ(距離)を表示せよ。
// ただし、スクリプトのアタッチは『DotPosManager』のみに行うこと。
//【解答方針】
//・オブジェクトの座標を取得
//・原点からの長さを計算
//・テキストに座標と原点からの長さを表示

public class DotAndPos1 : MonoBehaviour
{
    GameObject _posText, _circle;
    Vector3 _position;
    string _text;
    float _length;

    void Start()
    {
        //オブジェクトの取得
        _circle = GameObject.Find("Circle");

        //左下テキストの取得
        _posText = GameObject.Find("posText");
    }

    void Update()
    {
        //座標の取得
        _position = _circle.transform.position;

        //原点からの長さの取得
        _length = _circle.transform.position.magnitude;

        //左下テキストの更新
        _text = $"positon:{_position}\n";
        _text += $"length:{_length}";
        _posText.GetComponent<Text>().text = _text ;
    }

}
