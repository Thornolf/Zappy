/*
** command_broadcast.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue Jun 27 18:47:00 2017 Pierre
** Last update Sun Jul 02 13:19:06 2017 Pierre
*/

#include "server/command.h"
#include "server/communication.h"

void	command_broadcast(t_server *server, t_client *client, char *arg)
{
  command_pbc(server, client, arg);
}

void	command_pbc(t_server *server, t_client *client, char *msg)
{
  char		*buf;
  t_player	*player;

  if (!msg)
    return;
  if (!(buf = malloc(sizeof(char) * 400)))
    return;
  if (!(player = get_player(server->players, client->fd)))
    return;
  snprintf(buf, 400, "pbc %d %s\n", player->id, msg);
  send_all_graphics(server, buf);
  free(buf);
}
