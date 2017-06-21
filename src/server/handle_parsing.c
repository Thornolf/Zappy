/*
** handle_parsing.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue Jun 20 15:32:00 2017 Pierre
** Last update Wed Jun 21 15:20:05 2017 Pierre
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

void free_struct(t_info *info)
{
  int i;

  free(info->cmds);
  i = 0;
  if (info->clients)
  {
    while (info->clients[i])
    {
      free(info->clients[i]);
      i++;
    }
    free(info->clients);
  }
}

int handle_parsing(t_info *info, int ac, char **av)
{
  int i;

  if (av[1][0] != '-')
    return (0);
  i = 1;
  if ((info->cmds = strdup("pxyncf")) == NULL)
    return (-1);
  while (i < ac)
  {
    if (av[i][0] == '-')
      {
        if (existing_command(av[i]) == 1)
        {
          if (av[i][1] != 'n')
            i = simple_command(info, i, av[i], av[i + 1]);
          else
            i = long_command(info, i, av);
          if (i <= 0)
            return (i);
        }
        else
          return (0);
      }
      else
        return (0);
  }
  //check_if_parsing_is_aux_petits_oignons(info);
  return (1);
}
