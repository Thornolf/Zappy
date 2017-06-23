/*
** EventHandler.cpp for EventHandler in /home/warin_a/TEK2/rendu/PSU/PSU_2016_zappy/src/ai
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Tue Jun 20 15:00:59 2017 Adrien Warin
** Last update Fri Jun 23 14:16:09 2017 Thomas Fossaert
*/

#include "EventHandler.hpp"

EventHandler::EventHandler(Socket *sock)
{
    _sock = sock;
    /*this->_event["Forward"] = std::bind(&EventHandler::MoveUp, this);
    this->_event["Right"] = std::bind(&EventHandler::TurnRight, this);
    this->_event["Left"] = std::bind(&EventHandler::TurnLeft, this);
    this->_event["Look"] = std::bind(&EventHandler::LookAround, this);
    this->_event["Inventory"] = std::bind(&EventHandler::Inventory, this);
    this->_event["Broadcast Text"] = std::bind(&EventHandler::BroadcastText, this);
    this->_event["Fork"] = std::bind(&EventHandler::Fork, this);
    this->_event["Eject"] = std::bind(&EventHandler::Eject, this);
    this->_event["Take object"] = std::bind(&EventHandler::TakeObject, this);
    this->_event["Set object"] = std::bind(&EventHandler::SetObject, this);
    this->_event["Incantation"] = std::bind(&EventHandler::Incantation, this);*/

    this->_need["nb_player"] = 1;
    this->_need["linemate"] = 1;
    this->_need["deraumere"] = 0;
    this->_need["sibur"] = 0;
    this->_need["mendiane"] = 0;
    this->_need["phiras"] = 0;
    this->_need["thystame"] = 0;

    this->_level = 1;
}

EventHandler::~EventHandler()
{

}

void EventHandler::launchScript()
{
  while (42)
    {
      if (_sock->getLastMsg() == "Elevation underway\n")
        {
          Incantation();
          if (_sock->getLastMsg().find("Current level") != std::string::npos)
            {
              this->_level += 1;
              this->_need["nb_player"] = 2;
              this->_need["deraumere"] = 1;
              this->_need["sibur"] = 1;
            }
        }
      else
        {
          if (isAbleToIncant() == true)
          {
            TakeObject("linemate");
            TakeObject("deraumere");
            TakeObject("sibur");
            TakeObject("mendiane");
            TakeObject("phiras");
            TakeObject("thystame");

            SetObject("linemate");
            Incantation();
          }
        else
          {
            LookAround();
            MoveUp();
            TakeObject("linemate");
            TakeObject("food");
          }
        }
      std::cout << this->_level << '\n';
    }
}

void EventHandler::parseInventory(const std::string & inventory)
{
  std::string tmp = inventory;
  tmp.erase(std::remove(tmp.begin(), tmp.end(), '['), tmp.end());
  tmp.erase(std::remove(tmp.begin(), tmp.end(), ']'), tmp.end());
  tmp.erase(std::remove(tmp.begin(), tmp.end(), ','), tmp.end());
  tmp.erase(0, 1);
  tmp.erase(tmp.size() - 1);
  size_t pos = 0;
  std::string 	token;
  std::string   nb;
  std::string delimiter = " ";

  _inventory.erase(_inventory.begin(), _inventory.end());
  while ((pos = tmp.find(delimiter)) != std::string::npos)
    {
        token = tmp.substr(0, pos);
        epur(token);
        tmp.erase(0, pos + delimiter.length());
        if ((pos = tmp.find(delimiter)) != std::string::npos)
        {
            nb = tmp.substr(0, pos);
            epur(nb);
            tmp.erase(0, pos + delimiter.length());
        }
        _inventory.insert( std::pair<std::string, int>(token, stoi(nb)));
    }
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
  if (_inventory["linemate"] == _need["linemate"] &&
      _inventory["deraumere"] == _need["deraumere"] &&
      _inventory["sibur"] == _need["sibur"])
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
  parseTiles(_sock->getLastMsg());
}

void EventHandler::Inventory()
{
  _sock->sendMsg("Inventory\n");
  _sock->recvMsg();
  parseInventory(_sock->getLastMsg());
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

void EventHandler::TakeObject(const std::string & item)
{
  _sock->sendMsg(("Take " + item + "\n").c_str());
  _sock->recvMsg();
  Inventory();
}

void EventHandler::SetObject(const std::string & item)
{
  _sock->sendMsg(("Set " + item + "\n").c_str());
  _sock->recvMsg();
  Inventory();
}

void EventHandler::Incantation()
{
  _sock->sendMsg("Incantation\n");
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
