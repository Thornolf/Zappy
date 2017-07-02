using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System;

public class getIntel : MonoBehaviour
{

    // Use this for initialization
    public string Host;
    public int Port;
    public Text ipAdress;
    public Text portAdress;
    public GameObject btn;
    public bool ipGiven = false;
    public bool portGiven = false;
    void Start()
    {
        btn.gameObject.SetActive(false);
    }

    // Update is called once per frame
    public void GetIP()
    {
        Host = ipAdress.text.ToString();
        PlayerPrefs.SetString("Host", Host);
        ipGiven = true;
    }
    public void GetPort()
    {
        Port = System.Convert.ToInt32(portAdress.text.ToString());
        PlayerPrefs.SetInt("Port", Port);
        portGiven = true;
    }
    float i = 0f;
    void Update()
    {
        i += Time.deltaTime;
        if (i > 4)
        {
            Debug.Log("Port : " + Port);
            Debug.Log("Ip : " + Host);
        }
        if (portGiven && ipGiven)
        {
            btn.gameObject.SetActive(true);
        }
    }
}
