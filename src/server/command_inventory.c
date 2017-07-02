/*
** inventory_cmds_b.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 22 14:33:04 2017 Pierre
** Last update Sat Jul 01 22:24:51 2017 Pierre
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
  char *str;

  if (!(str = malloc(sizeof(char) * 100)))
    return ;
  if (!(snprintf(str, 100, "[ food %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d ]\n", stuff->quantities[FOOD], stuff->quantities[LINEMATE], stuff->quantities[DERAUMERE], stuff->quantities[SIBUR], stuff->quantities[MENDIANE], stuff->quantities[PHIRAS], stuff->quantities[THYSTAME])))
    return ;
  send_socket(fd, str);
}

void		command_inventory(t_server *server, t_client *client, char *arg)
{
  t_player *player;

  (void)arg;
  if (!(player = get_player(server->players, client->fd)))
    {
      send_socket(client->fd, "ko\n");
      return;
    }
  print_stuff(player->fd, player->stuff);
}
