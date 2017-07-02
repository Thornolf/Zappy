using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class playerInventory : MonoBehaviour {

	public Canvas hudPlayer;
	public List<Text> textToModifPlayer;
	static public Dictionary<string, Text> hudTextPlayer = new Dictionary<string, Text>();
	void Start () {
		hudTextPlayer.Add("NourriturePlayer", textToModifPlayer[0]);
		hudTextPlayer.Add("LinematePlayer", textToModifPlayer[1]);
		hudTextPlayer.Add("DeraumerePlayer", textToModifPlayer[2]);
		hudTextPlayer.Add("SiburPlayer", textToModifPlayer[3]);
		hudTextPlayer.Add("MendianePlayer", textToModifPlayer[4]);
		hudTextPlayer.Add("PhirasPlayer", textToModifPlayer[5]);
		hudTextPlayer.Add("ThystamePlayer", textToModifPlayer[6]);
        hudTextPlayer.Add("LevelPlayer", textToModifPlayer[7]);
        hudTextPlayer.Add("TeamPlayer", textToModifPlayer[8]);
        hudTextPlayer.Add("IdPlayer", textToModifPlayer[9]);
    }

    void Update () {
	}

	static public void	modifyItemPlayer(string key, int value) {
		key = key + "Player";
		hudTextPlayer [key].text = System.Convert.ToString (value);
	}
}
