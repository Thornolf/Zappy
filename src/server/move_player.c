/*
** move_player.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sun Jun 25 15:16:16 2017 Pierre
** Last update Sun Jun 25 15:32:38 2017 Pierre
*/

#include "server/server.h"

void turn_left(t_map *map, t_player *player)
{
  int new_dir;

  (void) map;
  new_dir = player->direction;
  new_dir--;
  if (new_dir < 0)
    new_dir = LEFT;
  player->direction = new_dir;
  printf("ok\n");
}

void turn_right(t_map *map, t_player *player)
{
  int new_dir;

  (void) map;
  new_dir = player->direction;
  new_dir++;
  if (new_dir > 3)
    new_dir = TOP;
  player->direction = new_dir;
  printf("ok\n");
}

void move_player(t_map *map, t_player *player)
{
  if (player->direction == TOP)
    player->y = check_y(map->height, player->y - 1);
  else if (player->direction == BOTTOM)
    player->y = check_y(map->height, player->y + 1);
  else if (player->direction == LEFT)
    player->x = check_x(map->width, player->x - 1);
  else if (player->direction == RIGHT)
    player->x = check_x(map->width, player->x + 1);
  printf("ok\n");
}
