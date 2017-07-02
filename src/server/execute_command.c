/*
** execute_command.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Jun 29 13:16:06 2017 Guillaume CAUCHOIS
** Last update Sun Jul 02 17:22:04 2017 Pierre
*/

#include "server/command.h"

bool	execute_command_undefined(t_server *server, t_client *client,
				  char *command_name)
{
  if (strcmp(command_name, "GRAPHIC") == 0)
    {
      connection_graphic(server, client);
      return (true);
    }
  else if (connection_ia(server, client, command_name))
    return (true);
  return (false);
}

bool	execute_command_defined(t_server *server,
				t_client *client, t_command *cmd)
{
  char	*arg;

  if (client->type == AI)
    {
      arg = strtok(NULL, " \t\n");
      if (arg != NULL && !(arg = strdup(arg)))
	return (false);
      add_waiting_cmd(server, cmd, client, arg);
      free(arg);
    }
  else if (client->type == GRAPHIC)
    cmd->fn(server, client, NULL);
  return (true);
}

bool		execute_command(t_server *server, t_client *client)
{
  t_list	*cur;
  char		*cmd_name;
  t_command	*cmd;

  if (!(cmd_name = strtok(client->buffer, " \t\n")))
    return (false);
  if (client->type == UNDEFINED)
    return (execute_command_undefined(server, client, cmd_name));
  cur = server->cmds;
  while (cur)
    {
      cmd = cur->data;
      if (strcmp(cmd->cmd_name, cmd_name) == 0 && cmd->type == client->type)
	return (execute_command_defined(server, client, cmd));
      cur = cur->next;
    }
  return (true);
}
