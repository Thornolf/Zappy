/*
** team.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 27 08:10:12 2017 Guillaume CAUCHOIS
** Last update Tue Jun 27 08:10:12 2017 Guillaume CAUCHOIS
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "server/team.h"
#include "server/player.h"

t_team		*create_team(char *name)
{
  t_team	*team;

  if (!(team = malloc(sizeof(t_team))))
    return (NULL);
  team->name = strdup(name);
  return (team);
}

void		delete_team(void *_team)
{
  t_team	*team;

  team = _team;
  free(team->name);
  free(team);
}

t_list		*init_team_list(t_info *info)
{
  t_list	*head;
  t_list	*father;
  t_list	*son;
  t_team	*team;
  int		idx_team;

  if (info->clients[0] == NULL)
    return (NULL);
  if (!(team = create_team(info->clients[0])))
    return (NULL);
  if (!(head = create_node(team, NULL)))
    return (NULL);
  idx_team = 1;
  father = head;
  while (info->clients[idx_team])
  {
    if (!(team = create_team(info->clients[idx_team])))
      return (NULL);
    if (!(son = create_node(team, NULL)))
      return (NULL);
    father->next = son;
    father = son;
    idx_team++;
  }
  return (head);
}

t_team		*get_team_by_name(t_list *team_list, char *name)
{
  t_list	*cur_team;
  t_team	*team;

  cur_team = team_list;
  while (cur_team)
  {
    team = cur_team->data;
    if (strcmp(team->name, name) == 0)
      return (team);
    cur_team = cur_team->next;
  }
  return (NULL);
}

int		nb_player_in_team(t_server *server, char *team_name)
{
  t_team	*team;
  t_list	*cur_player_node;
  t_player	*player;
  int		i;

  if (!(team = get_team_by_name(server->teams, team_name)))
    return (-1);
  cur_player_node = server->players;
  i = 0;
  while (cur_player_node)
  {
    player = cur_player_node->data;
    if (player->team == team)
      i++;
    cur_player_node = cur_player_node->next;
  }
  return (i);
}