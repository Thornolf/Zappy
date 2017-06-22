/*
** map.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:30:48 2017 Guillaume CAUCHOIS
** Last update Wed Jun 21 11:03:41 2017 Guillaume CAUCHOIS
*/

#include "server/map.h"

t_map		*create_empty_map(unsigned int x, unsigned int y)
{
  t_map		*map;
  unsigned int	i;

  if (!(map = malloc(sizeof(t_map))))
    return (NULL);
  map->x = x;
  map->y = y;
  if (!(map->data = malloc(sizeof(t_plot *) * (y + 2))))
    return (NULL);
  i = 0;
  while (i < y)
  {
    if (!(map->data[i] = malloc(sizeof(t_plot) * (x + 1))))
      return (NULL);
    i++;
  }
  map->data[i] = NULL;
  return (map);
}

t_stuff_type	generate_stuff_type_randomly(void)
{
  int	id;

  while ((id = rand() % STUFF_MAX) < STUFF_MIN);
  return ((t_stuff_type)id);
}

void	put_stuff_in_map(t_map *map, unsigned int x, unsigned int y)
{
  t_stuff	*new_node;
  t_stuff	*list;

  if (x > map->x || y > map->y)
    return;
  list = map->data[y][x].stuff_list;
  if (!(new_node = create_stuff_node(generate_stuff_type_randomly(), NULL)))
    return ;
  new_node->next = list;
  map->data[y][x].stuff_list = new_node;
}

void		fill_up_map_randomly(t_map *map)
{
  unsigned int	x;
  unsigned int	y;
  int		i;
  int		nb_entities;

  y = 0;
  while (y != map->y)
  {
    x = 0;
    while (x != map->x)
    {
      i = 0;
      map->data[y][x].stuff_list = NULL;
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
  unsigned int	x;

  y = 0;
  while (y < map->y)
  {
    x = 0;
    while (x < map->x)
      delete_stuff_list(map->data[y][x++].stuff_list);
    free(map->data[y++]);
  }
  free(map->data);
  map->data = NULL;
  free(map);
}

void	print_map(t_map *map)
{
  unsigned int	x;
  unsigned int	y;
  t_stuff	*stuff;

  y = 0;
  while (y != map->y)
  {
    x = 0;
    while (x != map->x)
    {
      printf("MAP[%d][%d] =", y, x);
      stuff = map->data[y][x].stuff_list;
      while (stuff)
      {
	printf(" %d", stuff->stuff);
	stuff = stuff->next;
      }
      printf("\n");
      x++;
    }
    y++;
  }
}