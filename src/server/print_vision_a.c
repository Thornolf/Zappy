/*
** print_vision_a.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sat Jun 24 12:51:13 2017 Pierre
** Last update Thu Jun 29 14:39:47 2017 Guillaume CAUCHOIS
*/

#include "server/command.h"

void print_mendiane(int fd)
{
  send_socket(fd, "mendiane");
}

void print_phiras(int fd)
{
  send_socket(fd, "phiras");
}

void print_thystame(int fd)
{
  send_socket(fd, "thystame");
}

void	init_print_cmds(void (*print_stuff_cmds[7])(int fd))
{
  print_stuff_cmds[FOOD]	= &print_food;
  print_stuff_cmds[LINEMATE]	= &print_linemate;
  print_stuff_cmds[DERAUMERE]	= &print_deraumere;
  print_stuff_cmds[SIBUR]	= &print_sibur;
  print_stuff_cmds[MENDIANE]	= &print_mendiane;
  print_stuff_cmds[PHIRAS]	= &print_phiras;
  print_stuff_cmds[THYSTAME]	= &print_thystame;
}

void	print_objects(int player_fd, t_list *list_player, t_vision *vision)
{
  t_vision	*tmp;
  t_list	*players;
  int		index;
  void		(*print_stuff_cmds[7])(int fd);

  init_print_cmds(print_stuff_cmds);
  tmp = vision;
  index = 0;
  send_socket(player_fd, "[player");
  while (tmp)
    {
      players = list_player;
      while (players)
	{
	  send_socket(player_fd, " player");
	  players = players->next;
	}
      index = 0;
      while (index <= STUFF_MAX)
	{
	  send_socket(player_fd, " ");
	  (*print_stuff_cmds[index])(player_fd);
	  index++;
	}
      if (tmp->next)
	send_socket(player_fd, ",");
      tmp = tmp->next;
    }
  send_socket(player_fd, "]\n");
}
