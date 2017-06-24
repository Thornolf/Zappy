/*
** look.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Fri Jun 23 09:55:55 2017 Pierre
** Last update Sat Jun 24 12:52:44 2017 Pierre
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
  print_vision(vision); //Fonction temporaire pour checker les coordonnées
  print_objects(map, vision);
}
