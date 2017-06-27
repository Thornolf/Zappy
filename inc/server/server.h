/*
** server.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 21 16:03:34 2017 Guillaume CAUCHOIS
** Last update Tue Jun 27 14:26:11 2017 Pierre
*/

#ifndef		_SERVER__H_
# define	_SERVER__H_
# include <stdbool.h>
# include "server/stuff.h"
# include "server/map.h"
# include "server/socket.h"
# include "server/stuff.h"
# include "server/list.h"
# include "server/info.h"

typedef			void(*fct_server)(void *);

typedef struct		s_server
{
  int			fd;
  int			team_size;
  struct sockaddr_in	*sin;
  fct_server		server_read;
  fct_server		server_write;
  t_map			*map;
  t_list		*clients;
  t_list		*players;
  t_list		*cmds;
  t_list		*teams;
}			t_server;

bool	init_zappy_server(t_info *);
bool	handle_io(fd_set *, fd_set *, t_server *);
bool	handle_isset_sockets(t_server *, fd_set *, t_list *, int);
int	get_fd_max(t_server *);
void	init_elems_cmds(t_info *info);

#endif		/* !_SERVER__H_! */
