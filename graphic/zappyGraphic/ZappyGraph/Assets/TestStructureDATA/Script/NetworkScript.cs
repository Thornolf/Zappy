using UnityEngine;
using System.Collections;
using System;
using System.IO;
using System.Net.Sockets;
using System.Text;

public class NetworkScript : MonoBehaviour
{
    internal Boolean socketReady = false;
    TcpClient mySocket;
    NetworkStream theStream;
    StreamWriter theWriter;
    StreamReader theReader;
    public String _host = "";
    public Int32 _port = 0;
    private float TimeIntervale = 0.0f;

    void Start()
    {
    }

    void Update()
    {
    }

    public void SetParams(String ip, int port)
    {
        this._host = ip;
        this._port = port;
    }

    public void setupSocket()
    {
        try
        {
            mySocket = new TcpClient(_host, _port);
            theStream = mySocket.GetStream();
            theWriter = new StreamWriter(theStream);
            theReader = new StreamReader(theStream);
            socketReady = true;
        }
        catch (Exception e)
        {
            Application.Quit();
        }
    }

    public String[] getMap()
    {
        String mapStr = null;
        String[] tab = null;
        bool ok = false;
        Char delim = ' ';

        while (!ok)
        {
            if ((mapStr = readSocket()) != null)
            {
                tab = mapStr.Split(delim);
                if (tab[0] == "msz")
                    return (tab);
            }
        }
        return (null);
    }

    public void writeSocket(string theLine)
    {
        if (!socketReady)
            return;
        String line = theLine + "\n";
        theWriter.Write(line);
        theWriter.Flush();
    }

    public String readSocket()
    {
        string line = null;
            if (!socketReady)
                return null;
           if (theStream.DataAvailable)
        {
            line = theReader.ReadLine();
            return line;
        }
          return null;
    }


    public void closeSocket()
    {
        if (!socketReady)
            return;
        theWriter.Close();
        theReader.Close();
        mySocket.Close();
        socketReady = false;
    }
}   // end class