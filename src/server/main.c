/*
** main.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue May 30 13:21:39 2017 Guillaume CAUCHOIS
** Last update Thu Jun 29 14:38:58 2017 Guillaume CAUCHOIS
*/

#include <time.h>
#include <stdio.h>
#include "server/map.h"
#include "server/funcs.h"

void	print_usage(void)
{
  printf("USAGE: ./zappy_server -p port -x width -y height ");
  printf("-n name1 name2 ... -c clientsNb -f freq\n");
  printf("\tport\t\tis the port number\n");
  printf("\twidth\t\tis the width of the world\n");
  printf("\theight\t\tis the height of the world\n");
  printf("\tnameX\t\tis the name of the team X\n");
  printf("\tclientsNb\tis the number of authorized clients per team\n");
  printf("\tfreq\t\tis the reciprocal of time unit for execution ");
  printf("of actions\n");
  exit(84);
}

int		main(int ac, char **av)
{
  t_info	info;
  int		check;

  srand((unsigned int)time(NULL));
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
	  free_server_informations(&info);
	  return (84);
	}
    }
  else if (check == 0)
    {
      fprintf(stderr, "Error: Bad arguments.\n./zappy_server -help\n");
      free_server_informations(&info);
      return (84);
    }
  else
    {
      fprintf(stderr, "Error: Memory error, launch failed\n");
      free_server_informations(&info);
      return (84);
    }
  free_server_informations(&info);
  return (0);
}
