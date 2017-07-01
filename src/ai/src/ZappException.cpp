/*
** ZappException.cpp for PSU_2016_zappy in /home/fossae_t/rendu2/PSU_2016_zappy/src/ai
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Jun 20 12:03:07 2017 Thomas Fossaert
** Last update Thu Jun 29 16:12:20 2017 Pierre
*/

#include "ZappException.hpp"

ZappException::ZappException(std::string msg) throw() : _msg(msg)
{
}

const char *ZappException::what() const throw()
{
  return (_msg.c_str());
}
