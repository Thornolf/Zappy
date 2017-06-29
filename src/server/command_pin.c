/*
** command_pin.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 28 19:09:18 2017 Guillaume CAUCHOIS
** Last update Wed Jun 28 19:09:18 2017 Guillaume CAUCHOIS
*/

#include "server/command.h"
#include "server/string.h"

void	command_pin(t_server *server, t_client *client)
{
  t_player	*player;
  char		*param;
  int		player_id;
  char		*buffer;
  int		*qts;

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
  if (!(buffer = malloc(sizeof(char) * 450)))
    return;
  if (!(qts = player->stuff->quantities))
    return;
  snprintf(buffer, 450, "pin %d %d %d %d %d %d %d %d %d %d %d\n", player->id,
	   player->x, player->y, qts[FOOD], qts[FOOD], qts[LINEMATE],
	   qts[DERAUMERE], qts[SIBUR], qts[MENDIANE], qts[PHIRAS],
	   qts[THYSTAME]);
  send_socket(client->fd, buffer);
  free(buffer);
}