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