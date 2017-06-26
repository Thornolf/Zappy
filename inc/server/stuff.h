/*
** inventory.h for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/inc
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 22 14:16:37 2017 Pierre
** Last update Thu Jun 22 14:49:00 2017 Pierre
*/

#ifndef		_STUFF__H_
# define	_STUFF__H_

#include <stdlib.h>
#include <stdio.h>

typedef enum	e_stuff_type
{
  STUFF_MIN = 0,
  FOOD = STUFF_MIN,
  LINEMATE = 1,
  DERAUMERE = 2,
  SIBUR = 3,
  MENDIANE = 4,
  PHIRAS = 5,
  THYSTAME = 6,
  STUFF_MAX = THYSTAME
}		t_stuff_type;

typedef struct	s_stuff
{
  int		*quantities;
}		t_stuff;

void		add_quantity(t_stuff *, t_stuff_type);
void		print_stuff(t_stuff *);
t_stuff		*init_stuff(void);

#endif		/* !_STUFF__H_! */
