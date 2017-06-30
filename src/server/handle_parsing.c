/*
** handle_parsing.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue Jun 20 15:32:00 2017 Pierre
** Last update Fri Jun 30 12:06:52 2017 Guillaume CAUCHOIS
*/

#include <string.h>
#include "server/funcs.h"

void	free_server_informations(t_info *info)
{
  int	i;

  free(info->cmds);
  i = 0;
  if (info->clients)
    {
      while (info->clients[i])
	free(info->clients[i++]);
      free(info->clients);
    }
}

int	init_info_struct(t_info *info, char **av)
{
  info->cmds = NULL;
  info->clients = NULL;
  if ((info->cmds = strdup("pxyncf")) == NULL)
    return (-1);
  if (av[1][0] != '-')
    return (0);
  return (1);
}

int	handle_parsing(t_info *info, int ac, char **av)
{
  int	i;

  if ((i = init_info_struct(info, av) != 1))
    return (i);
  i = 1;
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
