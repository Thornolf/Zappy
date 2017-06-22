/*
** stuff.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 14:05:39 2017 Guillaume CAUCHOIS
** Last update Thu Jun 22 13:47:15 2017 Pierre
*/

#ifndef		_STUFF__H_
# define	_STUFF__H_
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum	e_stuff_type
{
  STUFF_MIN = 0,
  FOOD = STUFF_MIN,
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME,
  STUFF_MAX = THYSTAME
}		t_stuff_type;

typedef struct		s_stuff
{
  t_stuff_type		stuff;
  struct s_stuff	*next;
}			t_stuff;

t_stuff		*create_stuff_node(t_stuff_type, t_stuff *);
bool		stuff_type_in_stuff_list(t_stuff_type, t_stuff *);
void		delete_stuff_list(t_stuff *);

#endif		/* !_STUFF__H_! */
