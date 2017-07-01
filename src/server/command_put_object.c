/*
** command_put_object.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 29 15:36:57 2017 Pierre
** Last update Sat Jul 01 23:40:07 2017 Pierre
*/

#include "server/command.h"

void	command_put_object(t_server *server, t_client *client)
{
  t_player *player;
  t_stuff *stuff;

  player = get_player(server->players, client->fd);
  stuff = player->stuff;
  if (check_object(client->object_id, stuff) == 1)
  {
    server->map->data[player->y][player->x].stuff->quantities[client->object_id]++;
    player->stuff->quantities[client->object_id]--;
    send_socket(client->fd, "ok\n");
  }
  else
  {
    send_socket(client->fd, "ko\n");
  }
}
