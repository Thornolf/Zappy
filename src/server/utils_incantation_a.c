/*
** utils_incantation_a.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sat Jul 01 15:12:50 2017 Pierre
** Last update Sat Jul 01 23:41:29 2017 Pierre
*/

#include "server/command.h"

int nb_players(t_list *players, int y, int x)
{
  t_player *player;
  int nb;

  nb = 0;
  while (players)
  {
    player = players->data;
    if (player->y == y && player->x == x)
      nb++;
    players = players->next;
  }
  return (nb);
}

int check_level_2(void *_server, int y, int x)
{
  t_stuff *tile;
  t_server *server;

  server = _server;
  tile = server->map->data[y][x].stuff;
  if (tile->quantities[LINEMATE] == 1 &&
      tile->quantities[DERAUMERE] == 0 &&
      tile->quantities[SIBUR] == 0 &&
      tile->quantities[MENDIANE] == 0 &&
      tile->quantities[PHIRAS] == 0 &&
      tile->quantities[THYSTAME] == 0)
    return (1);
  return (0);
}

int check_level_3(void *_server, int y, int x)
{
  t_stuff *tile;
  t_server *server;

  server = _server;
  if (nb_players(server->players, y, x) == 2)
    return (0);
  tile = server->map->data[y][x].stuff;
  if (tile->quantities[LINEMATE] == 1 &&
      tile->quantities[DERAUMERE] == 1 &&
      tile->quantities[SIBUR] == 1 &&
      tile->quantities[MENDIANE] == 0 &&
      tile->quantities[PHIRAS] == 0 &&
      tile->quantities[THYSTAME] == 0)
    return (1);
  return (0);
}

int check_level_4(void *_server, int y, int x)
{
  t_stuff *tile;
  t_server *server;

  server = _server;
  if (nb_players(server->players, y, x) == 2)
    return (0);
  tile = server->map->data[y][x].stuff;
  if (tile->quantities[LINEMATE] == 2 &&
      tile->quantities[DERAUMERE] == 0 &&
      tile->quantities[SIBUR] == 1 &&
      tile->quantities[MENDIANE] == 0 &&
      tile->quantities[PHIRAS] == 2 &&
      tile->quantities[THYSTAME] == 0)
    return (1);
  return (0);
}

int check_level_5(void *_server, int y, int x)
{
  t_stuff *tile;
  t_server *server;

  server = _server;
  if (nb_players(server->players, y, x) == 4)
    return (0);
  tile = server->map->data[y][x].stuff;
  if (tile->quantities[LINEMATE] == 1 &&
      tile->quantities[DERAUMERE] == 1 &&
      tile->quantities[SIBUR] == 2 &&
      tile->quantities[MENDIANE] == 0 &&
      tile->quantities[PHIRAS] == 1 &&
      tile->quantities[THYSTAME] == 0)
    return (1);
  return (0);
}
