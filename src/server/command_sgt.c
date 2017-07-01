/*
** command_sgt.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Jun 29 11:21:10 2017 Guillaume CAUCHOIS
** Last update Sat Jul 01 22:03:44 2017 Pierre
*/

#include "server/command.h"

void	command_sgt(t_server *server, t_client *client)
{
  char	*buf;

  if (!(buf = malloc(sizeof(char) * 100)))
    return;
  snprintf(buf, 100, "sgt %d\n", server->freq);
  send_socket(client->fd, buf);
  free(buf);
}
