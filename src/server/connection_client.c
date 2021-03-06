/*
** command_client.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon Jun 26 15:38:05 2017 Guillaume CAUCHOIS
** Last update Sun Jul  2 21:25:11 2017 Guillaume CAUCHOIS
*/

#include "server/command.h"
#include "server/player.h"
#include "server/string.h"
#include "server/communication.h"

void	connection_graphic(t_server *server, t_client *client)
{
  client->type = GRAPHIC;
  command_msz(server, client, NULL);
  command_sgt(server, client, NULL);
  command_mct(server, client, NULL);
  command_tna(server, client, NULL);
}

bool		connection_ia(t_server *s, t_client *client, char *team_name)
{
  t_player	*player;
  char		*buf;
  int		mod;

  if (!(buf = malloc(sizeof(char) * 400)) ||
      nb_player_in_team(s, team_name) + 1 > s->team_size)
    {
      send_socket(client->fd, "ko\n");
      return (false);
    }
  if (s->players == NULL)
    s->players = init_players_list(client->fd, rand() % s->map->height,
				   rand() % s->map->width);
  else
    add_player(s->players, client->fd, rand() % s->map->height,
	       rand() % s->map->width);
  if (!(player = get_player(s->players, client->fd)) ||
      !(assign_player_to_team(s, player, team_name)))
    return (false);
  client->type = AI;
  mod = s->team_size - nb_player_in_team(s, team_name);
  snprintf(buf, 400, "%d\n%d %d\n", mod, s->map->width, s->map->height);
  send_socket(client->fd, buf);
  command_pnw(s, player, NULL);
  return (true);
}

void	command_pnw(t_server *server, t_player *player, char *arg)
{
  char	*buf;

  (void)arg;
  if (!(buf = malloc(sizeof(char) * 1000)))
    return;
  snprintf(buf, 1000, "pnw %d %d %d %d %d %s\n",
	   player->id, player->x, player->y, player->direction, player->lv,
	   player->team->name);
  send_all_graphics(server, buf);
  free(buf);
}
