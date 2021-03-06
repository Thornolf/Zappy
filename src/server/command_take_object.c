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

void		command_take_object(t_server *server, t_client *client, char *arg)
{
  t_player	*p;
  t_stuff	*stuff;

  (void)arg;
  if (!(p = get_player(server->players, client->fd)))
    {
      send_socket(client->fd, "ko\n");
      return;
    }
  stuff = server->map->data[p->y][p->x].stuff;
  if (check_object(client->object_id, stuff) == 1)
    {
      server->map->data[p->y][p->x].stuff->quantities[client->object_id]--;
      p->stuff->quantities[client->object_id]++;
      send_socket(client->fd, "ok\n");
      command_pgt(server, client, NULL);
      command_bct_at_pos_graphics(server, p->x, p->y);
    }
  else
    send_socket(client->fd, "ko\n");
}

void		command_pgt(t_server *server, t_client *client, char *arg)
{
  char		*buffer;
  t_player	*player;

  (void)arg;
  if (!(player = get_player(server->players, client->fd)))
    return;
  if (!(buffer = malloc(sizeof(char) * 500)))
    return;
  snprintf(buffer, 500, "pgt %d %d\n", player->id, client->object_id);
  send_all_graphics(server, buffer);
  free(buffer);
}
