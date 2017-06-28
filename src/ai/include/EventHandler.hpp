/*
** EventHandler.hpp for EventHandler in /home/warin_a/TEK2/rendu/PSU/PSU_2016_zappy/src/ai
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Tue Jun 20 15:01:18 2017 Adrien Warin
** Last update Tue Jun 27 15:48:28 2017 Thomas Fossaert
*/

#ifndef     _EVENTHANDLER_HPP_
# define    _EVENTHANDLER_HPP_

# include	<map>
# include	<algorithm>
# include	<string>
# include <unordered_map>
# include	<functional>
# include <vector>
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
    std::map<std::string, std::function<void(void)> >	_event;
    std::map<int,std::vector<std::string>> _tiles;
    std::unordered_map<std::string,int> _inventory;
    std::unordered_map<std::string,int> _need;
    Direction _orientation;
    Socket *_sock;
    State _currentState;

    int _level;

public:
    EventHandler (Socket *);
    ~EventHandler ();


    bool ExistOnTile(const std::string &, int tileNbr);
    void TakeEverything();

    void launchScript();
    void parseInventory(const std::string &);
    void parseTiles(const std::string &);
    bool isAbleToIncant();
    void changeNeed(int);
    int  countPlayerOnTile();

    void MoveUp();
    void TurnRight();
    void TurnLeft();
    void LookAround();
    void Inventory();
    void BroadcastText(const std::string &);
    void Fork();
    void Eject();
    void TakeObject(const std::string &);
    void SetObject(const std::string &);
    void Incantation();
    void PutRock(const std::string &, int, int);
    void TakeRequirement(const std::string &, int, int);
    void UpdateRequirement(int);
    int CaseRequirement(const std::string &, int);
    void PutRequirementRock(const std::string &);

    void epur(std::string &s);
    std::vector<std::string> explode(const std::string&, const char&);
    bool has_any_digits(const std::string& s);
};

#endif
