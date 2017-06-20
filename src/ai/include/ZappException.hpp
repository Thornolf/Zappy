/*
** ZappException.hpp for PSU_2016_zappy in /home/fossae_t/rendu2/PSU_2016_zappy/src/ai/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Jun 20 12:07:01 2017 Thomas Fossaert
** Last update Tue Jun 20 12:20:51 2017 Thomas Fossaert
*/

#include <exception>
#include <iostream>

class ZappException : public std::exception
{
private:
  std::string _msg;
public:
  ZappException(std::string msg) throw();
  virtual const char* what() const throw();
  virtual ~ZappException() throw() {};
};
