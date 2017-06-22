/*
** add_to_inventory.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 22 19:15:36 2017 Pierre
** Last update Thu Jun 22 19:16:08 2017 Pierre
*/

#include "server/server.h"

void add_element_in_inventory(t_info *info, t_inventory *inv, t_stuff_type elem)
{
  (*info->add_elems_cmds[elem])(inv);
}

void init_elems_cmds(t_info *info)
{
  info->add_elems_cmds[0] = &(add_food);
  info->add_elems_cmds[1] = &(add_linemate);
  info->add_elems_cmds[2] = &(add_deraumere);
  info->add_elems_cmds[3] = &(add_sibur);
  info->add_elems_cmds[4] = &(add_mendiane);
  info->add_elems_cmds[5] = &(add_phiras);
  info->add_elems_cmds[6] = &(add_thystame);
}
