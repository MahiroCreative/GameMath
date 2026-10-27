using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DebugSightFan : MonoBehaviour
{
    // エネミーオブジェクト
    [SerializeField]
    Enemy _enemy = null;

    // メッシュ用マテリアル（参照）
    [SerializeField]
    private Material _refMaterial;

    // 扇のポリゴン数
    [SerializeField, Range(1, 1000)]
    private int _numTriangles = 100;

    // メッシュカラー
    [SerializeField]
    private Color _fanMeshNormalColor = new Color(0.1f, 1.0f, 1.0f, 0.8f);  // 通常時
    [SerializeField]
    private Color _fanMeshFoundColor = new Color(1.0f, 0.0f, 0.0f, 0.8f);   // 発見時

    private Mesh _mesh;             // メッシュ
    private Material _material;     // 個別マテリアル
    private int _numVertices;       // 頂点数
    private Vector3[] _vertices;    // 頂点座標
    private int[] _triangles;       // 三角形の頂点インデクス

    private void Awake()
    {
        MeshFilter meshFilter = GetComponent<MeshFilter>();
        MeshRenderer meshRenderer = GetComponent<MeshRenderer>();

        if (_enemy == null || _refMaterial == null || meshFilter == null || meshRenderer == null)
        {
            Debug.LogErrorFormat("Enemy:{0}, RefMaterial:{1}, MeshFilter:{2}, MeshRenderer:{3}",
                _enemy, _refMaterial, meshFilter, meshRenderer);
            Debug.Break();
        }

        // メッシュとマテリアル生成
        _mesh = new Mesh();
        _material = new Material(_refMaterial);
        meshFilter.mesh = _mesh;
        meshRenderer.material = _material;

        // 頂点情報生成
        _numVertices = _numTriangles + 2;
        _vertices = new Vector3[_numVertices];
        _triangles = new int[_numVertices * 3];
    }

    private void LateUpdate()
    {
        // 頂点情報更新
        Color color = _enemy.GetFindFlag() ? _fanMeshFoundColor : _fanMeshNormalColor;
        CreateFanMesh(_enemy.GetFanAngle(), _enemy.GetFanRadius(), color);
    }

    // 頂点情報更新
    private void CreateFanMesh(float fanAngle, float fanRadius, Color color)
    {
        // 開始角
        float angle = (180.0f - fanAngle) / 2;
        angle = Mathf.PI * angle / 180;

        // 差分角
        float delta_angle = (Mathf.PI * fanAngle / 180) / _numTriangles;

        // ２頂点をまず計算
        _vertices[0] = Vector3.zero;
        {
            _vertices[1].x = Mathf.Cos(angle);
            _vertices[1].z = Mathf.Sin(angle);
            _vertices[1].y = 0.0f;
        }

        // ３頂点目から計算継続
        for (int v = 2, t = 0; v < _numVertices; ++v, t += 3)
        {
            angle += delta_angle;

            _vertices[v].x = fanRadius * Mathf.Cos(angle);
            _vertices[v].z = fanRadius * Mathf.Sin(angle);
            _vertices[v].y = 0.0f;

            _triangles[t + 0] = 0;
            _triangles[t + 1] = v - 0;
            _triangles[t + 2] = v - 1;
        }

        // メッシュ更新
        _mesh.vertices = _vertices;
        _mesh.triangles = _triangles;
        _material.color = color;
        
        _mesh.RecalculateNormals();
        //_mesh.RecalculateBounds();
    }
}
