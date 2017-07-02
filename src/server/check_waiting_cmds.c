/*
** check_waiting_cmds.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sun Jul 02 19:46:04 2017 Pierre
** Last update Sun Jul  2 21:26:04 2017 Guillaume CAUCHOIS
*/

#include "server/server.h"
#include "server/player.h"
#include "server/client.h"
#include "server/command.h"

bool		launch_waiting_cmd(t_server *server,
				   t_command *cmd, t_waiting_cmds *tmp)
{
  t_client	*client;

  if (tmp->endwait != -1 && time(NULL) >= tmp->endwait)
    {
      client = tmp->client;
      if (strcmp(cmd->cmd_name, "Take") == 0 ||
	  strcmp(cmd->cmd_name, "Set") == 0)
	client->object_id = check_arg(tmp->arg);
      cmd->fn(server, client, tmp->arg);
      remove_waiting(&server->waiting_cmds, tmp);
      if (!server->waiting_cmds)
	return (false);
    }
  return (true);
}

bool		start_waiting(t_server *server,
			      t_command *cmd, t_waiting_cmds *tmp)
{
  t_client	*client;

  if (tmp->endwait == -1)
    {
      client = tmp->client;
      if (strcmp(cmd->cmd_name, "Incantation") == 0 && !client->incant)
	{
	  if (!(start_incantation(server, client)))
	    {
	      tmp->endwait = -1;
	      remove_waiting(&server->waiting_cmds, tmp);
	      if (!server->waiting_cmds)
		return (false);
	    }
	  else
	    tmp->endwait = time(NULL) + (cmd->action_time / server->freq);
	}
      else
	tmp->endwait = time(NULL) + (cmd->action_time / server->freq);
    }
  return (true);
}

void			check_waiting_cmds(t_server *server)
{
  t_command		*cmd;
  t_waiting_cmds	*tmp;

  tmp = server->waiting_cmds;
  while (tmp)
    {
      cmd = tmp->cmd;
      if (!(start_waiting(server, cmd, tmp)))
	return;
      if (!(launch_waiting_cmd(server, cmd, tmp)))
	return;
      if (tmp->next)
	tmp = tmp->next;
    }
}
