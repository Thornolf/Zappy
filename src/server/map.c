/*
** map.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:30:48 2017 Guillaume CAUCHOIS
** Last update Tue Jun 20 09:30:48 2017 Guillaume CAUCHOIS
*/

#include "map.h"

t_map		create_empty_map(unsigned int x, unsigned int y)
{
  t_map		map;
  unsigned int	i;

  if (!(map = malloc(sizeof(t_plot *) * (x + 1))))
    return (NULL);
  i = 0;
  while (i != y)
  {
    if (!(map[i] = malloc(sizeof(t_plot))))
      return (NULL);
    i++;
  }
  map[i] = NULL;
  return (map);
}