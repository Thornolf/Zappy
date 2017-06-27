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
  set_client_type(client, GRAPHIC);
  command_msz(server, client);
  command_mct(server, client);
}

bool	command_ia(t_server *server, t_client *client, char *team_name)
{
  set_client_type(client, AI);
  (void)server;
  (void)team_name;
  /**
   * ASSIGNER LA TEAM DU PLAYER ASSOCIE ET RETURN STATUS (valide team name ?)
   */
  send_socket(client->fd, "INFORMATION POUR IA");
  return (true);
}