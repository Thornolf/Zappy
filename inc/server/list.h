/*
** list.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:38:02 2017 Guillaume CAUCHOIS
** Last update Tue Jun 20 09:38:02 2017 Guillaume CAUCHOIS
*/

#ifndef		_LIST__H_
# define	_LIST__H_
# include	<stdlib.h>
# include	<unistd.h>

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

t_list		*create_node(void *, t_list *);
void		remove_node(t_list **, t_list *, void(*)(void *));
void		remove_list(t_list *, void(*)(void *));

#endif		/* !_STUFF__H_! */