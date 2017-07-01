/*
** waiting_cmds.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Wed Jun 28 20:07:18 2017 Pierre
** Last update Sat Jul 01 10:21:11 2017 Pierre
*/

#include "server/command.h"

void add_cmd(t_waiting_cmds *head, t_command *cmd, t_client *client, char *arg)
{
  t_waiting_cmds *current;

  current = head;
  while (current->next != NULL)
    current = current->next;
  current->next = malloc(sizeof(t_waiting_cmds));
  current->next->cmd = cmd;
  current->next->client = client;
  current->next->arg = arg;
  current->next->endwait = -1;
  current->next->next = NULL;
}

t_waiting_cmds *init_waiting_list(t_command *cmd, t_client *client, char *arg)
{
  t_waiting_cmds *head;

  head = NULL;
  head = malloc(sizeof(t_waiting_cmds));
  head->cmd = cmd;
  head->client = client;
  head->arg = arg;
  head->endwait = -1;
  head->next = NULL;
  return (head);
}

void add_waiting_cmd(t_server *server, t_command *cmd, t_client *client, char *arg)
{
  if (!server->waiting_cmds)
    server->waiting_cmds = init_waiting_list(cmd, client, arg);
  else
    add_cmd(server->waiting_cmds, cmd, client, arg);
  check_waiting_cmds(server);
}
