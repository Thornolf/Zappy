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

void		concat_quantities_bct(t_server *server, char *buf, unsigned int x, unsigned int y)
{
  char		*n;
  t_stuff_type	type;

  type = STUFF_MIN;
  while (type != STUFF_MAX)
  {
    if (!(buf = strcat(buf, " ")) ||
	!(n = itos(server->map->data[y][x].stuff->quantities[type++])) ||
	!(buf = strcat(buf, n)))
      return;
    free(n);
  }
}

void		command_bct_at_position(t_server *server, t_client *client,
					    unsigned int x, unsigned int y)
{
  char		*buf;
  char		*n;

  if (x >= server->map->width || y >= server->map->height)
  {
    send_socket(client->fd, "sbp\n");
    return;
  }
  if (!(buf = strdup("bct ")) || !(buf = realloc(buf, (strlen(buf) + 40))) ||
      !(n = itos(x)) || !(buf = strcat(buf, n)))
    return;
  free(n);
  if (!(buf = strcat(buf, " ")) || !(n = itos(y)) || !(buf = strcat(buf, n)))
    return;
  concat_quantities_bct(server, buf, x, y);
  if (!(buf = strcat(buf, "\n")) || !send_socket(client->fd, buf))
    return;
  free(buf);
}

void	command_bct(t_server *server, t_client *client)
{
  unsigned int	x;
  unsigned int	y;
  char		*buf;

  (void)server;
  if (!(buf = strtok(NULL, " \t\n")) || !string_is_number(buf))
  {
    send_socket(client->fd, "sbp\n");
    return;
  }
  x = (unsigned int)atoi(buf);
  if (!(buf = strtok(NULL, " \t\n")) || !string_is_number(buf))
  {
    send_socket(client->fd, "sbp\n");
    return;
  }
  y = (unsigned int)atoi(buf);
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