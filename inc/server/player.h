/*
** player.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:35:50 2017 Guillaume CAUCHOIS
** Last update Sun Jul 02 14:48:00 2017 Pierre
*/

#ifndef		_PLAYER__H_
# define	_PLAYER__H_

# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include "server/map.h"
# include "server/list.h"
# include "server/stuff.h"
# include "server/team.h"

typedef enum	e_direction
{
  DIR_MIN = 1,
  TOP = DIR_MIN,
  RIGHT,
  BOTTOM,
  LEFT,
  DIR_MAX = LEFT
}		t_direction;

typedef struct	s_player
{
  int		id;
  int		fd;
  int		x;
  int		y;
  int		lv;
  time_t start_time;
  t_stuff	*stuff;
  t_direction	direction;
  t_team	*team;
}		t_player;

void		delete_player(void *);
void		add_player(t_list *, int, int, int);
int		check_x(int, int);
int		check_y(int, int);
bool		assign_player_to_team(t_server *, t_player *, char *);
t_list		*init_players_list(int fd, int y, int x);
t_player	*create_player(int, int, int);
t_player	*get_player(t_list *, int);
t_player	*get_player_by_id(t_list *, int);
char		*player_ids_on_plot_to_string(t_list *, int, int);

#endif		/* _PLAYER__H_ */
