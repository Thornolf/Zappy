/*
** command_team.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon Jun 26 16:25:27 2017 Guillaume CAUCHOIS
** Last update Thu Jun 29 14:50:32 2017 Guillaume CAUCHOIS
*/

#include "server/command.h"
#include "server/socket.h"

void		command_tna(t_server *server, t_client *client)
{
  t_list	*cur_node;
  t_team	*team;
  char		*buf;

  cur_node = server->teams;
  while (cur_node)
    {
      if (!(buf = strdup("tna ")))
	return;
      team = cur_node->data;
      if (!(buf = realloc(buf, sizeof(char) * (strlen(buf) + strlen(team->name) + 2))))
	return;
      if (!(buf = strcat(buf, team->name)))
	return;
      if (!(buf = strcat(buf, "\n")))
	return;
      send_socket(client->fd, buf);
      free(buf);
      cur_node = cur_node->next;
    }
}
