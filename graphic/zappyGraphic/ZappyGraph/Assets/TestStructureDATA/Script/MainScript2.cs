using System.Collections;
using System.Collections.Generic;
using System;
using UnityEngine;

public class MainScript2 : MonoBehaviour
{

    public NetworkScript net;
    public ParsingScript parser;
    Char delim = ' ';
    private float TimeIntervale = 0.0f;

    void Start()
    {
        net = new NetworkScript();
        parser = new ParsingScript();  
    }

    void OnDestroy()
    {
       net.closeSocket();
    }

    void LateUpdate()
    {
        String line = null;

        /*   TimeIntervale += Time.deltaTime;
           if (TimeIntervale >= 0.6f)
           {
               TimeIntervale = 0.0f;
        */
   //     line = net.readSocket();
      //  if ((line = net.readSocket()) != null)
      //      line = line;
      //      print(line);
           //     String[] cmd = line.Split(delim);
           //     parser.SetServSend(cmd);
     //           parser.SearchInDico(cmd[0]);
     //       }
    //    }
     //      */
    }
}
