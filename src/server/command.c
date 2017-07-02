/*
** command.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 23 12:49:11 2017 Guillaume CAUCHOIS
** Last update Sat Jul 01 15:11:17 2017 Pierre
*/
#include "server/list.h"
#include "server/command.h"

t_command	*create_command_node(const char *name, time_t action_time,
				     cmd_func fun, t_client_type type)
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

  head = NULL;
  if (!(cmd = create_command_node("msz", -1, &command_msz, GRAPHIC)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("bct", -1, &command_bct, GRAPHIC)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("mct", -1, &command_mct, GRAPHIC)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("tna", -1, &command_tna, GRAPHIC)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("ppo", -1, &command_ppo, GRAPHIC)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("plv", -1, &command_plv, GRAPHIC)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("pin", -1, &command_pin, GRAPHIC)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("sgt", -1, &command_sgt, GRAPHIC)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("sst", -1, &command_sst, GRAPHIC)) ||
      !(append_data(&head, cmd)))
    return (NULL);
  return (head);
}

t_list		*init_cmd_callback_ai(t_list *head)
{
  t_command	*cmd;

  if (!(cmd = create_command_node("Forward", 7, &command_move_player, AI)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("Right", 7, &command_turn_right, AI)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("Left", 7, &command_turn_left, AI)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("Look", 7, &command_look, AI)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("Take", 7, &command_take_object, AI)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("Inventory", 1, &command_inventory, AI)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("Connect_nbr", 0, &command_connect_nbr, AI))
      || !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("Set", 7, &command_put_object, AI)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("Incantation", 300, &command_incantation, AI)) ||
      !(append_data(&head, cmd)) ||
      !(cmd = create_command_node("Broadcast", 7, &command_broadcast, AI)) ||
      !(append_data(&head, cmd)))
    return (NULL);
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
