/*
** command_take_object.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Thu Jun 29 12:59:50 2017 Pierre
** Last update Thu Jun 29 15:26:38 2017 Pierre
*/

#include "server/command.h"

char **init_check()
{
  char **objects;

  if ((objects = malloc(sizeof(char*) * 8)) == NULL)
    return (NULL    );
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
  char **objects;

  if ((objects = init_check()) == NULL)
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
  if (tile->quantities[object_id] > 0)
    return (1);
  else
    return (0);
}

void	command_take_object(t_server *server, t_client *client)
{
  t_player *player;
  t_stuff *stuff;
  int object_id;

  if ((object_id = check_arg(strtok(NULL, " \t\n"))) == -1)
    {
      send_socket(client->fd, "ko\n");
      return ;
    }
  player = get_player(server->players, client->fd);
  stuff = server->map->data[player->y][player->x].stuff;
  if (check_object(object_id, stuff) == 1)
  {
    server->map->data[player->y][player->x].stuff->quantities[object_id]--;
    player->stuff->quantities[object_id]++;
    send_socket(client->fd, "ok\n");
  }
  else
    send_socket(client->fd, "ko\n");
}
