/*
** look.h for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/inc/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Fri Jun 23 10:15:39 2017 Pierre
** Last update Wed Jun 28 13:19:19 2017 Pierre
*/

#ifndef LOOK_H_
# define LOOK_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_vision
{
  int case_nb;
  int y;
  int x;
  struct s_vision	*next;
}		t_vision;

void	print_food(int fd);
void	print_linemate(int fd);
void	print_deraumere(int fd);
void	print_sibur(int fd);
void	print_mendiane(int fd);
void	print_phiras(int fd);
void	print_thystame(int fd);

t_vision	*init_vision(int, int);
void		add_case_vision(t_vision *, int, int);

typedef struct s_it
{
  int end;
  int max_end;
  int line;
  int line_end;
  int i;
  int x;
  int y;
}  t_it;

#endif
