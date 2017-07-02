using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ParsingScript : MonoBehaviour {

    private String[] servSend = null;
    static Dictionary<string, Func<String[], bool>> dico = null;
    
    private void Start()
    {
    }

    private void OnDestroy()
    {
    }

    public static bool MapFunction(String[] array)
    {
        GenScript gen = new GenScript();
        gen.SetSize(Convert.ToInt32(array[1]), Convert.ToInt32(array[2]));
        gen.GenMap();
        return (true);
    }

    public static bool FreqFunction(String[] array)
    {
        Debug.Log("Freq Function.");
        return (true);
    }

    public static bool EndGame(String[] array)
    {
        Debug.Log("End Game Function.");
        return (true);
    }

    public static bool RessFunction(String[] array)
    {
        Debug.Log("INIT Ress Function.");
        return (true);
    }

    public static bool TeamFunction(String[] array)
    {
        Debug.Log("INIT Team Function.");
        return (true);
    }

    public static bool NewPlayerFunction(String[] array)
    {
        Debug.Log("New Player Function.");
        return (true);
    }

    public static bool PlayerPosition(String[] array)
    {
        Debug.Log("Player position");
        return (true);
    }

    public static bool PlayerLevel(String[] array)
    {
        Debug.Log("Level of the Player");
        return (true);
    }

    public static bool PlayerInventory(String[] array)
    {
        Debug.Log("Inventory of player");
        return (true);
    }

    public static bool PlayerExpulse(String[] array)
    {
        Debug.Log("Inventory of player");
        return (true);
    }

    public static bool PlayerBroadcast(String[] array)
    {
        Debug.Log("Player send \"HEY !!\"");
        return (true);
    }

    public static bool PlayerIncantationStart(String[] array)
    {
        Debug.Log("player incantates !");
        return (true);
    }

    public static bool PlayerIncantationEnd(String[] array)
    {
        Debug.Log("player finishes his Incantation !");
        return (true);
    }

    public static bool PlayerLay(String[] array)
    {
        Debug.Log("player lays !");
        return (true);
    }

    public static bool PlayerThrowRessource(String[] array)
    {
        Debug.Log("player throw ressource !");
        return (true);
    }

    public static bool PlayerTakeRessource(String[] array)
    {
        Debug.Log("player take ressource !");
        return (true);
    }

    public static bool PlayerDie(String[] array)
    {
        Debug.Log("player dies !");
        return (true);
    }

    public static bool EggCome(String[] array)
    {
        Debug.Log("An egg has been layed !");
        return (true);
    }

    public static bool EggHatching(String[] array)
    {
        Debug.Log("An egg is hatching !");
        return (true);
    }

    public static bool EggPlayer(String[] array)
    {
        Debug.Log("An egg has been lays by a player !");
        return (true);
    }

    public static bool EggDie(String[] array)
    {
        Debug.Log("An egg dies ! ");
        return (true);
    }

    public static bool ServerMessage(String[] array)
    {
        Debug.Log("A message from the server !");
        return (true);
    }

    public static bool UnknownCommand(String[] array)
    {
        Debug.Log("Unknown command");
        return (true);
    }

    public static bool WrongParameter(String[] array)
    {
        Debug.Log("Wrong Parameter !");
        return (true);
    }

    public void    CreateDico() {

        Dictionary<string, Func<String[], bool>> tmp = new Dictionary<string, Func<String[], bool>>();
        tmp.Add("msz", MapFunction);

        tmp.Add("sgt", FreqFunction);
        tmp.Add("seg", EndGame);

        tmp.Add("bct", RessFunction);
        tmp.Add("tna", TeamFunction);

        tmp.Add("pnw", NewPlayerFunction);
        tmp.Add("ppo", PlayerPosition);
        tmp.Add("plv", PlayerLevel);
        tmp.Add("pin", PlayerInventory);
        tmp.Add("pex", PlayerExpulse);
        tmp.Add("pbc", PlayerBroadcast);
        tmp.Add("pic", PlayerIncantationStart);
        tmp.Add("pie", PlayerIncantationEnd);
        tmp.Add("pfk", PlayerLay);
        tmp.Add("pdr", PlayerThrowRessource);
        tmp.Add("pgt", PlayerTakeRessource);
        tmp.Add("pdi", PlayerDie);

        tmp.Add("enw", EggCome);
        tmp.Add("eht", EggHatching);
        tmp.Add("ebo", EggPlayer);
        tmp.Add("edi", EggDie);

        tmp.Add("smg", ServerMessage);
        tmp.Add("suc", UnknownCommand);
        tmp.Add("sbp", WrongParameter);
        dico = tmp;

    }

    public void    SetServSend(String[] newArray)
    {
        servSend = newArray;
    }

    public void    SearchInDico(String what)
    {
        foreach (var line in dico)
        {
            if (line.Key.Equals(what))
            {
               var ok = line.Value(servSend);
            }
        }    
    }
}
