/*
** command_team.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon Jun 26 16:25:27 2017 Guillaume CAUCHOIS
** Last update Mon Jun 26 16:25:27 2017 Guillaume CAUCHOIS
*/

#include "server/command.h"
#include "server/socket.h"

void	command_tna(t_server *server, t_client *client)
{
  (void)server;
  send_socket(client->fd, "tna \n");
}