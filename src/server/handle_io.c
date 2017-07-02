/*
** handle_io.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Jun 29 13:52:59 2017 Guillaume CAUCHOIS
** Last update Sun Jul 02 15:21:56 2017 Pierre
*/

#include "server/server.h"
#include "server/list.h"
#include "server/command.h"

void		set_all_fd(fd_set *fd_read, t_server *server)
{
  t_list	*cur_client_node;
  t_client	*client;

  FD_SET(server->fd, fd_read);
  cur_client_node = server->clients;
  while (cur_client_node)
    {
      client = cur_client_node->data;
      FD_SET(client->fd, fd_read);
      cur_client_node = cur_client_node->next;
    }
}

void check_food(t_server *server, t_list *_client)
{
  t_client *client;
  t_player *player;

  client = _client->data;
  player = get_player(server->players, client->fd);
  if (!player)
    return ;
  if (time(NULL) >= player->start_time + server->food_time)
    {
      player->stuff->quantities[FOOD] -= 1;
      if (player->stuff->quantities[FOOD] < 0)
        {
          send_socket(client->fd, "dead\n");
	  command_pdi(server, client, NULL);
	  remove_node(&server->players, get_player_node(server->players, client->fd), &delete_player);
          remove_node(&server->clients, _client, &delete_client);
        }
      else
        player->start_time = time(NULL);
    }
}

void		isset_all_fd(fd_set *fd_read, t_server *server)
{
  t_list	*cur_client_node;
  t_client	*client;

  if (FD_ISSET(server->fd, fd_read))
    server->server_read(server);
  cur_client_node = server->clients;
  while (cur_client_node)
    {
      client = cur_client_node->data;
      if (FD_ISSET(client->fd, fd_read))
	cur_client_node = client->fct_read(server, cur_client_node);
      else
	cur_client_node = cur_client_node->next;
    }
  cur_client_node = server->clients;
  while (cur_client_node)
    {
      check_food(server, cur_client_node);
      cur_client_node = cur_client_node->next;
    }
}

bool		handle_io(fd_set *fd_read, t_server *server)
{
  int		fd_max;
  bool		go_on;

  go_on = true;
  while (go_on)
    {
      check_waiting_cmds(server);
      fd_max = get_fd_max(server);
      FD_ZERO(fd_read);
      set_all_fd(fd_read, server);
      go_on = (select(fd_max + 1, fd_read, NULL, NULL, &server->timeout) >= 0);
      isset_all_fd(fd_read, server);
    }
  return (true);
}
