/*
** command_player.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 28 18:21:24 2017 Guillaume CAUCHOIS
** Last update Fri Jun 30 12:04:38 2017 Guillaume CAUCHOIS
*/

#include "server/command.h"
#include "server/string.h"

void	command_ppo(t_server *server, t_client *client)
{
  t_player	*player;
  char		*param;
  int		player_id;
  char		*buffer;

  if (!(param = strtok(NULL, " \t\n")) || !string_is_number(param))
    {
      send_socket(client->fd, "sbp\n");
      return;
    }
  player_id = atoi(param);
  if (!(player = get_player_by_id(server->players, player_id)))
    {
      send_socket(client->fd, "sbp\n");
      return;
    }
  if (!(buffer = malloc(sizeof(char) * 100)))
    return;
  snprintf(buffer, 100, "ppo %d %d %d %d\n", player->id, player->x,
	   player->y, (int)player->direction);
  send_socket(client->fd, buffer);
  free(buffer);
}

void	command_plv(t_server *server, t_client *client)
{
  t_player	*player;
  char		*param;
  int		player_id;
  char		*buffer;

  if (!(param = strtok(NULL, " \t\n")) || !string_is_number(param))
    {
      send_socket(client->fd, "sbp\n");
      return;
    }
  player_id = atoi(param);
  if (!(player = get_player_by_id(server->players, player_id)))
    {
      send_socket(client->fd, "sbp\n");
      return;
    }
  if (!(buffer = malloc(sizeof(char) * 40)))
    return;
  snprintf(buffer, 40, "plv %d %d\n", player->id, player->lv);
  send_socket(client->fd, buffer);
  free(buffer);
}
