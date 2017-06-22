/*
** inventory_cmds_b.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 22 14:33:04 2017 Pierre
** Last update Thu Jun 22 18:50:58 2017 Pierre
*/

#include "inventory.h"

void add_phiras(t_inventory *inv)
{
  inv->phiras += 1;
}

void add_thystame(t_inventory *inv)
{
  inv->thystame += 1;
}

t_inventory *init_inventory()
{
  t_inventory *inv;

  if ((inv = malloc(sizeof(t_inventory))) == NULL)
    return (NULL);
  inv->food = 0;
  inv->linemate = 0;
  inv->deraumere = 0;
  inv->sibur = 0;
  inv->mendiane = 0;
  inv->phiras = 0;
  inv->thystame = 0;
  return (inv);
}

void print_inventory(t_inventory *inv)
{
  printf("[food %d, ", inv->food);
  printf("linemate %d, ", inv->linemate);
  printf("deraumere %d, ", inv->deraumere);
  printf("sibur %d, ", inv->sibur);
  printf("mendiane %d, ", inv->mendiane);
  printf("phiras %d, ", inv->phiras);
  printf("thystame %d]\n", inv->thystame);
}
