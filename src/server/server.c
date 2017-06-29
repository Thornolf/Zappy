/*
** server.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 21 16:06:13 2017 Guillaume CAUCHOIS
** Last update Thu Jun 29 14:40:27 2017 Guillaume CAUCHOIS
*/

#include <signal.h>
#include "server/server.h"
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
  send_socket(client->fd, "WELCOME\n");
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
  s_conf.waiting_cmds = NULL;
  s_conf.endwait = -1;
  s_conf.timeout.tv_sec = 1;
  s_conf.timeout.tv_usec = 0;
  s_conf.freq = info->freq;
  s_conf.server_read = server_read;
  s_conf.team_size = info->clientsNb;
  if (!handle_io(&fd_read, &fd_write, &s_conf))
    return (false);
  remove_list(s_conf.cmds, &delete_command);
  remove_list(s_conf.clients, &delete_client);
  delete_map(s_conf.map);
  return (true);
}

void check_waiting_cmds(t_server *server)
{
  t_command *cmd;
  t_client *client;

  if (server->waiting_cmds != NULL)
    {
      if (server->endwait == -1)
	{
	  cmd = server->waiting_cmds->cmd;
	  server->endwait = time(NULL) + (cmd->action_time / server->freq);
	}
      else if (server->endwait != -1 && time(NULL) > server->endwait)
	{
	  cmd = server->waiting_cmds->cmd;
	  client = server->waiting_cmds->client;
	  cmd->fn(server, client);
	  printf("on a lancé la commande %s\n", cmd->cmd_name);
	  server->endwait = -1;
	  server->waiting_cmds = server->waiting_cmds->next;
	}
    }
}

bool		handle_io(fd_set *fd_read, fd_set *fd_write, t_server *server)
{
  int		fd_max;
  t_list	*cur_client_node;
  t_client	*client;
  bool		go_on;

  go_on = true;
  while (go_on)
    {
      fd_max = get_fd_max(server);
      FD_ZERO(fd_read);
      FD_SET(server->fd, fd_read);
      cur_client_node= server->clients;
      while (cur_client_node)
	{
	  client = cur_client_node->data;
	  FD_SET(client->fd, fd_read);
	  cur_client_node = cur_client_node->next;
	}
      check_waiting_cmds(server);
      go_on = (select(fd_max + 1, fd_read, fd_write, NULL, &server->timeout) >= 0);
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
      check_waiting_cmds(server);
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
