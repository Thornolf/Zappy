/*
** EventHandler.hpp for EventHandler in /home/warin_a/TEK2/rendu/PSU/PSU_2016_zappy/src/ai
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Tue Jun 20 15:01:18 2017 Adrien Warin
** Last update Thu Jun 22 13:43:52 2017 Adrien Warin
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

class EventHandler
{
private:
    std::map<std::string, std::function<void(void)> >	_event;

    std::map<int,std::vector<std::string>> _tiles;

    std::unordered_map<std::string,int> _inventory;
    std::unordered_map<std::string,int> _need;

    Direction _orientation;
    Socket *_sock;

public:
    EventHandler (Socket *);
    ~EventHandler ();

    void launchScript();
    void parseInventory(const std::string &);
    void parseTiles(const std::string &);
    bool isAbleToIncant();

    void MoveUp();
    void TurnRight();
    void TurnLeft();
    void LookAround();
    void Inventory();
    void BroadcastText();
    void Fork();
    void Eject();
    void TakeObject();
    void SetObject();
    void Incantation();

    void epur(std::string &s);
    std::vector<std::string> explode(const std::string&, const char&);
};

#endif
