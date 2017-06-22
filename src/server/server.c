/*
** server.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 21 16:06:13 2017 Guillaume CAUCHOIS
** Last update Thu Jun 22 19:15:35 2017 Pierre
*/

#include "server/server.h"
#include "server/funcs.h"
#include "server/socket.h"
#include "server/player.h"
#include "server/client.h"

void	server_read(void *_server)
{
  t_server	*server;
  t_client	*client;
  t_list	*clientnode;

  server = _server;
  client = init_client(server);
  if (!(clientnode = create_node(client, server->clients)))
  {
    fprintf(stderr, "ERROR: A client try to connect but something went wrong...\n");
    return;
  }
  server->clients = clientnode;
}

void	server_write(void *server)
{
  (void)server;
}

bool	init_zappy_server(t_info *info)
{
  t_map			*map;
  t_server		s_conf;
  fd_set		fd_read;
  fd_set		fd_write;

  if (!(map = create_empty_map(info->width, info->height)))
    return (84);
  init_elems_cmds(info);
  fill_up_map_randomly(map);
  if ((s_conf.fd = open_socket(info->port)) == -1)
    return (false);
  listen_socket(s_conf.fd);
  s_conf.clients = NULL;
  s_conf.server_read = server_read;
  s_conf.server_write = server_write;
  if (!handle_io(&fd_read, &fd_write, &s_conf))
    return (false);
  return (true);
}

bool		handle_io(fd_set *fd_read, fd_set *fd_write, t_server *server)
{
  struct timeval	tv;
  bool			go_on;
  int			fd_max;
  t_list		*cur_client_node;
  t_client		*client;

  set_time_out(&tv);
  go_on = true;
  while (go_on)
  {
    fd_max = get_fd_max(server);
    FD_ZERO(fd_read);
    FD_ZERO(fd_write);
    FD_SET(server->fd, fd_read);
    cur_client_node= server->clients;
    while (cur_client_node)
    {
      client = cur_client_node->data;
      FD_SET(client->fd, fd_read);
      cur_client_node = cur_client_node->next;
    }
    go_on = (select(fd_max + 1, fd_read, fd_write, NULL, &tv) != 0);
    if (FD_ISSET(server->fd, fd_read))
      server->server_read(server);
    cur_client_node= server->clients;
    while (cur_client_node)
    {
      client = cur_client_node->data;
      if (FD_ISSET(client->fd, fd_read))
	client->fct_read(server, cur_client_node);
      cur_client_node = cur_client_node->next;
    }
  }
  return (true);
}

int		get_fd_max(t_server *server)
{
  t_list	*cur;
  t_client	*client;
  int		fd_max;

  fd_max = server->fd;
  cur = server->clients;
  while (cur)
  {
    client = cur->data;
    if (client->fd > fd_max)
      fd_max = client->fd;
    cur = cur->next;
  }
  return (fd_max);
}