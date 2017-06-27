/*
** command_client.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon Jun 26 15:38:05 2017 Guillaume CAUCHOIS
** Last update Mon Jun 26 15:38:05 2017 Guillaume CAUCHOIS
*/

#include "server/command.h"
#include "server/player.h"

void	connection_graphic(t_server *server, t_client *client)
{
  set_client_type(client, GRAPHIC);
  command_msz(server, client);
  command_mct(server, client);
}

bool	connection_ia(t_server *server, t_client *client, char *team_name)
{
  t_list	*cur;
  t_player	*player;
  char		*buf;

  if (!(buf = malloc(sizeof(char) * 400)))
    return (false);
  cur = server->players;
  while (cur)
  {
    player = cur->data;
    if (player->fd == client->fd)
    {
      if (nb_player_in_team(server, team_name) + 1 > server->team_size)
      {
	send_socket(client->fd, "ko");
	exit(84);
      }
      if (!(assign_player_to_team(server, player, team_name)))
	return (false);
      set_client_type(client, AI);
      sprintf(buf, "%d\n%d %d\n", server->team_size - nb_player_in_team(server, team_name), server->map->width, server->map->height);
      send_socket(client->fd, buf);
    }
    cur = cur->next;
  }
  return (true);
}