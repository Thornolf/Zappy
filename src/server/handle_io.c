/*
** handle_io.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Jun 29 13:52:59 2017 Guillaume CAUCHOIS
** Last update Thu Jun 29 15:56:25 2017 Guillaume CAUCHOIS
*/

#include "server/server.h"
#include "server/list.h"
#include "server/command.h"

bool		handle_io(fd_set *fd_read, t_server *server)
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
      go_on = (select(fd_max + 1, fd_read, NULL, NULL, &server->timeout) >= 0);
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
