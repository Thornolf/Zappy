/*
** map.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:31:54 2017 Guillaume CAUCHOIS
** Last update Thu Jun 22 12:31:12 2017 Pierre
*/

#ifndef		_MAP__H_
# define	_MAP__H_
# include	"stuff.h"
# include	"list.h"
# include "player.h"
# include	<stdio.h>

typedef struct	s_plot
{
  t_list	*player_list;
  t_stuff	*stuff_list;
}		t_plot;

typedef t_plot** t_map_data;

typedef struct	s_map
{
  t_map_data	data;
  unsigned int	x;
  unsigned int y;
}		t_map;

t_map	*create_empty_map(unsigned int, unsigned int);
void	fill_up_map_randomly(t_map *);
void	delete_map(t_map *);
void	print_map(t_map *);

#endif		/* !_MAP__H_ */
