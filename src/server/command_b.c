/*
** command_b.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Jun 29 13:08:00 2017 Guillaume CAUCHOIS
** Last update Thu Jun 29 13:08:00 2017 Guillaume CAUCHOIS
*/

#include "server/command.h"

void		delete_command(void *_command)
{
  t_command	*command;

  command = _command;
  free(command->cmd_name);
  free(command);
}
