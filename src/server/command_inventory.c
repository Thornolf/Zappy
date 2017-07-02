/*
** inventory_cmds_b.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 22 14:33:04 2017 Pierre
** Last update Sun Jul  2 21:08:00 2017 Guillaume CAUCHOIS
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
  char		*str;
  int		wrote_sized;
  size_t	limit;

  limit = 200;
  if (!(str = malloc(sizeof(char) * limit)))
    return ;
  wrote_sized = 0;
  wrote_sized += snprintf(str, limit, "[ food %d, linemate %d",
			  stuff->quantities[FOOD],
			  stuff->quantities[LINEMATE]);
  limit -= wrote_sized;
  wrote_sized += snprintf(str, limit, ", deraumere %d, sibur %d",
			  stuff->quantities[DERAUMERE],
			  stuff->quantities[SIBUR]);
  limit -= wrote_sized;
  wrote_sized += snprintf(str, limit, ", mendiane %d, phiras %d, ",
			  stuff->quantities[MENDIANE],
			  stuff->quantities[PHIRAS]);
  limit -= wrote_sized;
  wrote_sized += snprintf(str, limit, "thystame %d ]\n",
			  stuff->quantities[THYSTAME]);
  send_socket(fd, str);
  free(str);
}

void		delete_stuff(void *_stuff)
{
  t_stuff	*stuff;

  stuff = _stuff;
  if (!stuff)
    return;
  free(stuff->quantities);
  free(stuff);
}

void		command_inventory(t_server *server, t_client *client, char *arg)
{
  t_player	*player;

  (void)arg;
  if (!(player = get_player(server->players, client->fd)))
    {
      send_socket(client->fd, "ko\n");
      return;
    }
  print_stuff(player->fd, player->stuff);
}
