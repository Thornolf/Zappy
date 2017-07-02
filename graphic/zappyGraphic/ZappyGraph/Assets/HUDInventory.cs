using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class HUDInventory : MonoBehaviour {

	// Use this for initialization
	public Canvas hud;
	public List<Text> textToModif;
	static public Dictionary<string, Text> hudText = new Dictionary<string, Text>();
	void Start () {
		//)hud.gameObject.SetActive (false);
		hudText.Add("Nourriture", textToModif[0]);
		hudText.Add("Linemate", textToModif[1]);
		hudText.Add("Deraumere", textToModif[2]);
		hudText.Add("Sibur", textToModif[3]);
		hudText.Add("Mendiane", textToModif[4]);
		hudText.Add("Phiras", textToModif[5]);
		hudText.Add("Thystame", textToModif[6]);
	}

	// Update is called once per frame
	void Update () {
	}
	static public void	modifyItem(string key, int value) {
		hudText [key].text = System.Convert.ToString (value);
	}
}
