/*
** EventHandler.cpp for EventHandler in /home/warin_a/TEK2/rendu/PSU/PSU_2016_zappy/src/ai
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Tue Jun 20 15:00:59 2017 Adrien Warin
** Last update Sun Jul 02 13:12:46 2017 Adrien Warin
*/

#include <ctime>
#include "ai/EventHandler.hpp"

EventHandler::EventHandler(Socket *sock)
{
    this->_sock = sock;

    this->_need.insert( std::pair<std::string, int>("player", 1));
    this->_need.insert( std::pair<std::string, int>("linemate", 1));
    this->_need.insert( std::pair<std::string, int>("deraumere", 0));
    this->_need.insert( std::pair<std::string, int>("sibur", 0));
    this->_need.insert( std::pair<std::string, int>("mendiane", 0));
    this->_need.insert( std::pair<std::string, int>("phiras", 0));
    this->_need.insert( std::pair<std::string, int>("thystame", 0));
    this->_level = 1;
    this->_currentState = State::NORMAL;
}

EventHandler::~EventHandler()
{

}

bool EventHandler::ExistOnTile(const std::string & item, int tileNbr)
{
  int cpt = 0;

  for (auto it : _tiles)
    {
      for (auto it2 : _tiles[cpt])
        {
          if (cpt == tileNbr && it2 == item)
            return (true);
        }
      cpt++;
    }
  return (false);
}

void EventHandler::TakeEverything()
{
  for (auto it : _tiles[0])
    {
      if (it != "player")
        {
          std::cout << it << '\n';
          TakeObject(it);
        }
    }
}

void EventHandler::UpdateRequirement(int newLvl)
{
    if (newLvl == 2)
    {
      _need["player"] = 2;
      _need["deraumere"] = 1;
      _need["sibur"] = 1;
    }
    else if (newLvl == 3)
    {
      _need["linemate"] = 2;
      _need["deraumere"] = 0;
      _need["phiras"] = 2;
    }
    else if (newLvl == 4)
    {
      _need["player"] = 4;
      _need["linemate"] = 1;
      _need["deraumere"] = 1;
      _need["sibur"] = 2;
      _need["phiras"] = 1;
    }
    else if (newLvl == 5)
    {
      _need["mendiane"] = 3;
      _need["deraumere"] = 2;
      _need["sibur"] = 1;
      _need["phiras"] = 0;
    }
    else if (newLvl == 6)
    {
      _need["player"] = 6;
      _need["sibur"] = 3;
      _need["mendiane"] = 0;
      _need["phiras"] = 1;
    }
    else if (newLvl == 7)
    {
      _need["linemate"] = 2;
      _need["deraumere"] = 2;
      _need["sibur"] = 2;
      _need["phiras"] = 2;
      _need["thystame"] = 1;
    }
}

void EventHandler::launchScript()
{
  std::srand(std::time(0));

  while (42)
    {
      Inventory();
      LookAround();
      parseTiles(_sock->getLastTile());
      parseInventory(_sock->getLastInventory());
      _sock->resetBroacastText();
      if (isAbleToIncant() == true && _currentState == State::NORMAL)
        _currentState = State::READYFORINC;
      else if (hasEnoughRock() == true && _currentState == State::NORMAL)
        BroadcastText("Need ppl for level " + std::to_string(_level + 1));
      if (_currentState == State::INCANTATION)
        {
          if (_sock->getLevelUp().find("Current level") != std::string::npos)
            {
              _sock->resetLevelUp();
              this->_level += 1;
              UpdateRequirement(this->_level);
              _currentState = State::NORMAL;
            }
          else if (_sock->getLastMsg().find("ko") != std::string::npos)
            _currentState = State::NORMAL;
          else
            Incantation();
        }
        else if (_currentState == State::READYFORINC)
          {
            TakeEverything();
            PutRequirementRock();
            _currentState = State::INCANTATION;
          }
        else if (_currentState == State::NORMAL)
          {
            Move();
            TakeObject("food");
            TakeRequirement();
          }
    }
}

void EventHandler::parseInventory(const std::string & inventory)
{
  std::string tmp = inventory;
  tmp.erase(std::remove(tmp.begin(), tmp.end(), '['), tmp.end());
  tmp.erase(std::remove(tmp.begin(), tmp.end(), ']'), tmp.end());
  tmp.erase(0, 1);
  std::vector<std::string> my_vec;
  std::string delimiter = " ";
  size_t pos = 0;
  std::string 	token;
  std::string   nb;

  std::cout << tmp << '\n';
  my_vec = _utils.explode(tmp, ',');
  for(std::vector<std::string>::iterator it = my_vec.begin(); it != my_vec.end(); ++it)
    {
        _utils.epur(*it);
        token = *it;
        if ((pos = token.find(delimiter)) != std::string::npos)
        {
            token = tmp.substr(0, pos);
            tmp.erase(0, pos + delimiter.length());
            if ((pos = tmp.find(delimiter)) != std::string::npos)
            {
                nb = tmp.substr(0, pos);
                tmp.erase(0, pos + delimiter.length());
            }
            if (_utils.has_any_digits(nb) == true)
            {
                nb.erase(std::remove(nb.begin(), nb.end(), ','), nb.end());
              _inventory[token] = stoi(nb);
            }
        }
    }
}

void EventHandler::PutRock(const std::string &objName, int inv, int requirement)
{
    int cpt = 0;

    if (inv >= requirement)
    {
        while (cpt != requirement)
        {
            SetObject(objName);
            cpt++;
        }
    }
}

void EventHandler::TakeRequirement()
{
    for (auto it : _tiles[0])
    {
        if (_inventory[it] < _need[it] && it != "player")
            TakeObject(it);
    }
}

void EventHandler::parseTiles(const std::string & tiles)
{
  std::string tmp = tiles;
  std::vector<std::string> tmpVec;
  int i = 0;

  tmp.erase(std::remove(tmp.begin(), tmp.end(), '['), tmp.end());
  tmp.erase(std::remove(tmp.begin(), tmp.end(), ']'), tmp.end());
  _utils.epur(tmp);

  tmpVec = _utils.explode(tmp, ',');
  for (auto it : tmpVec)
    {
      _utils.epur(it);
      _tiles[i] = _utils.explode(it, ' ');
      i++;
    }
}

void EventHandler::PutRequirementRock()
{
    int nb = 0;
    int nb_to_put = 0;

    for (auto &it : _inventory)
    {
        nb = CaseRequirement(it.first, 0);
        if (this->_need[it.first] > 0)
            nb_to_put = this->_need[it.first] - nb;
        if (nb_to_put > 0)
            PutRock(it.first, this->_inventory[it.first], nb_to_put);
    }
}

int EventHandler::CaseRequirement(const std::string & item, int tileNbr)
{
  int cpt = 0;
  int rock = 0;

  for (auto it : _tiles)
    {
      for (auto it2 : _tiles[cpt])
        {
          if (cpt == tileNbr && it2 == item)
            rock++;
        }
      cpt++;
    }
  return (rock);
}

bool EventHandler::isAbleToIncant()
{
  if (_inventory["linemate"] >= _need["linemate"] &&
      _inventory["deraumere"] >= _need["deraumere"] &&
      _inventory["sibur"] >= _need["sibur"] &&
      _inventory["mendiane"] >= _need["mendiane"] &&
      _inventory["phiras"] >= _need["phiras"] &&
      _inventory["thystame"] >= _need["thystame"] &&
      countPlayerOnTile() == _need["player"])
    return (true);
  return (false);
}

bool EventHandler::hasEnoughRock()
{
  if (_inventory["linemate"] >= _need["linemate"] &&
      _inventory["deraumere"] >= _need["deraumere"] &&
      _inventory["sibur"] >= _need["sibur"] &&
      _inventory["mendiane"] >= _need["mendiane"] &&
      _inventory["phiras"] >= _need["phiras"] &&
      _inventory["thystame"] >= _need["thystame"])
    return (true);
  return (false);
}

int EventHandler::countPlayerOnTile()
{
  int i = 0;

  for (auto it : _tiles[0])
    {
      if (it == "player")
        i++;
    }
  return (i);
}

int EventHandler::getBroadCastDirection()
{
  int dir;
  std::vector<std::string> tmpVec;

  for (auto it : tmpVec)
    {
      if (it.find("Need ppl for level " + std::to_string(_level + 1)) != std::string::npos)
        {
          dir = std::stoi(it);
          return (dir);
        }
    }
  return (0);
}

void EventHandler::Move()
{
  int dir = 0;
  int random_variable;

  random_variable = std::rand();
  dir = getBroadCastDirection();
  if (dir == 3 || dir == 4)
    TurnLeft();
  else if (dir == 5 || dir == 6)
    {
      TurnLeft();
      TurnLeft();
    }
  else if (dir == 7 || dir == 8)
    TurnRight();
  else if (random_variable % 5 == 0)
      TurnRight();
  std::cout << "COMMAND: Move" << '\n';
  _sock->sendMsg("Forward\n");
  _sock->recvMsg();
}

void EventHandler::TurnRight()
{
     std::cout << "COMMAND: TurnRight" << '\n';
  _sock->sendMsg("Right\n");
  _sock->recvMsg();
}

void EventHandler::TurnLeft()
{
     std::cout << "COMMAND: TurnLeft" << '\n';
  _sock->sendMsg("Left\n");
  _sock->recvMsg();
}

void EventHandler::LookAround()
{
     std::cout << "COMMAND: LookAround" << '\n';
  _sock->sendMsg("Look\n");
  _sock->recvMsg();
}

void EventHandler::Inventory()
{
     std::cout << "COMMAND: Inventory" << '\n';
  _sock->sendMsg("Inventory\n");
  _sock->recvMsg();
}

void EventHandler::Connect_nbr()
{
     std::cout << "COMMAND: Connect_nbr" << '\n';
  _sock->sendMsg("Connect_nbr\n");
  _sock->recvMsg();
}

void EventHandler::BroadcastText(const std::string & text)
{
     std::cout << "COMMAND: BroadcastText" << '\n';
  _sock->sendMsg(("Broadcast " + text + "\n").c_str());
  _sock->recvMsg();
}

void EventHandler::Fork()
{
     std::cout << "COMMAND: Fork" << '\n';
  _sock->sendMsg("Fork\n");
  _sock->recvMsg();
}

void EventHandler::Eject()
{
     std::cout << "COMMAND: Eject" << '\n';
  _sock->sendMsg("Eject\n");
  _sock->recvMsg();
}

void EventHandler::TakeObject(const std::string & item)
{
     std::cout << "COMMAND: Take" << '\n';
    _sock->sendMsg(("Take " + item + "\n").c_str());
    _sock->recvMsg();
}

void EventHandler::SetObject(const std::string & item)
{
     std::cout << "COMMAND: SetObject" << '\n';
  _sock->sendMsg(("Set " + item + "\n").c_str());
  _sock->recvMsg();
}

void EventHandler::Incantation()
{
     std::cout << "COMMAND: Incantation" << '\n';
  _sock->sendMsg("Incantation\n");
  _sock->recvMsg();
}
