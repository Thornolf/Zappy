/*
** socket.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 21 15:05:09 2017 Guillaume CAUCHOIS
** Last update Wed Jun 21 15:05:09 2017 Guillaume CAUCHOIS
*/

#include "server/socket.h"

int	open_socket(int port)
{
  int			s;
  struct sockaddr_in	sin;

  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    return (-1);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if ((bind(s, (struct sockaddr *)&sin, sizeof(struct sockaddr_in))) == -1)
    return (-1);
  return (s);
}

void	set_time_out(struct timeval *tv)
{
  tv->tv_usec = 0;
  tv->tv_sec = 8;
}

bool	listen_socket(int socket)
{
  if (listen(socket, MAX_NB_CONNECTION) == -1)
    return (false);
  return (true);
}