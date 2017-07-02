/*
** command_take_object.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 29 12:59:50 2017 Pierre
** Last update Sun Jul 02 13:30:43 2017 Pierre
*/

#include "server/command.h"
#include "server/communication.h"

void	command_take_object(t_server *server, t_client *client, char *arg)
{
  t_player	*player;
  t_stuff	*stuff;
  char		*buf;

  (void)arg;
  if (!(player = get_player(server->players, client->fd)))
    return;
  stuff = server->map->data[player->y][player->x].stuff;
  if (check_object(client->object_id, stuff) == 1)
    {
      server->map->data[player->y][player->x].stuff->quantities[client->object_id]--;
      player->stuff->quantities[client->object_id]++;
      send_socket(client->fd, "ok\n");
      if (!(buf = malloc(sizeof(char) * 500)))
	       return;
      snprintf(buf, 500, "pgt %d %d\n", player->id, client->object_id);
      send_all_graphics(server, buf);
      free(buf);
    }
  else
    send_socket(client->fd, "ko\n");
}
