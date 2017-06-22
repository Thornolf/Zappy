/*
** client.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 21 18:06:03 2017 Guillaume CAUCHOIS
** Last update Wed Jun 21 18:06:03 2017 Guillaume CAUCHOIS
*/

#ifndef		_CLIENT__H_
# define	_CLIENT__H_
# define	BUFFER_CLIENT_SIZE (4096)
# include	<unistd.h>
# include	<stdlib.h>
# include	<string.h>
# include	"server/server.h"
# include	"server/list.h"

typedef			void*(*fct_client)(void *, void *);

typedef struct	s_client
{
  int		fd;
  char		*buffer;
  fct_client	fct_read;
  fct_client	fct_write;
}		t_client;

t_client	*init_client(t_server *);
void		*client_read(void *, void *);
void		*client_write(void *, void *);
void		delete_client(void *);

#endif		/* !_CLIENT_H_! */