/*
** send.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 23 16:35:09 2017 Guillaume CAUCHOIS
** Last update Sun Jul 02 11:13:45 2017 Pierre
*/

#include "server/client.h"
#include "server/socket.h"

bool	send_socket(int fd, char *msg)
{
  return ((send(fd, msg, strlen(msg), 0)) < 0);
}
