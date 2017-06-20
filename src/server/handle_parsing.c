/*
** handle_parsing.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue Jun 20 15:32:00 2017 Pierre
** Last update Tue Jun 20 17:31:25 2017 Pierre
*/

#include <string.h>
#include "funcs.h"

void check_if_parsing_is_aux_petits_oignons(t_info *info)
{
  int i;

  i = 0;
  while (info->cmds[i])
  {
    if (info->cmds[i] != '0')
      my_exit("Bad arguments.\n./zappy_server -help");
    i++;
  }
  printf("-----\nport = %d\n", info->port);
  printf("width = %d\n", info->width);
  printf("height = %d\n", info->height);
  printf("clientsNb = %d\n", info->clientsNb);
  printf("freq = %d\n", info->freq);
  i = 0;
  printf("\nClients :\n");
  while (info->clients[i])
  {
    printf("%s\n", info->clients[i]);
    i++;
  }
  printf("-----\n");
}

void handle_parsing(int ac, char **av)
{
  t_info info;
  int i;

  if (av[1][0] != '-')
    my_exit("Bad arguments.\n./zappy_server -help");
  i = 1;
  info.cmds = strdup("pxyncf");
  while (i < ac)
  {
    if (av[i][0] == '-')
      {
        if (existing_command(av[i]) == 1)
        {
          if (av[i][1] != 'n')
            i = simple_command(&info, i, av[i], av[i + 1]);
          else
            i = long_command(&info, i, av);
        }
        else
          my_exit("Bad arguments.\n./zappy_server -help");
      }
      else
        my_exit("Bad arguments.\n./zappy_server -help");
  }

}
