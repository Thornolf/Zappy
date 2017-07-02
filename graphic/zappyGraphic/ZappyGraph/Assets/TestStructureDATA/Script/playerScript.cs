using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

[Serializable]
public class myPlayer
{
	public int id = 0;
	public int xPos = 0;
	public int yPos = 0;
	public int level = 1;
	public int playerDirection = 1;
	public string team = "blue";
	public GameObject player;
	public Dictionary<string, int> inv = new Dictionary<string, int>();
}
