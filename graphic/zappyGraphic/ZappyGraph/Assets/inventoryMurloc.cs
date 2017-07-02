using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class inventoryMurloc : MonoBehaviour {

	public GameObject player;

	void Start () {
		
	}
	
	void Update () {
		
	}

	void OnMouseDown() {
		GameObject cube = GameObject.Find ("MainCube");
		MainCube mCube = cube.GetComponent<MainCube> ();

		foreach (myPlayer p in mCube.map.activePlayer) {
			if (System.Convert.ToInt32 (player.transform.position.z) == p.yPos && System.Convert.ToInt32 (player.transform.position.x) == p.xPos) {
				foreach (KeyValuePair<string, int> entry in p.inv) {
					playerInventory.modifyItemPlayer (entry.Key, entry.Value);
				}
			}
		}
	}
}
