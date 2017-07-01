/*
** inventory_cmds_b.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 22 14:33:04 2017 Pierre
** Last update Sat Jul 01 10:47:34 2017 Pierre
*/

#include <string.h>
#include "server/string.h"
#include "server/command.h"

void		add_quantity(t_stuff *stuff, t_stuff_type type)
{
  stuff->quantities[type] += 1;
}

t_stuff		*init_stuff(void)
{
  t_stuff	*stuff;
  int		i;

  if (!(stuff = malloc(sizeof(t_stuff))))
    return (NULL);
  if (!(stuff->quantities = malloc(sizeof(int) * (STUFF_MAX + 1))))
    return (NULL);
  i = 0;
  while (i != STUFF_MAX + 1)
    stuff->quantities[i++] = 0;
  return (stuff);
}

void		print_stuff(int fd, t_stuff *stuff)
{
  send_socket(fd, "[food ");
  send_socket(fd, itos(stuff->quantities[FOOD]));
  send_socket(fd, ", linemate ");
  send_socket(fd, itos(stuff->quantities[LINEMATE]));
  send_socket(fd, ", deraumere ");
  send_socket(fd, itos(stuff->quantities[DERAUMERE]));
  send_socket(fd, ", sibur ");
  send_socket(fd, itos(stuff->quantities[SIBUR]));
  send_socket(fd, ", mendiane ");
  send_socket(fd, itos(stuff->quantities[MENDIANE]));
  send_socket(fd, ", phiras ");
  send_socket(fd, itos(stuff->quantities[PHIRAS]));
  send_socket(fd, ", thystame ");
  send_socket(fd, itos(stuff->quantities[THYSTAME]));
  send_socket(fd, "]\n");
}

void command_inventory(t_server *server, t_client *client)
{
  t_player *player;

  if (!(player = get_player(server->players, client->fd)))
    {
      send_socket(client->fd, "ko\n");
      return;
    }
  print_stuff(player->fd, player->stuff);
}
