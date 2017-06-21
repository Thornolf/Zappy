/*
** main.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue May 30 13:21:39 2017 Guillaume CAUCHOIS
** Last update Wed Jun 21 14:28:55 2017 Pierre
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
  if (ac == 2 && strcmp(av[1], "-help") == 0)
    print_usage();
  else if (ac < 13)
    my_exit("Not enough arguments.\n./zappy_server -help");
  handle_parsing(ac, av);
  t_map	*map;
  srand((unsigned int)time(NULL));
  if (!(map = create_empty_map(42, 42)))
    return (84);
  fill_up_map_randomly(map);
  print_map(map);
  delete_map(map);
  return (0);
}
