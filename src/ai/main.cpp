/*
** main.cpp for PSU_2016_zappy in /home/fossae_t/rendu2/PSU_2016_zappy/src/ai
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Jun 20 10:06:26 2017 Thomas Fossaert
** Last update Sun Jul 02 17:22:31 2017 Thomas Fossaert
*/

#include <iostream>
#include "ai/zappy.hpp"

int main(int ac, char **av)
{
  if (ac == 2 && std::string(av[1]) == "-help")
    {
      std::cout << "USAGE: ./zappy_client -p port -n name -h machine" << '\n';
      std::cout << "\t -p port is the port number" << '\n';
      std::cout << "\t -n name is the name of the team" << '\n';
      std::cout << "\t -h machine is the name of the machine; localhost by default" << '\n';
    }
  else if (ac > 2)
    {
      try {
        Zappy *zapp = new Zappy(av);
        zapp->init();
        delete zapp;
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
