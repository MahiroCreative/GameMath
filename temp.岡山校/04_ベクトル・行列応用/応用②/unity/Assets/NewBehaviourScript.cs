using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NewBehaviourScript : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {

        //Vector3 gp = gameObject.transform.position;
        //Vector3 gx = gameObject.transform.right;
        //Vector3 gz = gameObject.transform.forward;
        //Debug.Log($"pos = {gp}");
        //Debug.Log($"xxx = {gx}");
        //Debug.Log($"zzz = {gz}");

        //Matrix4x4 m = gameObject.transform.localToWorldMatrix;
        //Vector3 gxx = new Vector3(m[0, 0], m[0, 1], m[0, 2]);
        //Vector3 gzz = new Vector3(m[2, 0], m[2, 1], m[2, 2]);
        //Vector3 gpp = new Vector3(m[3, 0], m[3, 1], m[3, 2]);

        //Debug.Log($"pos2 = {gpp}");
        //Debug.Log($"xxx2 = {gxx}");
        //Debug.Log($"zzz2 = {gzz}");

        Matrix4x4 m = transform.worldToLocalMatrix;
        Vector4 right = m.GetColumn(0);
        Vector4 up = m.GetColumn(1);
        Vector4 forward = m.GetColumn(2);
        Vector4 pos = m.GetColumn(3);

        Debug.Log($"right    = {right}");
        Debug.Log($"up       = {up}");
        Debug.Log($"forward  = {forward}");
        Debug.Log($"position = {pos}");


    }
}
