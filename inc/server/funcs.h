/*
** funcs.h for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/inc
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue Jun 20 15:52:04 2017 Pierre
** Last update Fri Jun 23 15:48:59 2017 Pierre
*/

#ifndef		_FUNCS__H_
# define	_FUNCS__H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server/server.h"
#include "server/stuff.h"

int		handle_parsing(t_info *info, int ac, char **av);
void		free_server_informations(t_info *info);
int		existing_command(char *arg);
int		simple_command(t_info *info, int i, char *arg, char *val);
int		long_command(t_info *info, int i, char **av);

#endif		/* _FUNC__H_ */
