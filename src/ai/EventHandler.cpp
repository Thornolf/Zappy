/*
** EventHandler.cpp for EventHandler in /home/warin_a/TEK2/rendu/PSU/PSU_2016_zappy/src/ai
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Tue Jun 20 15:00:59 2017 Adrien Warin
** Last update Wed Jun 21 14:53:02 2017 Thomas Fossaert
*/

#include "EventHandler.hpp"

EventHandler::EventHandler(Socket *sock)
{
    _sock = sock;
    this->_event["Forward"] = std::bind(&EventHandler::MoveUp, this);
    this->_event["Right"] = std::bind(&EventHandler::TurnRight, this);
    this->_event["Left"] = std::bind(&EventHandler::TurnLeft, this);
    this->_event["Look"] = std::bind(&EventHandler::LookAround, this);
    this->_event["Inventory"] = std::bind(&EventHandler::Inventory, this);
    this->_event["Broadcast Text"] = std::bind(&EventHandler::BroadcastText, this);
    this->_event["Fork"] = std::bind(&EventHandler::Fork, this);
    this->_event["Eject"] = std::bind(&EventHandler::Eject, this);
    this->_event["Take object"] = std::bind(&EventHandler::TakeObject, this);
    this->_event["Set object"] = std::bind(&EventHandler::SetObject, this);
    this->_event["Incantation"] = std::bind(&EventHandler::Incantation, this);
}

EventHandler::~EventHandler()
{

}

void EventHandler::launchScript()
{
  while (42)
    {
      _sock->sendMsg("Forward\n");
      _sock->recvMsg();
      _sock->sendMsg("Inventory\n");
      _sock->recvMsg();
      parseInventory(_sock->getLastMsg());
      _sock->sendMsg("Take food\n");
      _sock->recvMsg();
    }
}

void EventHandler::parseInventory(const std::string & inventory)
{
  std::string tmp = inventory;
  tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
}

void EventHandler::MoveUp()
{
}

void EventHandler::TurnRight()
{

}

void EventHandler::TurnLeft()
{

}

void EventHandler::LookAround()
{

}

void EventHandler::Inventory()
{

}

void EventHandler::BroadcastText()
{

}

void EventHandler::Fork()
{

}

void EventHandler::Eject()
{

}

void EventHandler::TakeObject()
{

}

void EventHandler::SetObject()
{

}

void EventHandler::Incantation()
{

}
