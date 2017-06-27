/*
** print_vision_a.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sat Jun 24 12:51:13 2017 Pierre
** Last update Sat Jun 24 12:52:23 2017 Pierre
*/

#include "server/look.h"

void print_mendiane(void)
{
  printf("mendiane");
}

void print_phiras(void)
{
  printf("phiras");
}

void print_thystame(void)
{
  printf("thystame");
}

void	init_print_cmds(void (*print_stuff_cmds[7])(void))
{
  print_stuff_cmds[FOOD]	= print_food;
  print_stuff_cmds[LINEMATE]	= print_linemate;
  print_stuff_cmds[DERAUMERE]	= print_deraumere;
  print_stuff_cmds[SIBUR]	= print_sibur;
  print_stuff_cmds[MENDIANE]	= print_mendiane;
  print_stuff_cmds[PHIRAS]	= print_phiras;
  print_stuff_cmds[THYSTAME]	= print_thystame;
}

void	print_objects(t_list *list_player, t_vision *vision)
{
  t_vision	*tmp;
  t_list	*players;
  int		index;
  void		(*print_stuff_cmds[7])(void);

  init_print_cmds(print_stuff_cmds);
  tmp = vision;
  index = 0;
  printf("[player");
  while (tmp)
  {
    players = list_player;
    while (players)
    {
      printf(" player");
      players = players->next;
    }
    index = 0;
    while (index <= STUFF_MAX)
    {
      printf(" ");
      (*print_stuff_cmds[index])();
      index++;
    }
    if (tmp->next)
      printf(",");
    tmp = tmp->next;
  }
  printf("]\n");
}
