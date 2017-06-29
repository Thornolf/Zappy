/*
** server.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 21 16:03:34 2017 Guillaume CAUCHOIS
** Last update Thu Jun 29 10:55:48 2017 Pierre
*/

#ifndef		_SERVER__H_
# define	_SERVER__H_
# include <stdbool.h>
# include <time.h>
# include "server/stuff.h"
# include "server/map.h"
# include "server/socket.h"
# include "server/stuff.h"
# include "server/list.h"
# include "server/info.h"

typedef			void(*fct_server)(void *);

typedef struct		s_waiting_cmds
{
  void			*cmd;
  void			*client;
  struct s_waiting_cmds	*next;
}			t_waiting_cmds;

typedef struct		s_server
{
  int			fd;
  int			team_size;
  int			freq;
  time_t		endwait;
  struct timeval	timeout;
  fct_server		server_read;
  t_map			*map;
  t_list		*clients;
  t_list		*players;
  t_list		*cmds;
  t_waiting_cmds	*waiting_cmds;
  t_list		*teams;
}			t_server;

bool	init_zappy_server(t_info *);
bool	handle_io(fd_set *, fd_set *, t_server *);
int	get_fd_max(t_server *);
void	check_waiting_cmds(t_server *);

#endif		/* !_SERVER__H_! */
