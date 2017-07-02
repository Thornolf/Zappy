/*
** print_vision_a.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sat Jun 24 12:51:13 2017 Pierre
** Last update Sun Jul 02 13:27:46 2017 Pierre
*/

#include "server/command.h"

void print_mendiane(char *str)
{
  str = strcat(str, "mendiane");
}

void print_phiras(char *str)
{
  str = strcat(str, "phiras");
}

void	init_print_cmds(void (*print_stuff_cmds[7])(char *str))
{
  if (print_stuff_cmds[FOOD])
    return ;
  print_stuff_cmds[FOOD]	= &print_food;
  print_stuff_cmds[LINEMATE]	= &print_linemate;
  print_stuff_cmds[DERAUMERE]	= &print_deraumere;
  print_stuff_cmds[SIBUR]	= &print_sibur;
  print_stuff_cmds[MENDIANE]	= &print_mendiane;
  print_stuff_cmds[PHIRAS]	= &print_phiras;
  print_stuff_cmds[THYSTAME]	= &print_thystame;
}

void print_tile_players(char *str, int y, int x, t_list *list_player)
{
  t_list	*tmp;
  t_player *player;

  tmp = list_player;
  while (tmp)
    {
      player = tmp->data;
      if (player->x == x && player->y == y)
        str = strcat(str, "player ");
      tmp = tmp->next;
    }
}

void	print_objects(int player_fd, t_list *list_player,
			  t_vision *tmp, t_map *map)
{
  int index;
  int i;
  char *str;
  static void	(*print_stuff_cmds[7])(char *str);

  if (!(str = malloc(sizeof(char) * 4096)))
    return ;
  str[0] = 0;
  str = strcat(str, "[ ");
  init_print_cmds(print_stuff_cmds);
  while (tmp)
    {
      print_tile_players(str, tmp->y, tmp->x, list_player);
      index = 0;
      while (index <= 6)
	    {
	      i = 1;
	      while (i <= map->data[tmp->y][tmp->x].stuff->quantities[index])
	       {
	         (*print_stuff_cmds[index])(str);
            str = strcat(str, " ");
	         i++;
	       }
	     index++;
	    }
      if (tmp->next)
        str = strcat(str, ", ");
      tmp = tmp->next;
    }
  str = strcat(str, "] \n");
  send_socket(player_fd, str);
  free(str);
}
