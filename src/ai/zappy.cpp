/*
** zappy.cpp for PSU_2016_zappy in /home/fossae_t/rendu2/PSU_2016_zappy/src/ai
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Wed Jun 21 09:19:57 2017 Thomas Fossaert
** Last update Fri Jun 23 14:37:55 2017 Thomas Fossaert
*/

#include "zappy.hpp"

Zappy::Zappy(char **av)
{
  int i = 1;

  while (av[i])
    {
      if (std::string(av[i -1]) == "-p")
        this->_port = std::string(av[i]);
      else if (std::string(av[i -1]) == "-n")
        this->_teamName = std::string(av[i]);
      else if (std::string(av[i -1]) == "-h")
        this->_machineName = std::string(av[i]);
      i++;
    }
  if (_port.empty() || _teamName.empty() || _machineName.empty())
    throw ZappException("An argument was not defined");
}

Zappy::~Zappy()
{
}

Zappy::Zappy(Zappy const & other)
{
  (void)other;
}

Zappy& Zappy::operator=(Zappy const & other)
{
  (void)other;
  return *this;
}

void Zappy::init(void)
{
  _sock = new Socket(_machineName, _port);
  _sock->recvMsg();
  _sock->sendMsg((_teamName + "\n").c_str());
  if (_sock->getLastMsg() == "ko\n")
    throw ZappException("This team does not exist");
  _sock->recvMsg();
  _event = new EventHandler(_sock);
  _event->launchScript();
  /*while (42)
    {
      _sock->sendMsg("Forward\n");
      _sock->recvMsg();
      _sock->sendMsg("Look\n");
      _sock->recvMsg();
      _sock->sendMsg("Take food\n");
      _sock->recvMsg();
    }*/
}
