/*
** send.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 23 16:35:09 2017 Guillaume CAUCHOIS
** Last update Fri Jun 23 16:35:09 2017 Guillaume CAUCHOIS
*/

#include "server/client.h"
#include "server/socket.h"

void	send_socket(int fd, char *msg)
{
  send(fd, msg, strlen(msg), 0);
}