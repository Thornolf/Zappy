/*
** waiting_cmds.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Wed Jun 28 20:07:18 2017 Pierre
** Last update Wed Jun 28 20:07:27 2017 Pierre
*/

#include "server/command.h"

void add_cmd(t_waiting_cmds *head, t_command *cmd, t_client *client)
{
  t_waiting_cmds *current;

  printf("on add\n");
  current = head;
  while (current->next != NULL)
    current = current->next;
  current->next = malloc(sizeof(t_waiting_cmds));
  current->next->cmd = cmd;
  current->next->client = client;
  current->next->next = NULL;
}

t_waiting_cmds *init_waiting_list(t_command *cmd, t_client *client)
{
  t_waiting_cmds *head;

  head = NULL;
  head = malloc(sizeof(t_waiting_cmds));
  head->cmd = cmd;
  head->client = client;
  head->next = NULL;
  return (head);
}

void add_waiting_cmd(t_server *server, t_command *cmd, t_client *client)
{
  if (!server->waiting_cmds)
    server->waiting_cmds = init_waiting_list(cmd, client);
  else
    add_cmd(server->waiting_cmds, cmd, client);
}
