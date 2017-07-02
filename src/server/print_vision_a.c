/*
** print_vision_a.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sat Jun 24 12:51:13 2017 Pierre
** Last update Sun Jul 02 19:38:05 2017 Pierre
*/

#include "server/command.h"

void	init_print_cmds(void (*print_stuff_cmds[7])(char *str))
{
  if (print_stuff_cmds[FOOD])
    return ;
  print_stuff_cmds[FOOD] = &print_food;
  print_stuff_cmds[LINEMATE] = &print_linemate;
  print_stuff_cmds[DERAUMERE] = &print_deraumere;
  print_stuff_cmds[SIBUR] = &print_sibur;
  print_stuff_cmds[MENDIANE] = &print_mendiane;
  print_stuff_cmds[PHIRAS] = &print_phiras;
  print_stuff_cmds[THYSTAME] = &print_thystame;
}

void		print_tile_players(char *str, int y, int x, t_list *list_player)
{
  t_list	*tmp;
  t_player	*player;

  tmp = list_player;
  while (tmp)
    {
      player = tmp->data;
      if (player->x == x && player->y == y)
        str = strcat(str, "player ");
      tmp = tmp->next;
    }
}

char	*init_vision_str()
{
  char	*str;

  if (!(str = malloc(sizeof(char) * 4096)))
    return (NULL);
  str[0] = 0;
  str = strcat(str, "[ ");
  return (str);
}

void	finish_vision(int player_fd, char *str)
{
  str = strcat(str, "] \n");
  send_socket(player_fd, str);
  free(str);
}

void	print_objects(int player_fd, t_server *server, t_vision *tmp,
		      void (*print_stuff_cmds[7])(char *str))
{
  int	index;
  int	i;
  char	*str;

  if (!(str = init_vision_str()))
    return ;
  while (tmp)
    {
      print_tile_players(str, tmp->y, tmp->x, server->players);
      index = 0;
      while (index <= 6)
	{
	  i = 1;
	  while (i <= server->map->data[tmp->y][tmp->x].stuff->quantities[index])
	    {
	      (*print_stuff_cmds[index])(str);
	      i++;
	    }
	  index++;
	}
      if (tmp->next)
        str = strcat(str, ", ");
      tmp = tmp->next;
    }
  finish_vision(player_fd, str);
}
