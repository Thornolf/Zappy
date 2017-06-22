/*
** inventory.h for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/inc
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 22 14:16:37 2017 Pierre
** Last update Thu Jun 22 14:49:00 2017 Pierre
*/

#ifndef INVENTORY_H_
# define INVENTORY_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct  s_inventory
{
  int food;
  int linemate;
  int deraumere;
  int sibur;
  int mendiane;
  int phiras;
  int thystame;
}  t_inventory;

void add_food(t_inventory *inv);
void add_linemate(t_inventory *inv);
void add_deraumere(t_inventory *inv);
void add_sibur(t_inventory *inv);
void add_mendiane(t_inventory *inv);
void add_phiras(t_inventory *inv);
void add_thystame(t_inventory *inv);
void print_inventory(t_inventory *inv);
t_inventory *init_inventory();

#endif
