/*
** utils_object_commands.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 29 15:44:07 2017 Pierre
** Last update Sat Jul 01 23:41:33 2017 Pierre
*/

#include "server/command.h"

char **init_check(char **objects)
{
  if (objects)
    return (objects);
  if ((objects = malloc(sizeof(char*) * 8)) == NULL)
    return (NULL);
  if ((objects[0] = strdup("food")) == NULL)
    return (NULL);
  if ((objects[1] = strdup("linemate")) == NULL)
    return (NULL);
  if ((objects[2] = strdup("deraumere")) == NULL)
    return (NULL);
  if ((objects[3] = strdup("sibur")) == NULL)
    return (NULL);
  if ((objects[4] = strdup("mendiane")) == NULL)
    return (NULL);
  if ((objects[5] = strdup("phiras")) == NULL)
    return (NULL);
  if ((objects[6] = strdup("thystame")) == NULL)
    return (NULL);
  objects[7] = NULL;
  return (objects);
}

int check_arg(char *arg)
{
  int i;
  static char **objects;

  if (arg == NULL)
    return (-1);
  if ((objects = init_check(objects)) == NULL)
    return (-1);
  i = 0;
  while (objects[i])
    {
      if (strcmp(objects[i], arg) == 0)
	return (i);
      i++;
    }
  return (-1);
}

int check_object(int object_id, t_stuff *tile)
{
  if (object_id == -1)
    return (0);
  if (tile->quantities[object_id] > 0)
    return (1);
  else
    return (0);
}
