/*
** command.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 23 12:49:11 2017 Guillaume CAUCHOIS
** Last update Tue Jun 27 14:17:32 2017 Pierre
*/
#include "server/list.h"
#include "server/command.h"

t_command	*create_command_node(const char *name, int action_time, cmd_func fun, t_client_type type)
{
  t_command	*cmd;

  if (!(cmd = malloc(sizeof(t_command))))
    return (NULL);
  cmd->cmd_name = strdup(name);
  cmd->action_time = action_time;
  cmd->fn = fun;
  cmd->type = type;
  return (cmd);
}

t_list		*init_cmd_callback(void)
{
  t_list	*head;
  t_list	*son;
  t_list	*father;
  t_command	*cmd;

  if (!(cmd = create_command_node("msz", -1, &command_msz, GRAPHIC)))
    return (NULL);
  if (!(head = create_node(cmd, NULL)))
    return (NULL);
  father = head;
  if (!(cmd = create_command_node("bct", -1, &command_bct, GRAPHIC)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("mct", -1, &command_mct, GRAPHIC)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("tna", -1, &command_tna, GRAPHIC)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  /*father = son;
  if (!(cmd = create_command_node("Forward", -1, &command_tna, GRAPHIC)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;*/
  return (head);
}

bool		execute_command(t_server *server, t_client *client)
{
  t_list	*cur;
  t_command	*cmd;
  char		*command_name;

  if (!(command_name = strtok(client->buffer, " \t\n")))
    return (false);
  if (client->type == UNDEFINED)
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
  cur = server->cmds;
  while (cur)
  {
    cmd = cur->data;
    if (strcmp(cmd->cmd_name, command_name) == 0 && cmd->type == client->type)
    {
      //if (client->type == AI)
      //wait_action_time();
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
