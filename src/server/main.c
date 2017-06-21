/*
** main.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue May 30 13:21:39 2017 Guillaume CAUCHOIS
** Last update Tue May 30 13:21:39 2017 Guillaume CAUCHOIS
*/

#include <time.h>
#include <stdio.h>
#include "map.h"

int	main(void)
{
  t_map	*map;
  srand((unsigned int)time(NULL));
  if (!(map = create_empty_map(42, 42)))
    return (84);
  fill_up_map_randomly(map);
  delete_map(map);
  return (0);
}
