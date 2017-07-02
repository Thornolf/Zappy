/*
** client.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 21 18:06:03 2017 Guillaume CAUCHOIS
** Last update Sun Jul 02 14:51:20 2017 Pierre
*/

#ifndef		_CLIENT__H_
# define	_CLIENT__H_
# define	BUFFER_CLIENT_SIZE (4096)
# include <sys/socket.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "server/list.h"
# include "server/socket.h"

typedef			void*(*fct_client)(void *, void *);

typedef enum	e_client_type
{
  UNDEFINED = -1,
  AI = 0,
  GRAPHIC
}		t_client_type;

typedef struct	s_client
{
  int		fd;
  bool		incant;
  int		object_id;
  t_client_type	type;
  char		*buffer;
  fct_client	fct_read;
  fct_client	fct_write;
}		t_client;

typedef struct s_server t_server;

t_client	*init_client(t_server *);
void		*client_read(t_server *, t_list *);
void		*client_write(void *, void *);
void		delete_client(void *);
t_list		*get_player_node(t_list *player_list, int fd);

#endif		/* !_CLIENT_H_! */
