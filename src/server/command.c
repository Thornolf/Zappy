/*
** command.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 23 12:49:11 2017 Guillaume CAUCHOIS
** Last update Thu Jun 29 15:40:39 2017 Pierre
*/
#include "server/list.h"
#include "server/command.h"

t_command	*create_command_node(const char *name, time_t action_time, cmd_func fun, t_client_type type)
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

t_list		*init_cmd_callback_graphic(void)
{
  t_command	*cmd;
  t_list	*head;
  t_list	*father;
  t_list	*son;

  if (!(cmd = create_command_node("msz", -1, &command_msz, GRAPHIC)) ||
      !(head = create_node(cmd, NULL)))
    return (NULL);
  father = head;
  if (!(cmd = create_command_node("bct", -1, &command_bct, GRAPHIC)) ||
      !(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("mct", -1, &command_mct, GRAPHIC)) ||
      !(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("tna", -1, &command_tna, GRAPHIC)) ||
      !(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("ppo", -1, &command_ppo, GRAPHIC)) ||
      !(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("plv", -1, &command_plv, GRAPHIC)) ||
      !(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("pin", -1, &command_pin, GRAPHIC)) ||
      !(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("sgt", -1, &command_sgt, GRAPHIC)) ||
      !(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  return (head);
}

t_list		*init_cmd_callback_ai(t_list *head)
{
  t_list	*father;
  t_list	*son;
  t_command	*cmd;

  if (!(father = get_last_node(head)))
    return (NULL);
  if (!(cmd = create_command_node("Forward", 7, &command_turn_left, AI)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("Right", 7, &command_turn_right, AI)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("Left", 7, &command_move_player, AI)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("Look", 7, &command_look, AI)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("Inventory", 1, &command_inventory, AI)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("Take", 7, &command_take_object, AI)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("Set", 7, &command_put_object, AI)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  father = son;
  if (!(cmd = create_command_node("Connect_nbr", 0, &command_connect_nbr, AI)))
    return (NULL);
  if (!(son = create_node(cmd, NULL)))
    return (NULL);
  father->next = son;
  return (head);
}

t_list		*init_cmd_callback(void)
{
  t_list	*head;

  if (!(head = init_cmd_callback_graphic()))
    return (NULL);
  if (!(head = init_cmd_callback_ai(head)))
    return (NULL);
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
	  if (client->type == AI)
	    add_waiting_cmd(server, cmd, client);
	  else if (client->type == GRAPHIC)
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
