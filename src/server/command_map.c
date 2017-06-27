/*
** command_map.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 23 13:00:06 2017 Guillaume CAUCHOIS
** Last update Fri Jun 23 18:44:47 2017 Pierre
*/

#include "server/map.h"
#include "server/server.h"
#include "server/client.h"
#include "server/string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Permit to send to the client the size of the map
 * @param server
 */
void	command_msz(t_server *server, t_client *client)
{
  char	*str;

  if (!(str = malloc(sizeof(char) * 400)))
    return;
  if (!(sprintf(str, "msz %d %d\r\n", server->map->width, server->map->height)))
    return ;
  send_socket(client->fd, str);
  free(str);
}

void		command_bct_at_position(t_server *server, t_client *client, unsigned int x, unsigned int y)
{
  char		*str;
  t_stuff_type	type = STUFF_MIN;

  if (x >= server->map->width || y >= server->map->height)
  {
    send_socket(client->fd, "sbp\n");
    return;
  }
  if (!(str = malloc(sizeof(char) * 400)))
    return;
  snprintf(str, 400, "bct %d %d", x, y);
  send_socket(client->fd, str);
  while (type != STUFF_MAX)
  {
    snprintf(str, 400, " %d", server->map->data[y][x].stuff->quantities[type]);
    send_socket(client->fd, str);
    type += 1;
  }
  send_socket(client->fd, "\n");
  free(str);
}

void	command_bct(t_server *server, t_client *client)
{
  int	x;
  int	y;
  char	*buf;

  (void)server;
  if (!(buf = strtok(NULL, " \t\n")) || !string_is_number(buf))
  {
    send_socket(client->fd, "sbp\n");
    return;
  }
  x = atoi(buf);
  if (!(buf = strtok(NULL, " \t\n")) || !string_is_number(buf))
  {
    send_socket(client->fd, "sbp\n");
    return;
  }
  y = atoi(buf);
  command_bct_at_position(server, client, x, y);
}

void		command_mct(t_server *server, t_client *client)
{
  unsigned int	x;
  unsigned int	y;

  x = 0;
  while (x != server->map->width)
  {
    y = 0;
    while (y != server->map->height)
    {
      command_bct_at_position(server, client, x, y);
      y++;
    }
    x++;
  }
}