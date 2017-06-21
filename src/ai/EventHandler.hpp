/*
** EventHandler.hpp for EventHandler in /home/warin_a/TEK2/rendu/PSU/PSU_2016_zappy/src/ai
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Tue Jun 20 15:01:18 2017 Adrien Warin
** Last update Tue Jun 20 15:38:32 2017 Adrien Warin
*/

#include	<map>
#include	<algorithm>
#include	<string>
#include	<functional>

#ifndef     EVENTHANDLER_HPP_
# define    EVENTHANDLER_HPP_

class EventHandler
{
private:
    std::map<std::string, std::function<void(int, int)> >	_event;

public:
    EventHandler ();
    virtual ~EventHandler ();

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
};

#endif
