/*
** look_funcction.c for PSU_2016_zappy in /home/gratte_r/Rendu/Teck_2/PSU/Zappy/PSU_2016_zappy/src/server/look_funcction.c
**
** Made by Robin GRATTEPANCHE
** Login   <robin.grattepanche@epitech.eu>
**
** Started on  Wed Jun 21 15:53:00 2017 Robin GRATTEPANCHE
** Last update Wed Jun 21 15:53:00 2017 Robin GRATTEPANCHE
*/

#include	"functions.h"

t_plot		in_which_plot(t_map *map, int id_player)
{
  unsigned int	x;
  unsigned int	y;
  t_player	*player;
  t_plot	out;

  x = 0;
  y = 0;
  while (y != map->y)
  {
    x = 0;
    while (x != map->x)
    {
      while (map->data[y][x].player_list)
      {
	player = (t_player *)(map->data[y][x].player_list->data);
	if (player->id == id_player)
	  out = map->data[y][x];
	map->data[y][x].player_list = map->data[y][x].player_list->next;
      }
      x++;
    }
    y++;
  }
  return (out);
}

void		look_function(t_map *map, t_player *current, int level)
{
  t_plot	plot;

  level = level;
  plot = in_which_plot(map, current->id);
  while (plot.stuff_list)
  {
    printf("%d ", plot.stuff_list->stuff);
    plot.stuff_list = plot.stuff_list->next;
  }
}