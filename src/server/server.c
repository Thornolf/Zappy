/*
** server.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 21 16:06:13 2017 Guillaume CAUCHOIS
** Last update Sun Jul 02 14:41:13 2017 Pierre
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
    fprintf(stderr, "ERROR: Can't initialize server\n");
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

void	init_server_config(t_server *s_conf)
{
  s_conf->players = NULL;
  s_conf->waiting_cmds = NULL;
  s_conf->timeout.tv_sec = 0;
  s_conf->timeout.tv_usec = 1;
  s_conf->food_time = 126 / s_conf->freq;
}

bool	init_zappy_server(t_info *info)
{
  t_server		s_conf;
  fd_set		fd_read;

  if ((s_conf.fd = open_socket(info->port)) == -1)
    return (false);
  if (!(s_conf.map = create_empty_map(info->width, info->height)))
    return (false);
  fill_up_map_randomly(s_conf.map);
  s_conf.clients = NULL;
  if (!(s_conf.teams = init_team_list(info)))
    return (NULL);
  if (!(s_conf.cmds = init_cmd_callback()))
    return (false);
  s_conf.freq = info->freq;
  init_server_config(&s_conf);
  s_conf.server_read = server_read;
  s_conf.team_size = info->clientsNb;
  init_level_cmds(&s_conf);
  listen_socket(s_conf.fd);
  if (!handle_io(&fd_read, &s_conf))
    return (false);
  remove_list(s_conf.cmds, &delete_command);
  remove_list(s_conf.clients, &delete_client);
  delete_map(s_conf.map);
  return (true);
}

void		remove_waiting(t_waiting_cmds **list, t_waiting_cmds *node)
{
  t_waiting_cmds	*prev;
  t_waiting_cmds	*cur;

  if (!list || !node)
    return;
  prev = *list;
  if (prev == node)
  {
    *list = prev->next;
    free(prev);
    return ;
    //fn_delete_node(prev->data);
  }
  cur = prev->next;
  while (cur)
  {
    if (cur == node)
    {
      prev->next = cur->next;
      free(cur);
      //fn_delete_node(cur->data);
      return;
    }
    prev = cur;
    cur = cur->next;
  }
}

void check_waiting_cmds(t_server *server)
{
  t_command *cmd;
  t_client *client;
  t_waiting_cmds *tmp;

  tmp = server->waiting_cmds;
  while (tmp)
    {
      cmd = tmp->cmd;
      if (tmp->endwait == -1)
      {
        client = tmp->client;
        if (strcmp(cmd->cmd_name, "Incantation") == 0 && !client->incant)
        {
          printf("on veut lancer l'incant\n");
          if (!(start_incantation(server, client)))
          {
            tmp->endwait = -1;
            remove_waiting(&server->waiting_cmds, tmp);
            if (!server->waiting_cmds)
              return ;
          }
          else
            tmp->endwait = time(NULL) + (cmd->action_time / server->freq);
        }
        else
          tmp->endwait = time(NULL) + (cmd->action_time / server->freq);
      }
      if (tmp->endwait != -1 && time(NULL) >= tmp->endwait)
{
      client = tmp->client;
      if (strcmp(cmd->cmd_name, "Take") == 0 ||
	  strcmp(cmd->cmd_name, "Set") == 0)
	client->object_id = check_arg(tmp->arg);
      cmd->fn(server, client, tmp->arg);
      remove_waiting(&server->waiting_cmds, tmp);
      if (!server->waiting_cmds)
	return;
    }
    if (tmp->next)
      tmp = tmp->next;
  }
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
