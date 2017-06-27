/*
** player.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:35:50 2017 Guillaume CAUCHOIS
** Last update Mon Jun 26 18:39:53 2017 Pierre
*/

#ifndef		_PLAYER__H_
# define	_PLAYER__H_
# include "server/map.h"
# include "server/list.h"
# include "server/stuff.h"
# include "server/team.h"
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <stdbool.h>

typedef struct s_server t_server;
typedef struct s_team t_team;

typedef enum	e_direction
{
  DIRECTION_MIN = 0,
  TOP = DIRECTION_MIN,
  RIGHT,
  BOTTOM,
  LEFT,
  DIRECTION_MAX = LEFT
}		t_direction;

typedef struct	s_player
{
  int		id;
  int   fd;
  int		x;
  int		y;
  int		lv;
  t_stuff	*stuff;
  t_direction	direction;
  t_team	*team;
}		t_player;

t_player	*create_player(int fd, int y, int x);
void		add_player(t_list *head, int fd, int y, int x);
void		print_players(t_list *head);
t_list		*init_players_list(int fd, int y, int x);
void turn_right(t_map *map, t_player *player);
void turn_left(t_map *map, t_player *player);
int		my_rand(int min, int max);
bool		assign_player_to_team(t_server *, t_player *, char *);
t_player	*get_player(t_list *, int);

#endif		/* _PLAYER__H_ */
