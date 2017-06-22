/*
** player.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:35:50 2017 Guillaume CAUCHOIS
** Last update Tue Jun 20 09:35:50 2017 Guillaume CAUCHOIS
*/

#ifndef		_PLAYER__H_
# define	_PLAYER__H_
# include        "server/list.h"
#include	<unistd.h>

typedef enum	e_direction
{
  TOP = 0,
  LEFT,
  RIGHT,
  BOTTOM
}		t_direction;

typedef struct	s_player
{
  int		id;
  t_list	*stuff_list;
  t_direction	direction;
}		t_player;

t_player	*create_player(void);

#endif		/* _PLAYER__H_ */