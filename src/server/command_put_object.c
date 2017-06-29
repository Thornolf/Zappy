/*
** command_put_object.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 29 15:36:57 2017 Pierre
** Last update Thu Jun 29 15:49:51 2017 Pierre
*/

#include "server/command.h"

void	command_put_object(t_server *server, t_client *client)
{
  t_player *player;
  t_stuff *stuff;
  int object_id;

  if ((object_id = check_arg(strtok(NULL, " \t\n"))) == -1)
    {
      send_socket(client->fd, "ko\n");
      return ;
    }
  player = get_player(server->players, client->fd);
  stuff = player->stuff;
  if (check_object(object_id, stuff) == 1)
  {
    server->map->data[player->y][player->x].stuff->quantities[object_id]++;
    player->stuff->quantities[object_id]--;
    send_socket(client->fd, "ok\n");
  }
  else
    send_socket(client->fd, "ko\n");
}
