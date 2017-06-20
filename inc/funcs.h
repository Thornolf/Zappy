/*
** funcs.h for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/inc
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue Jun 20 15:52:04 2017 Pierre
** Last update Tue Jun 20 17:14:50 2017 Pierre
*/

#ifndef FUNCS_H_
# define FUNCS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_info
{
  char *cmds;
  int port;
  int width;
  int height;
  int clientsNb;
  int freq;
  char **clients;
} t_info;

void my_exit(char *str);
void handle_parsing(int ac, char **av);
int existing_command(char *arg);
int simple_command(t_info *info, int i, char *arg, char *val);
int long_command(t_info *info, int i, char **av);

#endif
