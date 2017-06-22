/*
** inventory_cmds_a.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 22 14:32:52 2017 Pierre
** Last update Thu Jun 22 14:35:38 2017 Pierre
*/

#include "inventory.h"

void add_food(t_inventory *inv)
{
  inv->food += 1;
}

void add_linemate(t_inventory *inv)
{
  inv->linemate += 1;
}

void add_deraumere(t_inventory *inv)
{
  inv->deraumere += 1;
}

void add_sibur(t_inventory *inv)
{
  inv->sibur += 1;
}

void add_mendiane(t_inventory *inv)
{
  inv->mendiane += 1;
}
