/*
** socket.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 21 15:07:46 2017 Guillaume CAUCHOIS
** Last update Wed Jun 21 15:07:46 2017 Guillaume CAUCHOIS
*/

#ifndef		_SOCKET__H_
# define	_SOCKET__H_
# define	MAX_NB_CONNECTION (100)
# include	<stdbool.h>
# include	<sys/socket.h>
# include	<netinet/in.h>

int	open_socket(int);
bool	listen_socket(int socket);
void	set_time_out(struct timeval *);
void	send_socket(int , char *);


#endif		/* !_SOCKET__H_! */