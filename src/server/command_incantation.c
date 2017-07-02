/*
** command_incantation.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sat Jul 01 13:23:04 2017 Pierre
** Last update Sun Jul 02 11:45:11 2017 Pierre
*/

#include "server/command.h"
#include "server/string.h"
#include "server/player.h"
#include "server/communication.h"

bool		start_incantation(t_server *server, t_client *client)
{
  t_player	*player;

  player = get_player(server->players, client->fd);
  if (player->lv == 8)
  {
    send_socket(client->fd, "ko\n");
    return (false);
  }
  if ((*server->check_level_cmds[player->lv - 1])(server, player->y, player->x) == 0)
  {
    send_socket(client->fd, "ko\n");
    return (false);
  }
  client->incant = true;
  send_socket(client->fd, "Elevation underway\n");
  command_pic(server, client, NULL);
  return (true);
}

void command_incantation(t_server *server, t_client *client, char *arg)
{
  t_player *player;
  char *str;

  (void)arg;
  if (!(player = get_player(server->players, client->fd)))
    return;
  if (player->lv == 8)
  {
    send_socket(client->fd, "ko\n");
    command_pie(server, client, "0");
    return ;
  }
  if ((*server->check_level_cmds[player->lv - 1])(server, player->y, player->x) == 0)
  {
    send_socket(client->fd, "ko\n");
    command_pie(server, client, "0");
    return ;
  }
  player->lv++;
  client->incant = false;
  if (!(str = malloc(sizeof(char) * 18)))
    return ;
  snprintf(str, 18, "Current level: %d\n", player->lv);
  send_socket(client->fd, str);
  command_pie(server, client, "1");
  command_plv_for_plot(server, player->x, player->y);
  command_mct(server, client, NULL);
}

void		command_pic(t_server *server, t_client *client, char *arg)
{
  char		*buf;
  char		*buf_id_players;
  t_player	*player;

  (void)arg;
  if (!(buf = malloc(sizeof(char) * 500)))
    return;
  if (!(player = get_player(server->players, client->fd)))
    return;
  if (!(buf_id_players = player_ids_on_plot_to_string(server->players,
						      player->x, player->y)))
    return;
  snprintf(buf, 500, "pic %d %d %d%s\n", player->x, player->y,
	   player->lv, buf_id_players);
  send_all_graphics(server, buf);
  free(buf);
  free(buf_id_players);
}

void		command_pie(t_server *server, t_client *client, char *arg)
{
  char		*buffer;
  t_player	*player;

  if (!(player = get_player(server->players, client->fd)))
    return;
  if (!(buffer = malloc(sizeof(char) * 500)))
    return;
  if (!arg)
    return;
  snprintf(buffer, 500, "pie %d %d %s\n", player->x, player->y, arg);
  send_all_graphics(server, buffer);
  free(buffer);
}