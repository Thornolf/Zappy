using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

[Serializable]
public class myMap
{
	public int high;
	public int length;
	public List<myPlayer> activePlayer;
	public myCube[,] cubeMap;
}
