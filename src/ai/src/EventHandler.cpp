/*
** EventHandler.cpp for EventHandler in /home/warin_a/TEK2/rendu/PSU/PSU_2016_zappy/src/ai
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Tue Jun 20 15:00:59 2017 Adrien Warin
// Last update Tue Jun 27 18:06:50 2017 Adrien Warin
*/

#include <ctime>
#include "EventHandler.hpp"

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
        /*this->_need.insert( std::pair<std::string, int>("player", 2));
        this->_need.insert( std::pair<std::string, int>("deraumere", 1));
        this->_need.insert( std::pair<std::string, int>("sibur", 1));*/
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
        this->_need.insert( std::pair<std::string, int>("player", 4));
        this->_need.insert( std::pair<std::string, int>("linemate", 1));
        this->_need.insert( std::pair<std::string, int>("deraumere", 1));
        this->_need.insert( std::pair<std::string, int>("sibur", 2));
        this->_need.insert( std::pair<std::string, int>("phiras", 1));
    }
    else if (newLvl == 5)
    {
        this->_need.insert( std::pair<std::string, int>("deraumere", 2));
        this->_need.insert( std::pair<std::string, int>("sibur", 1));
        this->_need.insert( std::pair<std::string, int>("mendiane", 3));
        this->_need.insert( std::pair<std::string, int>("phiras", 0));

    }
    else if (newLvl == 6)
    {
        this->_need.insert( std::pair<std::string, int>("player", 6));
        this->_need.insert( std::pair<std::string, int>("sibur", 3));
        this->_need.insert( std::pair<std::string, int>("mendiane", 0));
        this->_need.insert( std::pair<std::string, int>("phiras", 1));
    }
    else if (newLvl == 7)
    {
        this->_need.insert( std::pair<std::string, int>("linemate", 2));
        this->_need.insert( std::pair<std::string, int>("sibur", 2));
        this->_need.insert( std::pair<std::string, int>("mendiane", 2));
        this->_need.insert( std::pair<std::string, int>("phiras", 2));
        this->_need.insert( std::pair<std::string, int>("thystame", 1));
    }
}

void EventHandler::launchScript()
{
  std::srand(std::time(0));
  int random_variable;

  while (42)
    {
      LookAround();
      if (isAbleToIncant() == true)
        _currentState = State::READYFORINC;
      if (_currentState == State::INCANTATION)
        {
          if (_sock->getLastMsg().find("Current level") != std::string::npos)
            {
              this->_level += 1;
              UpdateRequirement(this->_level);
              _currentState = State::NORMAL;
            }
          else if (_sock->getLastMsg().find("ko") != std::string::npos)
            _currentState = State::NORMAL;
        }
        else if (_currentState == State::READYFORINC)
          {
            TakeEverything();
            PutRequirementRock();
            // PutRequirementRock("linemate");
            // PutRequirementRock("deraumere");
            // PutRequirementRock("sibur");
            // PutRequirementRock("mendiane");
            // PutRequirementRock("phiras");
            // PutRequirementRock("thystame");
            Inventory();
            Incantation();
            (_sock->getLastMsg() != "ko\n") ? _currentState = State::INCANTATION : _currentState = State::NORMAL;
          }
        else if (_currentState == State::NORMAL)
          {
            MoveUp();
            random_variable = std::rand();
            if (random_variable % 5 == 0)
              TurnRight();
            TakeObject("food");
            TakeRequirement();
            // TakeRequirement("linemate", this->_inventory["linemate"], this->_need["linemate"]);
            // TakeRequirement("deraumere", this->_inventory["deraumere"], this->_need["deraumere"]);
            // TakeRequirement("sibur", this->_inventory["sibur"], this->_need["sibur"]);
            // TakeRequirement("mendiane", this->_inventory["mendiane"], this->_need["mendiane"]);
            // TakeRequirement("phiras", this->_inventory["phiras"], this->_need["phiras"]);
            // TakeRequirement("thystame", this->_inventory["thystame"], this->_need["thystame"]);
            Inventory();
          }
        std::cout << "LEVEL = " << _level << "\n";
        std::cout << "FOOD: " << _inventory["food"] << '\n';
        std::cout << "Player required : " << _need["player"] << '\n';
        std::cout << "Player on tile : " << countPlayerOnTile() << '\n';
        std::cout << "Need linemate =" << _need["linemate"] << '\n';
        std::cout << "Need deraumere =" << _need["deraumere"] << '\n';
        std::cout << "Need mendiane =" << _need["mendiane"] << '\n';
        std::cout << "Need phiras =" << _need["phiras"] << '\n';
        std::cout << "Need thystame =" << _need["thystame"] << '\n';
        std::cout << "LINEMATE DANS LINVENTAIRE : " << _inventory["linemate"] << '\n';
    }
}

void EventHandler::parseInventory(const std::string & inventory)
{
  std::string tmp = inventory;
  tmp.erase(std::remove(tmp.begin(), tmp.end(), '['), tmp.end());
  tmp.erase(std::remove(tmp.begin(), tmp.end(), ']'), tmp.end());
  tmp.erase(0, 1);
  tmp.erase(tmp.size() - 1);
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
                std::cout << "AJOUT DE " << nb << " DE " << token << '\n';
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
  std::cout << "PASSIIIIIIIIIIIINNNNNNNNNNNNNNNNNN : " << tiles << '\n';
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
        {
            std::cout << "NOMBRE DE " << it.first << " A POSER = " << nb_to_put << '\n';
            PutRock(it.first, this->_inventory[it.first], nb_to_put);
        }
    }
    // nb = CaseRequirement(item, 0);
    // if (this->_need[item] > 0)
    //   nb_to_put = this->_need[item] - nb;
    // if (nb_to_put < 0)
    //   nb_to_put = 0;
    // std::cout << "NOMBRE DE " << item << " A POSER = " << nb_to_put << '\n';
    // PutRock(item, this->_inventory[item], nb_to_put);
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
  if (_sock->getLastMsg() != "ko")
    parseTiles(_sock->getLastMsg());
}

void EventHandler::Inventory()
{
  _sock->sendMsg("Inventory\n");
  _sock->recvMsg();
  this->_test = _sock->getLastMsg();
  std::cout << " ---- INVENTORY : " << this->_test << '\n';
  parseInventory(this->_test);
}

void EventHandler::BroadcastText(const std::string & text)
{
  (void)text;
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
}

void EventHandler::SetObject(const std::string & item)
{
  _sock->sendMsg(("Set " + item + "\n").c_str());
  _sock->recvMsg();
}

void EventHandler::Incantation()
{
  _sock->sendMsg("Incantation\n");
  _sock->recvMsg();
}
