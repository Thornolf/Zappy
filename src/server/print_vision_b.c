/*
** print_vision_b.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sat Jun 24 12:51:22 2017 Pierre
** Last update Thu Jun 29 15:27:50 2017 Pierre
*/

#include "server/command.h"

void print_food(int fd)
{
  send_socket(fd, "food");
}

void print_linemate(int fd)
{
  send_socket(fd, "linemate");
}

void print_deraumere(int fd)
{
  send_socket(fd, "deraumere");
}

void print_sibur(int fd)
{
  send_socket(fd, "sibur");
}

void print_thystame(int fd)
{
  send_socket(fd, "thystame");
}
