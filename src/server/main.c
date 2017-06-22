/*
** main.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue May 30 13:21:39 2017 Guillaume CAUCHOIS
** Last update Thu Jun 22 18:50:50 2017 Pierre
*/

#include <time.h>
#include <stdio.h>
#include "map.h"
#include "funcs.h"

void my_exit(char *str)
{
  printf("%s\n", str);
  exit(84);
}

void print_usage()
{
  printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ...  -c clientsNb -f freq\n");
  printf("\tport\t   is the port number\n");
  printf("\twidth\t   is the width of the world\n");
  printf("\theight\t   is the height of the world\n");
  printf("\tnameX\t   is the name of the team X\n");
  printf("\tclientsNb  is the number of authorized clients per team\n");
  printf("\tfreq\t   is the reciproal of time unit for execution of actions\n");
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

void add_element_in_inventory(t_info *info, t_inventory *inv, t_stuff_type elem)
{
  (*info->add_elems_cmds[elem])(inv);
}

int		main(int ac, char **av)
{
  t_info	info;
  int		check;
  t_map		*map;

  info.cmds = NULL;
  info.clients = NULL;
  if (ac == 2 && strcmp(av[1], "-help") == 0)
    print_usage();
  else if (ac < 13)
  {
    fprintf(stderr, "Not enough arguments.\n./zappy_server -help");
    return (84);
  }
  if ((check = handle_parsing(&info, ac, av)) == 1)
    {
      srand((unsigned int)time(NULL));
      if (!(map = create_empty_map(info.width, info.height)))
        return (84);
      init_elems_cmds(&info);
      fill_up_map_randomly(map);
      print_map(map);
      delete_map(map);
    }
  else if (check == 0)
  {
    fprintf(stderr, "Error: Bad arguments.\n./zappy_server -help\n");
    return (84);
  }
  else
  {
    fprintf(stderr, "Error: Memory error, launch failed\n");
    return (84);
  }
  free_server_informations(&info);
  return (0);
}
