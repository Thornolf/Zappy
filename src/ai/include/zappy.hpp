/*
** zappy.hpp for PSU_2016_zappy in /home/fossae_t/rendu2/PSU_2016_zappy/src/ai/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Jun 20 10:41:59 2017 Thomas Fossaert
** Last update Tue Jun 20 12:31:23 2017 Thomas Fossaert
*/

#ifndef   MUSIC_HPP_
# define  MUSIC_HPP_

# include <iostream>
# include "ZappException.hpp"

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
};

#endif
