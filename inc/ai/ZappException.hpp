/*
** ZappException.hpp for PSU_2016_zappy in /home/fossae_t/rendu2/PSU_2016_zappy/src/ai/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Jun 20 12:07:01 2017 Thomas Fossaert
** Last update Wed Jun 21 09:52:22 2017 Thomas Fossaert
*/

#ifndef   ZAPPYEXCEPTION_HPP_
# define  ZAPPYEXCEPTION_HPP_


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

#endif
