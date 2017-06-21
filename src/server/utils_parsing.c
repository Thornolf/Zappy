/*
** utils_parsing.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue Jun 20 17:11:51 2017 Pierre
** Last update Tue Jun 20 17:13:18 2017 Pierre
*/

#include "funcs.h"

int check_twice(t_info *info, int val, int i)
{
  if (info->cmds[i] == '0')
    my_exit("Bad arguments.\n./zappy_server -help");
  else
    info->cmds[i] = '0';
  return (val);
}

void fill_simple_param(t_info *info, char param, int val)
{
  if (param == 'p')
    info->port = check_twice(info, val, 0);
  else if (param == 'x')
    info->width = check_twice(info, val, 1);
  else if (param == 'y')
    info->height = check_twice(info, val, 2);
  else if (param == 'n')
    info->cmds[3] = check_twice(info, val, 3);
  else if (param == 'c')
    info->clientsNb = check_twice(info, val, 4);
  else if (param == 'f')
    info->freq = check_twice(info, val, 5);
}

int simple_command(t_info *info, int i, char *arg, char *val)
{
  if (!val || atoi(val) == 0)
    my_exit("Bad arguments.\n./zappy_server -help");
  fill_simple_param(info, arg[1], atoi(val));
  return (i + 2);
}

int long_command(t_info *info, int i, char **av)
{
  int len;
  int y;

  if (!av[i + 1] || av[i + 1][0] == '-')
    my_exit("Bad arguments.\n./zappy_server -help");
  info->clients = NULL;
  i++;
  len = i;
  while (av[len] && av[len][0] != '-'){
    len++;
  }
  if ((info->clients = malloc(sizeof(char *) * ((len - i) + 1))) == NULL)
    my_exit("Error : info->clients malloc failed\n");
  y = 0;
  while (i < len)
  {
    info->clients[y] = strdup(av[i]);
    i++;
    y++;
  }
  info->clients[y] = NULL;
  fill_simple_param(info, 'n', 0);
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
