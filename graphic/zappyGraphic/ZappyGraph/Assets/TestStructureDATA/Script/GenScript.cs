using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GenScript {

    public int _x = 10;
    public int _y = 10;
    public GameObject _firstCube = Resources.Load("tempGen") as GameObject;

    void Start()
    {
    }

    public void    SetSize(int x, int y)
    {
        this._x = x;
        this._y = y;
    }

    public void GenMap()
    {
        GameObject myCube;

        for (int j = 0; j < _y; j++)
        {
            for (int i = 0; i < _x; i++)
            {
                myCube = GameObject.Instantiate(this._firstCube);
                myCube.transform.Translate((float)j, 0, (float)i);
            }
        }
    }
}
