/*
** main.cpp for PSU_2016_zappy in /home/fossae_t/rendu2/PSU_2016_zappy/src/ai
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Jun 20 10:06:26 2017 Thomas Fossaert
** Last update Thu Jun 29 16:12:28 2017 Pierre
*/

#include <iostream>
#include "zappy.hpp"

int main(int ac, char **av)
{
  if (ac == 2 && std::string(av[1]) == "-help")
    {
      std::cout << "USAGE: ./zappy_client -p port -n name -h machine" << '\n';
      std::cout << "port is the port number" << '\n';
      std::cout << "name is the name of the team" << '\n';
      std::cout << "machine is the name of the machine; localhost by default" << '\n';
    }
  else if (ac > 2)
    {
      try {
        Zappy *zapp = new Zappy(av);
        zapp->init();
      }
      catch (std::exception const & e)
        {
          std::cerr << "ERROR : " << e.what() << std::endl;
          return (1);
        }
    }
  else
    std::cout << "Not enough argument" << '\n';
  return (0);
}
