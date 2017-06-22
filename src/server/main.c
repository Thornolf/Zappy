/*
** main.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue May 30 13:21:39 2017 Guillaume CAUCHOIS
** Last update Thu Jun 22 12:32:10 2017 Pierre
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

int	main(int ac, char **av)
{
  t_info info;
  int check;

  info.cmds = NULL;
  info.clients = NULL;
  if (ac == 2 && strcmp(av[1], "-help") == 0)
    print_usage();
  else if (ac < 13)
    my_exit("Not enough arguments.\n./zappy_server -help");
  if ((check = handle_parsing(&info, ac, av)) == 1)
    {
      t_map	*map;
      srand((unsigned int)time(NULL));
      if (!(map = create_empty_map(info.height, info.width)))
        return (84);
      fill_up_map_randomly(map);
      map->data[0][0].player_list = init_players_list();
      add_player(map->data[0][0].player_list, NULL);
      print_players(map->data[0][0].player_list);
      //print_map(map);
      delete_map(map);
    }
  else if (check == 0)
    printf("Bad arguments.\n./zappy_server -help\n");
  else
    printf("Memory error, launch failed\n");
  free_struct(&info);
  return (0);
}
