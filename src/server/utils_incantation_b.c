/*
** utils_incantation_b.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sat Jul 01 15:13:00 2017 Pierre
** Last update Sat Jul 01 15:13:57 2017 Pierre
*/

#include "server/command.h"

int check_level_6(void *_server, int y, int x)
{
  t_stuff *tile;
  t_server *server;

  server = _server;
  if (nb_players(server->players, y, x) == 4)
    return (0);
  tile = server->map->data[y][x].stuff;
  if (tile->quantities[LINEMATE] == 1 &&
      tile->quantities[DERAUMERE] == 2 &&
      tile->quantities[SIBUR] == 1 &&
      tile->quantities[MENDIANE] == 3 &&
      tile->quantities[PHIRAS] == 0 &&
      tile->quantities[THYSTAME] == 0)
    return (1);
  return (0);
}

int check_level_7(void *_server, int y, int x)
{
  t_stuff *tile;
  t_server *server;

  server = _server;
  if (nb_players(server->players, y, x) == 6)
    return (0);
  tile = server->map->data[y][x].stuff;
  if (tile->quantities[LINEMATE] == 1 &&
      tile->quantities[DERAUMERE] == 2 &&
      tile->quantities[SIBUR] == 3 &&
      tile->quantities[MENDIANE] == 0 &&
      tile->quantities[PHIRAS] == 1 &&
      tile->quantities[THYSTAME] == 0)
    return (1);
  return (0);
}

int check_level_8(void *_server, int y, int x)
{
  t_stuff *tile;
  t_server *server;

  server = _server;
  if (nb_players(server->players, y, x) == 6)
    return (0);
  tile = server->map->data[y][x].stuff;
  if (tile->quantities[LINEMATE] == 2 &&
      tile->quantities[DERAUMERE] == 2 &&
      tile->quantities[SIBUR] == 2 &&
      tile->quantities[MENDIANE] == 2 &&
      tile->quantities[PHIRAS] == 2 &&
      tile->quantities[THYSTAME] == 1)
    return (1);
  return (0);
}

void init_level_cmds(t_server *server)
{
  server->check_level_cmds[0] = check_level_2;
  server->check_level_cmds[1] = check_level_3;
  server->check_level_cmds[2] = check_level_4;
  server->check_level_cmds[3] = check_level_5;
  server->check_level_cmds[4] = check_level_6;
  server->check_level_cmds[5] = check_level_7;
  server->check_level_cmds[6] = check_level_8;
}
