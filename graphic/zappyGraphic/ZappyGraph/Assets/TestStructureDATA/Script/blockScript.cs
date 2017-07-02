using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

[Serializable]
public class myCube
{
	//public Dictionary<int, int> cubePos = new Dictionary<int, int>();
	public int cubePosX = 0;
	public int cubePosY = 0;
	public int cubeId = 0;
	public Dictionary<string, int> resources = new Dictionary<string, int>();
	public List<myPlayer> playerList = new List<myPlayer>();
	public GameObject ground;
}