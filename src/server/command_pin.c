/*
** command_pin.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 28 19:09:18 2017 Guillaume CAUCHOIS
** Last update Sun Jul 02 14:20:14 2017 Pierre
*/

#include "server/command.h"
#include "server/string.h"

void send_sbp(int fd)
{
  send_socket(fd, "sbp\n");
  return ;
}

void		command_pin(t_server *server, t_client *client, char *arg)
{
  t_player	*player;
  char		*param;
  int		player_id;
  char		*buffer;
  int		*qts;

  (void)arg;
  if (!(param = strtok(NULL, " \t\n")) || !string_is_number(param))
    return (send_sbp(client->fd));
  player_id = atoi(param);
  if (!(player = get_player_by_id(server->players, player_id)) ||
      !(buffer = malloc(sizeof(char) * 450)) ||
      !(qts = player->stuff->quantities))
    return (send_sbp(client->fd));
  snprintf(buffer, 450, "pin %d %d %d %d %d %d %d %d %d %d %d\n", player->id,
	   player->x, player->y, qts[FOOD], qts[FOOD], qts[LINEMATE],
	   qts[DERAUMERE], qts[SIBUR], qts[MENDIANE], qts[PHIRAS],
	   qts[THYSTAME]);
  send_socket(client->fd, buffer);
  free(buffer);
  free(param);
}
