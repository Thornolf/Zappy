/*
** look.h for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/inc/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Fri Jun 23 10:15:39 2017 Pierre
** Last update Sat Jun 24 12:52:31 2017 Pierre
*/

#ifndef LOOK_H_
# define LOOK_H_

#include <stdlib.h>
#include <stdio.h>
#include "server/map.h"
#include "server/player.h"

typedef struct	s_vision
{
  int case_nb;
  int y;
  int x;
  struct s_vision	*next;
}		t_vision;

void	print_objects(t_list *, t_vision *);

void	print_food(void);
void	print_linemate(void);
void	print_deraumere(void);
void	print_sibur(void);
void	print_mendiane(void);
void	print_phiras(void);
void	print_thystame(void);

t_vision	*init_vision(int, int);
void		add_case_vision(t_vision *, int, int);
int		check_x(int, int);
int		check_y(int, int);

void		look(t_list *, t_map *, t_player *);

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
