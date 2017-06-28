/*
** inventory_cmds_b.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 22 14:33:04 2017 Pierre
** Last update Wed Jun 28 13:15:03 2017 Pierre
*/

#include <string.h>
#include "server/command.h"

void		add_quantity(t_stuff *stuff, t_stuff_type type)
{
  stuff->quantities[type] += 1;
}

t_stuff		*init_stuff(void)
{
  t_stuff	*stuff;

  if (!(stuff = malloc(sizeof(t_stuff))))
    return (NULL);
  if (!(stuff->quantities = malloc(sizeof(int) * (STUFF_MAX))))
    return (NULL);
  memset(stuff->quantities, 0, sizeof(int) * (STUFF_MAX));
  return (stuff);
}

void		print_stuff(t_stuff *stuff)
{
  printf("[food %d, ", stuff->quantities[FOOD]);
  printf("linemate %d, ", stuff->quantities[LINEMATE]);
  printf("deraumere %d, ", stuff->quantities[DERAUMERE]);
  printf("sibur %d, ", stuff->quantities[SIBUR]);
  printf("mendiane %d, ", stuff->quantities[MENDIANE]);
  printf("phiras %d, ", stuff->quantities[PHIRAS]);
  printf("thystame %d]\n", stuff->quantities[THYSTAME]);
}

void command_inventory(t_server *server, t_client *client)
{
  t_player *player;

  if (!(player = get_player(server->players, client->fd)))
    return;
  if (player == NULL)
  {
    printf("error : player not found\n");
    return ;
  }
  print_stuff(player->stuff);
}
