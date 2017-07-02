using System.Collections;
using System;
using System.Collections.Generic;
using UnityEngine;

public class MainCube : MonoBehaviour {

    public MainScript2 main = new MainScript2();
    public myMap map = new myMap ();
	public GameObject woodBlock;
	public GameObject playerObj;
	public Dictionary<int, string> dico = new Dictionary<int, string>();
    int sizeY = 10;
    int sizeX = 10;
    private float TimeIntervale = 0.0f;


    void Start()
    {

        genMap();
        dico.Add(0, "Nourriture");
        dico.Add(1, "Linemate");
        dico.Add(2, "Deraumere");
        dico.Add(3, "Sibur");
        dico.Add(4, "Mendiane");
        dico.Add(5, "Phiras");
        dico.Add(6, "Thystame");
    }

    void    genMap()
    {
        main.parser.CreateDico();

          main.net.SetParams(PlayerPrefs.GetString("Host"), PlayerPrefs.GetInt("Port"));
          main.net.setupSocket();
          main.net.readSocket();
          main.net.writeSocket("GRAPHIC");
         String[] tab = main.net.getMap();

        map.cubeMap = new myCube[Convert.ToInt32(tab[2]), Convert.ToInt32(tab[1])];
        map.high = Convert.ToInt32(tab[2]);
        map.length = Convert.ToInt32(tab[1]);
        sizeY = Convert.ToInt32(tab[2]);
        sizeX = Convert.ToInt32(tab[1]);
        for (int high = 0; high < sizeY; high++)
        {
            for (int length = 0; length < sizeX; length++)
            {
                fillMap(high, length, 0, 0, 0, 0, 0, 0, 0);
            }
        }
    }

	void	fillMap(int high, int length, int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame) {
		map.cubeMap [high, length] = new myCube ();
		map.cubeMap [high, length].cubePosX = length;
		map.cubeMap [high, length].cubePosY = high;
		map.cubeMap [high, length].cubeId = System.Convert.ToInt32("" + high + length);
		map.cubeMap [high, length].ground = Instantiate (woodBlock);
		map.cubeMap [high, length].ground.gameObject.transform.Translate (length, 0, high);
        map.cubeMap[high, length].resources = new Dictionary<string, int>();
        map.cubeMap [high, length].resources.Add("Nourriture", food);
		map.cubeMap [high, length].resources.Add("Linemate", linemate);
		map.cubeMap [high, length].resources.Add("Deraumere", deraumere);
		map.cubeMap [high, length].resources.Add("Sibur", sibur);
		map.cubeMap [high, length].resources.Add("Mendiane", mendiane);
		map.cubeMap [high, length].resources.Add("Phiras", phiras);
		map.cubeMap [high, length].resources.Add("Thystame", thystame);
		fillBlock (high, length);
	}

    void UpdateMap(int high, int length, int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame)
    {
        map.cubeMap[high, length].resources["Nourriture"] = food;
        map.cubeMap[high, length].resources["Linemate"] = linemate;
        map.cubeMap[high, length].resources["Deraumere"] = deraumere;
        map.cubeMap[high, length].resources["Sibur"] = sibur;
        map.cubeMap[high, length].resources["Mendiane"] = mendiane;
        map.cubeMap[high, length].resources["Phiras"] = phiras;
        map.cubeMap[high, length].resources["Thystame"] = thystame;
        fillBlock(high, length);
    }

    void	fillBlock(int high, int length) {

		foreach(KeyValuePair<string, int> entry in map.cubeMap[high, length].resources)
		{
			if (entry.Value < 1) {
				map.cubeMap [high, length].ground.transform.Find (entry.Key).gameObject.SetActive (false);
			}
            else
                map.cubeMap[high, length].ground.transform.Find(entry.Key).gameObject.SetActive(true);
        }
    }

	void	setPlayer(int newY, int newX, int newId, int newDirection, string newTeam) {
		myPlayer p = new myPlayer ();

		p.id = newId;
		p.xPos = newX;
		p.yPos = newY;
		p.level = 1;
		p.playerDirection = newDirection;
		p.team = newTeam;
		p.player = Instantiate(playerObj);
		map.activePlayer.Add (p);
		map.cubeMap [p.yPos, p.xPos].playerList.Add (p);
		p.inv.Add("Nourriture", 0);
		p.inv.Add("Linemate", 0);
		p.inv.Add("Deraumere", 0);
		p.inv.Add("Sibur", 0);
		p.inv.Add("Mendiane", 0);
		p.inv.Add("Phiras", 0);
		p.inv.Add("Thystame", 0);
		p.player.transform.Translate (p.yPos, 0.2f, p.xPos);
	}

    void takeItem(int playerId, int index)
    {
        string resourceName = getNameResources(index);
        foreach (myPlayer p in map.activePlayer)
        {
            if (p.id == playerId)
            {
                var keys = new List<string>(map.cubeMap[p.yPos, p.xPos].resources.Keys);
                foreach (string key in keys)
                {
                    if (key == resourceName)
                    {
                        p.inv[key] += 1;
                        map.cubeMap[p.yPos, p.xPos].resources[key] -= 1;

                    }
                }
            }
        }
    }

    void DropItem(int playerId, int index)
    {
        string resourceName = getNameResources(index);
        foreach (myPlayer p in map.activePlayer)
        {
            if (p.id == playerId)
            {
                var keys = new List<string>(map.cubeMap[p.yPos, p.xPos].resources.Keys);
                foreach (string key in keys)
                {
                    if (key == resourceName)
                    {
                        p.inv[key] -= 1;
                        map.cubeMap[p.yPos, p.xPos].resources[key] += 1;

                    }
                }
            }
        }
    }

    string		getNameResources(int index) {
		foreach (KeyValuePair<int, string> name in dico) {
			if (name.Key == index)
				return (name.Value);
		}
		return (null);
	}

    Vector3 rotatePlayer(int newOrientation)
    {
        if (newOrientation == 1)
            return (new Vector3(0, 90, 0));
        else if (newOrientation == 2)
            return (new Vector3(0, 0, 0));
        else if (newOrientation == 3)
            return (new Vector3(0, 270, 0));
        else if (newOrientation == 4)
            return (new Vector3(0, 180, 0));
        return (new Vector3(0, 0, 0));
    }

    void movePlayer(int id, int newY, int newX, int newOrientatin)
    {
        foreach (myPlayer p in map.activePlayer)
        {
            if (p.id == id)
            {
                map.cubeMap[p.yPos, p.xPos].playerList.Remove(p);
                p.xPos = newX;
                p.yPos = newY;
                map.cubeMap[p.yPos, p.xPos].playerList.Add(p);
                p.player.transform.position = new Vector3(newX, 0.2f, newY);
               p.player.transform.Rotate(rotatePlayer(1));
            }
        }
    }

    Dictionary<string, int> getResources(int id)
    {
        foreach (myCube item in map.cubeMap)
        {
            if (id == item.cubeId)
            {
                Debug.Log("ID : " + item.cubeId);
                return (map.cubeMap[item.cubePosX, item.cubePosY].resources);
            }
        }
        return (null);
    }

    void RedirParsing(String[] tab)
    {
        if (tab[0] == "bct")
        {
            UpdateMap(Convert.ToInt32(tab[2]), Convert.ToInt32(tab[1]), Convert.ToInt32(tab[3]),
                        Convert.ToInt32(tab[4]), Convert.ToInt32(tab[5]), Convert.ToInt32(tab[6]),
                        Convert.ToInt32(tab[7]), Convert.ToInt32(tab[8]), Convert.ToInt32(tab[9]));
        }
        if (tab[0] == "pnw")
        {
            setPlayer(Convert.ToInt32(tab[3]), Convert.ToInt32(tab[2]), Convert.ToInt32(tab[1]),
                        Convert.ToInt32(tab[4]), tab[6]);
        }
        if (tab[0] == "ppo")
        {
            movePlayer(Convert.ToInt32(tab[1]), Convert.ToInt32(tab[3]), Convert.ToInt32(tab[2]),
                        Convert.ToInt32(tab[4]));
        }
        if (tab[0] == "pgt")
            takeItem(Convert.ToInt32(tab[1]), Convert.ToInt32(tab[2]));
        if (tab[0] == "pdr")
            DropItem(Convert.ToInt32(tab[1]), Convert.ToInt32(tab[2]));
    }

    void Update()
    {
        if (Input.GetKey("escape"))
           Application.Quit();
        String line = null;
        String[] tab = null;
        Char delim = ' ';
        if ((line = main.net.readSocket()) != null)
          {
             tab = line.Split(delim);
             RedirParsing(tab);
         }
    }
}
 