/*
** handle_parsing.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue Jun 20 15:32:00 2017 Pierre
** Last update Thu Jun 29 14:38:27 2017 Guillaume CAUCHOIS
*/

#include <string.h>
#include "server/funcs.h"

void free_server_informations(t_info *info)
{
  int i;

  free(info->cmds);
  i = 0;
  if (info->clients)
    {
      while (info->clients[i])
	free(info->clients[i++]);
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
  return (1);
}
