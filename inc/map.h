/*
** map.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:31:54 2017 Guillaume CAUCHOIS
** Last update Tue Jun 20 09:31:54 2017 Guillaume CAUCHOIS
*/

#ifndef		_MAP__H_
# define	_MAP__H_
# include	"list.h"

typedef struct	s_plot
{
  t_list	*player_list;
  t_list	*stuff_list;
}		t_plot;

typedef t_plot** t_map;

t_map	create_empty_map(unsigned int, unsigned int);

#endif		/* !_MAP__H_ */