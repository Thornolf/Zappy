/*
** server.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 21 16:03:34 2017 Guillaume CAUCHOIS
** Last update Wed Jun 21 16:03:34 2017 Guillaume CAUCHOIS
*/

#ifndef		_SERVER__H_
# define	_SERVER__H_
# include	<stdbool.h>
# include	"server/stuff.h"
# include	"server/map.h"
# include	"server/socket.h"

typedef			void(*fct_server)(void *);

typedef struct		s_server
{
  int			fd;
  struct sockaddr_in	*sin;
  t_list		*clients;
  fct_server		server_read;
  fct_server		server_write;
}			t_server;

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

bool	init_zappy_server(t_info *);
bool	handle_io(fd_set *, fd_set *, t_server *);
bool	handle_isset_sockets(t_server *, fd_set *, t_list *, int);
int	get_fd_max(t_server *);

#endif		/* !_SERVER__H_! */