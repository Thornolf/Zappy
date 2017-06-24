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

void init_print_cmds()
{
  print_stuff_cmds[0] = print_food;
  print_stuff_cmds[1] = print_linemate;
  print_stuff_cmds[2] = print_deraumere;
  print_stuff_cmds[3] = print_sibur;
  print_stuff_cmds[4] = print_mendiane;
  print_stuff_cmds[5] = print_phiras;
  print_stuff_cmds[6] = print_thystame;
}

void print_objects(t_map *map, t_vision *vision)
{
  t_vision *tmp;
  t_stuff *cell;
  t_list *players;

  init_print_cmds();
  tmp = vision;
  cell = NULL;
  printf("[player");
  while (tmp)
  {
    players = map->data[tmp->y][tmp->x].player_list;
    while (players)
    {
      printf(" player");
      players = players->next;
    }
    cell = map->data[tmp->y][tmp->x].stuff_list;
    while (cell)
    {
      printf(" ");
      (*print_stuff_cmds[cell->stuff])();
      cell = cell->next;
    }
    if (tmp->next)
      printf(",");
    tmp = tmp->next;
  }
  printf("]\n");
}
