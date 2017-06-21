/*
** zappy.hpp for PSU_2016_zappy in /home/fossae_t/rendu2/PSU_2016_zappy/src/ai/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Jun 20 10:41:59 2017 Thomas Fossaert
** Last update Wed Jun 21 12:42:14 2017 Thomas Fossaert
*/

#ifndef   ZAPPY_HPP_
# define  ZAPPY_HPP_

# include <iostream>
# include "ZappException.hpp"
# include "Socket.hpp"
# include "EventHandler.hpp"

class Zappy
{
  public:
    Zappy(char **);
    Zappy(Zappy const & other);
    ~Zappy();
    Zappy& operator=(Zappy const & other);

    void init(void);

    private:
      std::string _port;
      std::string _teamName;
      std::string _machineName;
      Socket *_sock;
      EventHandler *_event;
};

#endif
