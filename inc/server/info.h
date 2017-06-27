/*
** info.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 27 08:39:52 2017 Guillaume CAUCHOIS
** Last update Tue Jun 27 08:39:52 2017 Guillaume CAUCHOIS
*/

#ifndef		_INFO__H_
# define	_INFO__H_

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