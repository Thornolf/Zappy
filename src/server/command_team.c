/*
** command_team.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon Jun 26 16:25:27 2017 Guillaume CAUCHOIS
** Last update Mon Jun 26 16:25:27 2017 Guillaume CAUCHOIS
*/

#include "server/command.h"
#include "server/socket.h"

void		command_tna(t_server *server, t_client *client)
{
  t_list	*cur_node;
  t_team	*team;

  cur_node = server->teams;
  (void)server;
  send_socket(client->fd, "tna");
  while (cur_node)
  {
    team = cur_node->data;
    send_socket(client->fd, " ");
    send_socket(client->fd, team->name);
    cur_node = cur_node->next;
  }
  send_socket(client->fd, "\n");
}