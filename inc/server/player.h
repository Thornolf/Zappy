/*
** player.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:35:50 2017 Guillaume CAUCHOIS
** Last update Fri Jun 23 15:49:10 2017 Pierre
*/

#ifndef		_PLAYER__H_
# define	_PLAYER__H_

# include "server/list.h"
# include "server/stuff.h"
# include "server/team.h"
# include <unistd.h>
# include <stdio.h>
# include <time.h>

typedef enum	e_direction
{
  DIRECTION_MIN = 0,
  TOP = DIRECTION_MIN,
  LEFT,
  RIGHT,
  BOTTOM,
  DIRECTION_MAX = BOTTOM
}		t_direction;

typedef struct	s_player
{
  int		id;
  int		x;
  int		y;
  int		lv;
  t_stuff	*stuff;
  t_direction	direction;
  t_team	*team;
}		t_player;

t_player	*create_player(int y, int x);
void		add_player(t_list *head, int y, int x);
t_list		*init_players_list(int y, int x);
int		my_rand(int min, int max);

#endif		/* _PLAYER__H_ */
