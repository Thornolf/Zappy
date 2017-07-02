using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnMap : MonoBehaviour {

	// Use this for initialization
	/* Check if it's lower than 0 */
	public int sizeX = 1;
	public int sizeY = 1;
	public GameObject firstCube;
	void Start () {
		GameObject myCube;
		for (int j = 0; j < sizeX; j++) {
			for (int i = 0; i < sizeY; i++) {
				myCube = GameObject.Instantiate(firstCube);
				myCube.transform.Translate ((float)j, 0, (float)i);
			}
		}
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
