/*
** command_mct.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Sun Jul 02 18:50:30 2017 Guillaume CAUCHOIS
** Last update Sun Jul  2 20:52:02 2017 Guillaume CAUCHOIS
*/

#include "server/command.h"

void		command_mct(t_server *server, t_client *client, char *arg)
{
  unsigned int	x;
  unsigned int	y;

  (void)arg;
  x = 0;
  while (x != server->map->width)
    {
      y = 0;
      while (y != server->map->height)
	{
	  command_bct_at_position(server, client, x, y);
	  y++;
	}
      x++;
    }
}

void		command_mct_all_graphics(t_server *server)
{
  t_list	*cur_client_node;
  t_client	*client;

  cur_client_node = server->clients;
  while (cur_client_node)
    {
      client = cur_client_node->data;
      if (client->type == GRAPHIC)
	command_mct(server, client, NULL);
      cur_client_node = cur_client_node->next;
    }
}
