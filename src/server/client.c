/*
** client.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 21 18:08:49 2017 Guillaume CAUCHOIS
** Last update Sun Jul 02 13:16:28 2017 Pierre
*/

#include "server/client.h"
#include "server/server.h"
#include "server/command.h"

t_client	*init_client(t_server *s)
{
  t_client		*c;
  struct sockaddr_in	c_sin;
  socklen_t 		c_sin_len;

  c_sin_len = sizeof(c_sin);
  if (!(c = malloc(sizeof(t_client))))
    return (c);
  if (!(c->fd = accept(s->fd, (struct sockaddr *)&c_sin, &c_sin_len)))
    return (NULL);
  c->fct_read = (void*(*)(void*, void *))(client_read);
  c->type = UNDEFINED;
  c->incant = false;
  c->object_id = -1;
  if (!(c->buffer = malloc(sizeof(char) * BUFFER_CLIENT_SIZE)))
    return (NULL);
  return (c);
}

t_list		*get_player_node(t_list *player_list, int fd)
{
  t_list	*cur;
  t_player	*player;

  cur = player_list;
  while (cur)
    {
      player = cur->data;
      if (player->fd == fd)
	return (cur);
      cur = cur->next;
    }
  return (NULL);
}

void	*client_read(t_server *server, t_list *client_node)
{
  t_client	*client;
  t_list	*next;
  t_list	*player;
  ssize_t end;

  client = client_node->data;
  memset(client->buffer, 0, BUFFER_CLIENT_SIZE);
  if ((end = recv(client->fd, client->buffer, BUFFER_CLIENT_SIZE, 0)) < 0)
    return (client_node->next);
  client->buffer[end] = 0;
  next = client_node->next;
  if (client->buffer[0] == 0)
    {
      if (!(player = get_player_node(server->players, client->fd)))
	return (next);
      remove_node(&server->players, player, &delete_player);
      remove_node(&server->clients, client_node, &delete_client);
      return (next);
    }
  else if (!(execute_command(server, client)))
    {
      send_socket(client->fd, "suc\n");
      return (next);
    }
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
