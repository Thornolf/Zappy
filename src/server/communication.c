/*
** communication.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 27 15:45:42 2017 Guillaume CAUCHOIS
** Last update Tue Jun 27 15:45:42 2017 Guillaume CAUCHOIS
*/

#include "server/socket.h"
#include "server/server.h"
#include "server/client.h"

bool		send_all_graphics(t_server *server, char *msg)
{
  t_list	*cur_client_node;
  t_client	*client;

  cur_client_node = server->clients;
  while (cur_client_node)
  {
    client = cur_client_node->data;
    if (client->type == GRAPHIC)
      send_socket(client->fd, msg);
    cur_client_node = cur_client_node->next;
  }
  return (true);
}

bool		send_all_ai(t_server *server, char *msg)
{
  t_list	*cur_client_node;
  t_client	*client;


  cur_client_node = server->clients;
  while (cur_client_node)
  {
    client = cur_client_node->data;
    if (client->type == AI && !send_socket(client->fd, msg))
      return (false);
    cur_client_node = cur_client_node->next;
  }
  return (true);
}