/*
** command_connect_nbr.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 29 10:52:23 2017 Pierre
** Last update Thu Jun 29 17:09:21 2017 Pierre
*/

#include "server/command.h"
#include "server/string.h"

void command_connect_nbr(t_server *server, t_client *client)
{
  t_list *list;
  t_player *tmp;
  char *team_name;
  int nb;

  list = server->players;
  nb = 0;
  tmp = get_player(server->players, client->fd);
  team_name = strdup(tmp->team->name);
  while (list)
    {
      tmp = list->data;
      if (strcmp(tmp->team->name, team_name) == 0)
	      nb++;
      list = list->next;
    }
  send_socket(client->fd, itos(server->team_size - nb));
  send_socket(client->fd, "\n");
}
