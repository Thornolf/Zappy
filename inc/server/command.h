/*
** command.h for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 23 12:49:35 2017 Guillaume CAUCHOIS
** Last update Thu Jun 29 14:47:27 2017 Pierre
*/

#ifndef		_COMMAND__H_
# define	_COMMAND__H_
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "server/client.h"
# include "server/player.h"
# include "server/server.h"
# include "server/look.h"

typedef void(*cmd_func)(t_server *, t_client *);

typedef struct	s_command
{
  char		*cmd_name;
  time_t action_time;
  cmd_func	fn;
  t_client_type	type;
}		t_command;

/**
 * Initialisation command list
 */
t_command	*create_command_node(const char *name, time_t action_time, cmd_func fun, t_client_type type);
t_list		*init_cmd_callback(void);
bool		execute_command(t_server *, t_client *);
void		delete_command(void *);

/**
 * Commandes UNDEFINED
 */

void add_waiting_cmd(t_server *server, t_command *cmd, t_client *client);

char *int_to_string(int nb);

void	connection_graphic(t_server *, t_client *);
bool	connection_ia(t_server *server, t_client *client, char *);
void	command_pnw(t_server *, t_player *);

void		print_stuff(int fd, t_stuff *stuff);

/**
 * Commandes IA
 */
void	command_take_object(t_server *server, t_client *client);
void	command_turn_right(t_server *, t_client *);
void	command_turn_left(t_server *, t_client *);
void	command_move_player(t_server *, t_client *);
void	command_look(t_server *, t_client *);
void	print_objects(int, t_list *, t_vision *, t_map *);
void	command_inventory(t_server *, t_client *);
void	command_broadcast(t_server *, t_client *);
void command_connect_nbr(t_server *server, t_client *client);

/**
 * Commandes GRAPHIC
 */
void	command_msz(t_server *, t_client *);
void	command_bct(t_server *, t_client *);
void	command_mct(t_server *, t_client *);
void	command_tna(t_server *, t_client *);
void	command_ppo(t_server *, t_client *);
void	command_plv(t_server *, t_client *);
void	command_pin(t_server *, t_client *);
void	command_sgt(t_server *, t_client *);

#endif		/* !_COMMAND__H_! */
