/*
** command_incantation.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sat Jul 01 13:23:04 2017 Pierre
** Last update Sun Jul 02 19:19:58 2017 Pierre
*/

#include "server/command.h"
#include "server/string.h"
#include "server/player.h"
#include "server/communication.h"

bool		start_incantation(t_server *s, t_client *client)
{
  t_player	*player;

  player = get_player(s->players, client->fd);
  if (player->lv == 8)
    {
      send_socket(client->fd, "ko\n");
      return (false);
    }
  if ((*s->check_level_cmds[player->lv - 1])(s, player->y, player->x) == 0)
    {
      send_socket(client->fd, "ko\n");
      return (false);
    }
  client->incant = true;
  send_socket(client->fd, "Elevation underway\n");
  command_pic(s, client, NULL);
  return (true);
}

void	failed_incantation(t_server *server, t_client *client)
{
  send_socket(client->fd, "ko\n");
  command_pie(server, client, "0");
  return ;
}

void		command_incant(t_server *s, t_client *client, char *arg)
{
  t_player	*player;
  char		*str;

  (void)arg;
  if (!(player = get_player(s->players, client->fd)))
    return;
  if (player->lv == 8)
    return (failed_incantation(s, client));
  if ((*s->check_level_cmds[player->lv - 1])(s, player->y, player->x) == 0)
    return (failed_incantation(s, client));
  player->lv++;
  client->incant = false;
  if (!(str = malloc(sizeof(char) * 18)))
    return ;
  snprintf(str, 18, "Current level: %d\n", player->lv);
  send_socket(client->fd, str);
  free(str);
  command_pie(s, client, "1");
  command_plv_for_plot(s, player->x, player->y);
  command_mct_all_graphics(s);
}

void		command_pic(t_server *server, t_client *client, char *arg)
{
  char		*buf;
  char		*buf_id_p;
  t_player	*p;

  (void)arg;
  if (!(buf = malloc(sizeof(char) * 500)))
    return;
  if (!(p = get_player(server->players, client->fd)))
    return;
  if (!(buf_id_p = player_ids_on_plot_to_string(server->players, p->x, p->y)))
    return;
  snprintf(buf, 500, "pic %d %d %d%s\n", p->x, p->y, p->lv, buf_id_p);
  send_all_graphics(server, buf);
  free(buf);
  free(buf_id_p);
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
