/*
** inventory_cmds_b.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 22 14:33:04 2017 Pierre
** Last update Thu Jun 22 19:03:17 2017 Pierre
*/

#include <string.h>
#include "server/stuff.h"

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
