/*
** EventHandler.cpp for EventHandler in /home/warin_a/TEK2/rendu/PSU/PSU_2016_zappy/src/ai
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Tue Jun 20 15:00:59 2017 Adrien Warin
** Last update Thu Jun 22 13:09:21 2017 Thomas Fossaert
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

    this->_need["nb_player"] = 1;
    this->_need["linemate"] = 1;
    this->_need["deraumere"] = 0;
    this->_need["sibur"] = 0;
    this->_need["mendiane"] = 0;
    this->_need["phiras"] = 0;
    this->_need["thystame"] = 0;


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
      _sock->sendMsg("Broadcast MDR\n");
      _sock->recvMsg();
      _sock->sendMsg("Look\n");
      _sock->recvMsg();
      parseTiles(_sock->getLastMsg());
      _sock->sendMsg("Take food\n");
      _sock->recvMsg();

    }
}

void EventHandler::parseInventory(const std::string & inventory)
{
  std::string tmp = inventory;
  tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
}

void EventHandler::parseTiles(const std::string & tiles)
{
  std::string tmp = tiles;
  std::vector<std::string> tmpVec;
  int i = 0;

  tmp.erase(std::remove(tmp.begin(), tmp.end(), '['), tmp.end());
  tmp.erase(std::remove(tmp.begin(), tmp.end(), ']'), tmp.end());
  epur(tmp);

  tmpVec = explode(tmp, ',');
  for (auto it : tmpVec)
    {
      epur(it);
      _tiles[i] = explode(it, ' ');
      i++;
    }
  /*int cpt = 0;
  for (auto it2 : _tiles)
    {
      std::cout << cpt << '\n';
      for (auto it3 : _tiles[cpt])
        std::cout << it3 << '\n';
      cpt++;
    }*/
}

bool EventHandler::isAbleToIncant()
{
  if (_invetory["linemate"] == _need["linemate"])
    return (true);
  return (false);
}

void EventHandler::MoveUp()
{
  _sock->sendMsg("Forward\n");
  _sock->recvMsg();
}

void EventHandler::TurnRight()
{
  _sock->sendMsg("Right\n");
  _sock->recvMsg();
}

void EventHandler::TurnLeft()
{
  _sock->sendMsg("Left\n");
  _sock->recvMsg();
}

void EventHandler::LookAround()
{
  _sock->sendMsg("Look\n");
  _sock->recvMsg();
}

void EventHandler::Inventory()
{
  _sock->sendMsg("Inventory\n");
  _sock->recvMsg();
}

void EventHandler::BroadcastText()
{
  _sock->sendMsg("Broadcast\n");
  _sock->recvMsg();
}

void EventHandler::Fork()
{
  _sock->sendMsg("Connect_nbr\n");
  _sock->recvMsg();
}

void EventHandler::Eject()
{
  _sock->sendMsg("Eject\n");
  _sock->recvMsg();
}

void EventHandler::TakeObject()
{
  _sock->sendMsg("Take\n");
  _sock->recvMsg();
}

void EventHandler::SetObject()
{
  _sock->sendMsg("Set\n");
  _sock->recvMsg();
}

void EventHandler::Incantation()
{
  _sock->sendMsg("start incantation\n");
  _sock->recvMsg();
}

void EventHandler::epur(std::string &s)
{
  bool space = false;
  auto p = s.begin();
  for (auto ch : s)
    if (std::isspace(ch)) {
      space = p != s.begin();
    } else {
      if (space) *p++ = ' ';
      *p++ = ch;
      space = false; }
  s.erase(p, s.end());
}

std::vector<std::string> EventHandler::explode(const std::string& str, const char& ch)
{
    std::string next;
    std::vector<std::string> result;

    for (auto it = str.begin(); it != str.end(); it++)
      {
        if (*it == ch)
          {
              result.push_back(next);
              next.clear();
          }
        else
          next += *it;
    }
    if (!next.empty())
        result.push_back(next);
    return (result);
}
