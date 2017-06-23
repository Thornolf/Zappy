/*
** look.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Fri Jun 23 09:55:55 2017 Pierre
** Last update Fri Jun 23 14:51:38 2017 Pierre
*/

#include "server/server.h"
#include "server/look.h"

t_vision *look_top(t_vision *vision, t_map *map, t_player *player)
{
  t_it it;

  it.line_end = player->lv + 1;
  it.line = 1;
  it.end = 0;
  it.y = player->y;
  while (it.line <= it.line_end)
  {
    it.max_end = 0 + it.end;
    it.i = 0 - it.end;
    while (it.i <= it.max_end)
    {
      it.x = check_x(map->width, player->x + it.i);
      if (vision == NULL)
        vision = init_vision(it.y, it.x);
      else
        add_case_vision(vision, it.y, it.x);
      it.i++;
    }
    it.line++;
    it.y = check_y(map->height, it.y - 1);
    it.end++;
  }
  return (vision);
}

t_vision *look_bottom(t_vision *vision, t_map *map, t_player *player)
{
  t_it it;

  it.line_end = player->lv + 1;
  it.line = 1;
  it.end = 0;
  it.y = player->y;
  while (it.line <= it.line_end)
  {
    it.max_end = 0 + it.end;
    it.i = 0 - it.end;
    while (it.i <= it.max_end)
    {
      it.x = check_x(map->width, player->x - it.i);
      if (vision == NULL)
        vision = init_vision(it.y, it.x);
      else
        add_case_vision(vision, it.y, it.x);
      it.i++;
    }
    it.line++;
    it.y = check_y(map->height, it.y + 1);
    it.end++;
  }
  return (vision);
}

t_vision *look_right(t_vision *vision, t_map *map, t_player *player)
{
  t_it it;

  it.line_end = player->lv + 1;
  it.line = 1;
  it.end = 0;
  it.x = player->x;
  while (it.line <= it.line_end)
  {
    it.max_end = 0 + it.end;
    it.i = 0 - it.end;
    while (it.i <= it.max_end)
    {
      it.y = check_y(map->height, player->y + it.i);
      if (vision == NULL)
        vision = init_vision(it.y, it.x);
      else
        add_case_vision(vision, it.y, it.x);
      it.i++;
    }
    it.line++;
    it.x = check_x(map->width, it.x + 1);
    it.end++;
  }
  return (vision);
}

t_vision *look_left(t_vision *vision, t_map *map, t_player *player)
{
  t_it it;

  it.line_end = player->lv + 1;
  it.line = 1;
  it.end = 0;
  it.x = player->x;
  while (it.line <= it.line_end)
  {
    it.max_end = 0 + it.end;
    it.i = 0 - it.end;
    while (it.i <= it.max_end)
    {
      it.y = check_y(map->height, player->y - it.i);
      if (vision == NULL)
        vision = init_vision(it.y, it.x);
      else
        add_case_vision(vision, it.y, it.x);
      it.i++;
    }
    it.line++;
    it.x = check_x(map->width, it.x - 1);
    it.end++;
  }
  return (vision);
}

void      print_vision(t_vision *head)
{
  t_vision *tmp;

  tmp = head;
  while (tmp)
  {
    printf("Case %d à [%d][%d]\n", tmp->case_nb, tmp->y, tmp->x);
    tmp = tmp->next;
  }
}

void print_food(void)
{
  printf("food");
}

void print_linemate(void)
{
  printf("linemate");
}

void print_deraumere(void)
{
  printf("deraumere");
}

void print_sibur(void)
{
  printf("sibur");
}

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

void look(t_map *map, t_player *player)
{
  t_vision *vision;

  vision = NULL;
  if (player->direction == TOP)
    vision = look_top(vision, map, player);
  else if (player->direction == BOTTOM)
    vision = look_bottom(vision, map, player);
  else if (player->direction == RIGHT)
    vision = look_right(vision, map, player);
  else if (player->direction == LEFT)
    vision = look_left(vision, map, player);
  print_vision(vision);
  print_objects(map, vision);
}
