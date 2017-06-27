/*
** team.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon Jun 26 16:32:48 2017 Guillaume CAUCHOIS
** Last update Mon Jun 26 16:32:48 2017 Guillaume CAUCHOIS
*/

#ifndef		_TEAM__H_
# define	_TEAM__H_
# include "server/info.h"
# include "server/list.h"

typedef struct	s_team
{
  char		*name;
}		t_team;

t_list		*init_team_list(t_info *info);

#endif		/* !_TEAM__H_! */