/*
** client.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 21 18:08:49 2017 Guillaume CAUCHOIS
** Last update Wed Jun 21 18:08:49 2017 Guillaume CAUCHOIS
*/

#include "server/client.h"
#include "server/server.h"
#include "server/command.h"

t_client	*init_client(t_server *server)
{
  t_client		*client;
  struct sockaddr_in	client_sin;
  socklen_t 		client_sin_len;

  client_sin_len = sizeof(client_sin);
  if (!(client = malloc(sizeof(t_client))))
    return (client);
  if (!(client->fd = accept(server->fd, (struct sockaddr *)&client_sin, &client_sin_len)))
    return (NULL);
  client->fct_read = client_read;
  client->fct_write = client_write;
  if (!(client->buffer = malloc(sizeof(char) * BUFFER_CLIENT_SIZE)))
    return (NULL);
  return (client);
}

void	*client_read(void *_server, void *_client_node)
{
  t_server	*server;
  t_list	*client_node;
  t_client	*client;
  t_list	*next;

  (void)_server;
  server = _server;
  client_node = _client_node;
  client = client_node->data;
  memset(client->buffer, 0, BUFFER_CLIENT_SIZE);
  if (recv(client->fd, client->buffer, BUFFER_CLIENT_SIZE, 0) < 0)
    return (client_node->next);
  next = client_node->next;
  if (client->buffer[0] == 0)
  {
    remove_node(server->clients, client_node, &delete_client);
    return (next);
  }
  else
  {
    printf("SEARCH CMD\n");
    if (!(execute_command(server, client)))
    {
      printf("PAS TROUVE\n");
      return (next);
    }
  }
  return (client_node->next);
}

void	*client_write(void *_server, void *_client_node)
{
  t_server	*server;
  t_list	*client_node;
  t_client	*client;

  server = _server;
  (void)server;
  (void)client;
  client_node = _client_node;
  return (client_node->next);
}

void	delete_client(void *_client)
{
  t_client	*client;

  client = _client;
  close(client->fd);
  free(client->buffer);
  free(client);
}