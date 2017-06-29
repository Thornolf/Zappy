/*
** map.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:30:48 2017 Guillaume CAUCHOIS
** Last update Thu Jun 29 14:39:10 2017 Guillaume CAUCHOIS
*/

#include "server/map.h"

t_map		*create_empty_map(unsigned int x, unsigned int y)
{
  t_map		*map;
  unsigned int	i;
  unsigned	j;

  if (!(map = malloc(sizeof(t_map))))
    return (NULL);
  map->width = x;
  map->height = y;
  if (!(map->data = malloc(sizeof(t_plot *) * (y + 1))))
    return (NULL);
  i = 0;
  while (i < y)
    {
      if (!(map->data[i] = malloc(sizeof(t_plot) * (x + 1))))
	return (NULL);
      j = 0;
      while (j < x)
	{
	  if (!(map->data[i][j].stuff = init_stuff()))
	    return (NULL);
	  j++;
	}
      i++;
    }
  map->data[i] = NULL;
  return (map);
}

t_stuff_type	generate_stuff_type_randomly(void)
{
  int		id;

  while ((id = rand() % STUFF_MAX + 1) < STUFF_MIN);
  return ((t_stuff_type)id);
}

void		put_stuff_in_map(t_map *map, unsigned int x, unsigned int y)
{
  t_stuff_type	type;

  if (x > map->width || y > map->height)
    return;
  type = generate_stuff_type_randomly();
  add_quantity(map->data[y][x].stuff, type);
}

void		fill_up_map_randomly(t_map *map)
{
  unsigned int	x;
  unsigned int	y;
  int		i;
  int		nb_entities;

  y = 0;
  while (y != map->height)
    {
      x = 0;
      while (x != map->width)
	{
	  i = 0;
	  nb_entities = rand() % (STUFF_MAX - STUFF_MIN);
	  while (i < nb_entities)
	    {
	      put_stuff_in_map(map, x, y);
	      i++;
	    }
	  x++;
	}
      y++;
    }
}

void	delete_map(t_map *map)
{
  unsigned int	y;

  y = 0;
  while (y < map->height)
    free(map->data[y++]);
  free(map->data);
  map->data = NULL;
  free(map);
}
