/*
** command.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 23 12:49:11 2017 Guillaume CAUCHOIS
** Last update Fri Jun 23 12:49:11 2017 Guillaume CAUCHOIS
*/
#include "server/list.h"
#include "server/command.h"

t_command	*create_command_node(const char *name, cmd_func fun)
{
  t_command	*cmd;

  if (!(cmd = malloc(sizeof(t_command))))
    return (NULL);
  cmd->cmd_name = strdup(name);
  cmd->fn = fun;
  return (cmd);
}

t_list		*init_cmd_callback(void)
{
  t_list	*head;
  t_list	*son;
  t_list	*father;
  t_command	*cmd;

  if (!(cmd = create_command_node("msz", &command_msz)))
    return (NULL);
  if (!(head = create_node(cmd, NULL)))
    return (NULL);
  father = head;
  if (!(cmd = create_command_node("bct", &command_bct)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("mct", &command_mct)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("GRAPHIC", &command_graphic)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  return (head);
}

bool		execute_command(t_server *server, t_client *client)
{
  t_list	*cur;
  t_command	*cmd;
  char		*command_name;

  if (!(command_name = strtok(client->buffer, " \t\n")))
    return (false);
  cur = server->cmds;
  while (cur)
  {
    cmd = cur->data;
    if (strcmp(cmd->cmd_name, command_name) == 0)
    {
      cmd->fn(server, client);
      return (true);
    }
    cur = cur->next;
  }
  return (false);
}

void	delete_command(void *_command)
{
  t_command	*command;

  command = _command;
  free(command->cmd_name);
  free(command);
}