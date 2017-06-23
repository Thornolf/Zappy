/*
** command.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 23 12:49:35 2017 Guillaume CAUCHOIS
** Last update Fri Jun 23 12:49:35 2017 Guillaume CAUCHOIS
*/

#ifndef		_COMMAND__H_
# define	_COMMAND__H_
# define	CTRL_F "\r\n"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "server/client.h"
# include "server/server.h"

typedef void(*cmd_func)(t_server *, t_client *);

typedef struct	s_command
{
  char		*cmd_name;
  cmd_func	fn;

}		t_command;

/**
 * Initialisation command list
 */
t_command	*create_command_node(const char *, cmd_func);
t_list		*init_cmd_callback(void);
bool		execute_command(t_server *, t_client *);
void		delete_command(void *);

/**
 * Commands functions
 */
void	command_msz(t_server *, t_client *);

#endif		/* !_COMMAND__H_! */