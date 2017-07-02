/*
** command_map.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 23 13:00:06 2017 Guillaume CAUCHOIS
** Last update Sun Jul 02 19:21:46 2017 Pierre
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server/map.h"
#include "server/server.h"
#include "server/client.h"
#include "server/string.h"

void	command_msz(t_server *server, t_client *client, char *arg)
{
  char	*str;

  (void)arg;
  if (!(str = malloc(sizeof(char) * 400)))
    return;
  if (!(sprintf(str, "msz %d %d\n", server->map->width, server->map->height)))
    return ;
  send_socket(client->fd, str);
  free(str);
}

char		*quantities_to_string(int *qts)
{
  char		*string;
  int		len_write;
  t_stuff_type	type;
  size_t	limit;

  len_write  = 0;
  type = STUFF_MIN;
  if (!(string = malloc(sizeof(char) * 400)))
    return (NULL);
  bzero(string, sizeof(char) * 400);
  while (type < STUFF_MAX)
    {
      limit = (400 - len_write >= 0) ? (size_t)(400 - len_write) : 0;
      len_write += snprintf(string + len_write, limit, " %d", qts[type++]);
    }
  return (string);
}

void	command_bct_at_position(t_server *server, t_client *client,
				unsigned int x, unsigned int y)
{
  char	*buf;
  char	*qts;

  if (x >= server->map->width || y >= server->map->height)
    {
      send_socket(client->fd, "sbp\n");
      return;
    }
  if (!(buf = malloc(sizeof(char) * 400)))
    return;
  if (!(qts = quantities_to_string(server->map->data[y][x].stuff->quantities)))
    return;
  snprintf(buf, 400, "bct %d %d%s\n", x, y, qts);
  send_socket(client->fd, buf);
  free(buf);
  free(qts);
}

void		command_bct(t_server *server, t_client *client, char *arg)
{
  unsigned int	x;
  unsigned int	y;
  char		*buf;

  (void)server;
  (void)arg;
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

void		command_mct(t_server *server, t_client *client, char *arg)
{
  unsigned int	x;
  unsigned int	y;

  (void)arg;
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

void		command_mct_all_graphics(t_server *server)
{
  t_list	*cur_client_node;
  t_client	*client;

  cur_client_node = server->clients;
  while (cur_client_node)
    {
      client = cur_client_node->data;
      if (client->type == GRAPHIC)
	command_mct(server, client, NULL);
      cur_client_node = cur_client_node->next;
    }
}
