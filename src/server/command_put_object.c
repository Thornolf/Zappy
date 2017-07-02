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
#include "server/communication.h"

void	command_put_object(t_server *server, t_client *client, char *arg)
{
  t_player *player;
  t_stuff *stuff;

  (void)arg;
  if (!(player = get_player(server->players, client->fd)))
    return;
  stuff = player->stuff;
  if (check_object(client->object_id, stuff) == 1)
  {
    server->map->data[player->y][player->x].stuff->quantities[client->object_id]++;
    player->stuff->quantities[client->object_id]--;
    send_socket(client->fd, "ok\n");
    command_pdr(server, client, NULL);
  }
  else
  {
    send_socket(client->fd, "ko\n");
  }
}

void	command_pdr(t_server *server, t_client *client, char *arg)
{
  char		*buffer;
  t_player	*player;

  (void)arg;
  if (!(player = get_player(server->players, client->fd)))
    return;
  if (!(buffer = malloc(sizeof(char) * 500)))
    return;
  snprintf(buffer, 500, "pdr %d %d\n", player->id, client->object_id);
  send_all_graphics(server,buffer);
  free(buffer);
}
