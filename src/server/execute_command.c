/*
** execute_command.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Jun 29 13:16:06 2017 Guillaume CAUCHOIS
** Last update Sat Jul 01 23:40:23 2017 Pierre
*/

#include "server/command.h"

bool		execute_command_undefined(t_server *server, t_client *client,
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

bool		execute_command_defined(t_server *server,
					    t_client *client, t_command *cmd, char *arg)
{
  if (client->type == AI)
    add_waiting_cmd(server, cmd, client, arg);
  else if (client->type == GRAPHIC)
    cmd->fn(server, client);
  return (true);
}

char	**my_split(char *str, char *delim)
{
  char	**res;
  char	*p;
  int	n_spaces;

	if (str[0] == 0)
		return (NULL);
  n_spaces = 0;
  p = strtok(str, delim);
  if ((res = malloc(sizeof(char*) * 1)) == NULL)
    return (NULL);
  res[0] = NULL;
  while (p)
    {
      if ((res = realloc(res, sizeof(char*) * ++n_spaces)) == NULL)
        return (NULL);
      res[n_spaces - 1] = p;
      p = strtok(NULL, delim);
    }
  if ((res = realloc(res, sizeof(char*) * (n_spaces + 1))) == NULL)
    return (NULL);
  res[n_spaces] = 0;
  return (res);
}

bool		execute_command(t_server *server, t_client *client)
{
  t_list	*cur;
  t_command	*cmd;
	char **cmds;
	int i;

	cmds = my_split(client->buffer, " \t\n");
	if (cmds == NULL || !cmds[0])
		return (false);
  if (client->type == UNDEFINED)
    return (execute_command_undefined(server, client, cmds[0]));
	i = 0;
	while (cmds[i])
	{
		cur = server->cmds;
  	while (cur)
    	{
      	cmd = cur->data;
      	if (strcmp(cmd->cmd_name, cmds[i]) == 0 && cmd->type == client->type)
				{
					if (strcmp(cmds[i], "Take") == 0 || strcmp(cmds[i], "Set") == 0)
					{
						if (cmds[i + 1])
						{
							execute_command_defined(server, client, cmd, cmds[i + 1]);
							i++;
						}
						else
							return (true);
					}
					else
						execute_command_defined(server, client, cmd, NULL);
				}
      	cur = cur->next;
    	}
		i++;
	}
	return (true);
}
