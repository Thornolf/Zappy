/*
** command_map.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 23 13:00:06 2017 Guillaume CAUCHOIS
** Last update Fri Jun 23 13:00:06 2017 Guillaume CAUCHOIS
*/

#include "server/map.h"
#include "server/server.h"
#include "server/client.h"
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

/**
 * Permit to send to the client the size of the map
 * @param server
 */
void	command_msz(t_server *server, t_client *client)
{
  char	*str;

  if (!(str = malloc(sizeof(char) * 400)))
    return;
  if (!(sprintf(str, "msz %d %d\r\n", server->map->x, server->map->y)))
    return ;
  send(client->fd, str, strlen(str), 0);
  free(str);
}