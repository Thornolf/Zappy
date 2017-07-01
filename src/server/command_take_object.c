/*
** command_take_object.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 29 12:59:50 2017 Pierre
** Last update Fri Jun 30 20:59:56 2017 Pierre
*/

#include "server/command.h"

void	command_take_object(t_server *server, t_client *client)
{
  t_player *player;
  t_stuff *stuff;

  player = get_player(server->players, client->fd);
  stuff = server->map->data[player->y][player->x].stuff;
  if (check_object(server->object_id, stuff) == 1)
    {
      server->map->data[player->y][player->x].stuff->quantities[server->object_id]--;
      player->stuff->quantities[server->object_id]++;
      send_socket(client->fd, "ok\n");
    }
  else
    send_socket(client->fd, "ko\n");
}
