/*
** funcs.h for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/inc
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue Jun 20 15:52:04 2017 Pierre
** Last update Wed Jun 21 14:52:48 2017 Pierre
*/

#ifndef		_FUNCS__H_
# define	_FUNCS__H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_info
{
  char		*cmds;
  int		port;
  unsigned int	width;
  unsigned int	height;
  int		clientsNb;
  int		freq;
  char		**clients;
}		t_info;

void		my_exit(char *str);
int		handle_parsing(t_info *info, int ac, char **av);
void		free_server_informations(t_info *info);
int		existing_command(char *arg);
int		simple_command(t_info *info, int i, char *arg, char *val);
int		long_command(t_info *info, int i, char **av);

#endif		/* _FUNC__H_ */