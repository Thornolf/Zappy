/*
** utils_parsing.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue Jun 20 17:11:51 2017 Pierre
** Last update Wed Jun 21 15:20:18 2017 Pierre
*/

#include "funcs.h"

int	check_twice(t_info *info, int val, int i)
{
  if (info->cmds[i] == '0')
    return (0);
  else
    info->cmds[i] = '0';
  return (val);
}

int	fill_simple_param(t_info *info, char param, int val)
{
  char	*tmp;
  int	i;
  int	try;

  if ((tmp = strdup("pxyncf")) == NULL)
    return (-1);
  i = 0;
  while (tmp[i] != param)
    i++;
  free(tmp);
  try = check_twice(info, val, i);
  if (try == 0)
    return (0);
  if (param == 'p')
    info->port = try;
  else if (param == 'x')
    info->width = try;
  else if (param == 'y')
    info->height = try;
  else if (param == 'c')
    info->clientsNb = try;
  else if (param == 'f')
    info->freq = try;
  return (1);
}

int	simple_command(t_info *info, int i, char *arg, char *val)
{
  if (!val || atoi(val) == 0)
    return (0);
  if ((fill_simple_param(info, arg[1], atoi(val))) == 0)
    return (0);
  return (i + 2);
}

int	long_command(t_info *info, int i, char **av)
{
  int	len;
  int	y;

  if (!av[i + 1] || av[i + 1][0] == '-')
    return (0);
  info->clients = NULL;
  i++;
  len = i;
  while (av[len] && av[len][0] != '-'){
    len++;
  }
  if ((info->clients = malloc(sizeof(char *) * ((len - i) + 1))) == NULL)
    return (-1);
  y = 0;
  while (i < len)
  {
    if ((info->clients[y] = strdup(av[i])) == NULL)
      return (-1);
    i++;
    y++;
  }
  info->clients[y] = NULL;
  if ((check_twice(info, 1, 3)) == 0)
    return (0);
  return (i);
}

int existing_command(char *arg)
{
  if (strlen(arg) != 2)
    return (0);
  if (arg[1] == 'p' ||
      arg[1] == 'x' ||
      arg[1] == 'y' ||
      arg[1] == 'n' ||
      arg[1] == 'c' ||
      arg[1] == 'f')
    return (1);
  return (0);
}
