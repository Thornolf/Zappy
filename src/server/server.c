/*
** server.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 21 16:06:13 2017 Guillaume CAUCHOIS
** Last update Sun Jun 25 15:39:01 2017 Pierre
*/

#include "server/server.h"
#include "server/funcs.h"
#include "server/socket.h"
#include "server/player.h"
#include "server/client.h"
#include "server/command.h"

void	server_read(void *_server)
{
  t_server	*server;
  t_client	*client;
  t_list	*client_node;
  int		i;
  t_list	*cur;

  server = _server;
  if (!(client = init_client(server)))
    return;
  if (!(client_node = create_node(client, server->clients)))
  {
    fprintf(stderr, "ERROR: A client try to connect but something went wrong...\n");
    return;
  }
  server->clients = client_node;
  cur = server->clients;
  i = 0;
  while (cur)
  {
    i++;
    cur = cur->next;
  }
}

void	server_write(void *_server)
{
  (void)_server;
}

bool	init_zappy_server(t_info *info)
{
  t_server		s_conf;
  fd_set		fd_read;
  fd_set		fd_write;

  if ((s_conf.fd = open_socket(info->port)) == -1)
    return (false);
  if (!(s_conf.map = create_empty_map(info->width, info->height)))
    return (false);
  fill_up_map_randomly(s_conf.map);
  listen_socket(s_conf.fd);
  s_conf.clients = NULL;
  if (!(s_conf.teams = init_team_list(info)))
    return (NULL);
  if (!(s_conf.cmds = init_cmd_callback()))
    return (false);
  s_conf.players = NULL;
  s_conf.server_read = server_read;
  s_conf.server_write = server_write;
  s_conf.team_size = info->clientsNb;
  if (!handle_io(&fd_read, &fd_write, &s_conf))
    return (false);
  remove_list(s_conf.cmds, &delete_command);
  remove_list(s_conf.clients, &delete_client);
  delete_map(s_conf.map);
  return (true);
}

bool		handle_io(fd_set *fd_read, fd_set *fd_write, t_server *server)
{
  bool			go_on;
  int			fd_max;
  t_list		*cur_client_node;
  t_client		*client;

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
    go_on = (select(fd_max + 1, fd_read, fd_write, NULL, NULL) != 0);
    if (FD_ISSET(server->fd, fd_read))
      server->server_read(server);
    cur_client_node = server->clients;
    while (cur_client_node)
    {
      client = cur_client_node->data;
      if (FD_ISSET(client->fd, fd_read))
	cur_client_node = client->fct_read(server, cur_client_node);
      else
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
