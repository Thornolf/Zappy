/*
** player.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:35:50 2017 Guillaume CAUCHOIS
** Last update Thu Jun 22 19:10:40 2017 Pierre
*/

#ifndef		_PLAYER__H_
# define	_PLAYER__H_

# include  "server/list.h"
# include "server/inventory.h"
# include	<unistd.h>
# include <stdio.h>

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
  t_inventory	*inventory;
  t_direction	direction;
}		t_player;

t_player	*create_player(void);
void      add_player(t_list *head);
void      print_players(t_list *head);
t_list    *init_players_list();

#endif		/* _PLAYER__H_ */
