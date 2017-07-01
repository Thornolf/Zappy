/*
** info.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 27 08:39:52 2017 Guillaume CAUCHOIS
** Last update Sat Jul 01 22:03:54 2017 Pierre
*/

#ifndef		_INFO__H_
# define	_INFO__H_

#include <time.h>

typedef struct	s_info
{
  char		*cmds;
  int		port;
  unsigned int	width;
  unsigned int	height;
  int		clientsNb;
  int		freq;
  char		**clients;
}		t_info;

#endif		/* !_INFO__H_! */
