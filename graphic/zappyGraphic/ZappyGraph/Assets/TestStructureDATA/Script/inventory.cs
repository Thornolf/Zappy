using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class inventory : MonoBehaviour {

	public GameObject plank;
	void Start () {
	}

	void Update () {
	}
	void OnMouseDown() {
		GameObject cube = GameObject.Find ("MainCube");
		MainCube mCube = cube.GetComponent<MainCube> ();

		int cubeId = System.Convert.ToInt32("" + plank.transform.position.x + plank.transform.position.z);
		foreach (KeyValuePair<string, int> entry in mCube.map.cubeMap[System.Convert.ToInt32(plank.transform.position.z), System.Convert.ToInt32(plank.transform.position.x)].resources) {
			HUDInventory.modifyItem (entry.Key, entry.Value);
		}
	}
}
