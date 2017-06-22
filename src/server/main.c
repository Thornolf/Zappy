/*
** main.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue May 30 13:21:39 2017 Guillaume CAUCHOIS
** Last update Thu Jun 22 19:04:03 2017 Pierre
*/

#include <time.h>
#include <stdio.h>
#include "server/map.h"
#include "server/funcs.h"

void	print_usage(void)
{
  printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ...  -c clientsNb -f freq\n");
  printf("\tport\t   is the port number\n");
  printf("\twidth\t   is the width of the world\n");
  printf("\theight\t   is the height of the world\n");
  printf("\tnameX\t   is the name of the team X\n");
  printf("\tclientsNb  is the number of authorized clients per team\n");
  printf("\tfreq\t   is the reciproal of time unit for execution of actions\n");
}

int		main(int ac, char **av)
{
  t_info	info;
  int		check;

  srand((unsigned int)time(NULL));
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
    if (!(init_zappy_server(&info)))
    {
      fprintf(stderr, "Error: Cannot start the server due to bad configuration\n");
      return (84);
    }
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
