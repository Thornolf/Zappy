/*
** command_connect_nbr.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 29 10:52:23 2017 Pierre
** Last update Sun Jul 02 13:21:23 2017 Pierre
*/

#include "server/command.h"
#include "server/string.h"

void command_connect_nbr(t_server *server, t_client *client, char *arg)
{
  t_list	*list;
  t_player	*tmp;
  char		*team_name;
  char *str;
  int		nb;

  (void)arg;
  list = server->players;
  nb = 0;
  tmp = get_player(server->players, client->fd);
  if (!(team_name = strdup(tmp->team->name)))
    return ;
  while (list)
    {
      tmp = list->data;
      if (strcmp(tmp->team->name, team_name) == 0)
	      nb++;
      list = list->next;
    }
  free(team_name);
  if (!(str = malloc(sizeof(char) * 15)))
    return ;
  snprintf(str, 15, "%d\n", server->team_size - nb);
  send_socket(client->fd, str);
  free(str);
}
