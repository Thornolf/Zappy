/*
** command_client.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon Jun 26 15:38:05 2017 Guillaume CAUCHOIS
** Last update Mon Jun 26 15:38:05 2017 Guillaume CAUCHOIS
*/

#include "server/command.h"

void	command_graphic(t_server *server, t_client *client)
{
  (void)server;
  client->type = GRAPHIC;
  send_socket(client->fd, "BIENVENUE\n");
  command_msz(server, client);
  command_mct(server, client);
}