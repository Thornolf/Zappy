/*
** EventHandler.hpp for EventHandler in /home/warin_a/TEK2/rendu/PSU/PSU_2016_zappy/src/ai
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Tue Jun 20 15:01:18 2017 Adrien Warin
<<<<<<< HEAD
** Last update Fri Jun 30 11:38:54 2017 Adrien Warin
=======
** Last update Fri Jun 30 11:01:20 2017 Thomas Fossaert
>>>>>>> 7143897f36dad20dda4ffdae7dc91f0259df77f9
*/

#ifndef     _EVENTHANDLER_HPP_
# define    _EVENTHANDLER_HPP_

# include	<map>
# include	<algorithm>
# include	<string>
# include <unordered_map>
# include	<functional>
# include <vector>
# include "Utils.hpp"
# include "Socket.hpp"

enum class Direction : int
{
    UP = 0,
    RIGHT,
    DOWN,
    LEFT
};

enum class State : int
{
    INCANTATION = 0,
    READYFORINC,
    NORMAL
};

class EventHandler
{
private:

    std::string                                         _test;
    int                                                 _level;


    Utils                                               _utils;
    State                                               _currentState;
    Socket *                                            _sock;
    Direction                                           _orientation;

    std::map<int,std::vector<std::string>>              _tiles;
    std::map<std::string, std::function<void(void)> >	  _event;

    std::unordered_map<std::string,int>                 _inventory;
    std::unordered_map<std::string,int>                 _need;

public:
    EventHandler (Socket *);
    ~EventHandler ();


    bool ExistOnTile(const std::string &, int tileNbr);
    void TakeEverything();

    void launchScript();
    void parseInventory(const std::string &);
    void parseTiles(const std::string &);
    bool isAbleToIncant();
    bool hasEnoughRock();
    void changeNeed(int);
    int  countPlayerOnTile();
    int getBroadCastDirection();

    void Move();
    void TurnRight();
    void TurnLeft();
    void LookAround();
    void Inventory();
    void Connect_nbr();
    void BroadcastText(const std::string &);
    void Fork();
    void Eject();
    void TakeObject(const std::string &);
    void SetObject(const std::string &);
    void Incantation();


    void PutRock(const std::string &, int, int);
    void TakeRequirement();
    void UpdateRequirement(int);
    int CaseRequirement(const std::string &, int);
    void PutRequirementRock();
};

#endif
