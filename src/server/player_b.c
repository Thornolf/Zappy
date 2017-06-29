/*
** player_b.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Jun 29 14:08:26 2017 Guillaume CAUCHOIS
** Last update Thu Jun 29 16:11:32 2017 Guillaume CAUCHOIS
*/

#include "server/player.h"

bool		assign_player_to_team(t_server *server,
					  t_player *player, char *team_name)
{
  t_team	*team;

  if (!(team = get_team_by_name(server->teams, team_name)))
    return (false);
  player->team = team;
  return (true);
}

t_player	*get_player_by_id(t_list *list_player, int id)
{
  t_list	*cur;
  t_player	*player;

  cur = list_player;
  while (cur)
    {
      player = cur->data;
      if (player->id == id)
	return (player);
      cur = cur->next;
    }
  return (NULL);
}
