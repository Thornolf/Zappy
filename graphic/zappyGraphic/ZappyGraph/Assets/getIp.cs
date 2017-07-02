using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class getIp : MonoBehaviour {

	// Use this for initialization
	public string ip;
	public int port;
	public Text ipAdress;
	public Text portAdress;
	void Start () {
	}
	
	// Update is called once per frame
	public void GetIP () {
		ip = ipAdress.text.ToString ();
	}
	public void GetPort() {
		port = System.Convert.ToInt32 (portAdress.text.ToString());
	}
	float i = 0f;
	void Update() {
		i += Time.deltaTime;
		if (i > 10) {
			Debug.Log ("Port : " + port);
			Debug.Log ("Ip : " + ip);
		}
	}
}
