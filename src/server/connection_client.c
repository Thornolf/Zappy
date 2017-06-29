/*
** command_client.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon Jun 26 15:38:05 2017 Guillaume CAUCHOIS
** Last update Thu Jun 29 14:38:18 2017 Guillaume CAUCHOIS
*/

#include "server/command.h"
#include "server/player.h"
#include "server/string.h"
#include "server/communication.h"

void	connection_graphic(t_server *server, t_client *client)
{
  set_client_type(client, GRAPHIC);
  command_msz(server, client);
  command_sgt(server, client);
  command_mct(server, client);
  command_tna(server, client);
}

bool	connection_ia(t_server *server, t_client *client, char *team_name)
{
  t_player	*player;
  char		*buf;
  int		x;
  int		y;
  int		mod;

  if (!(buf = malloc(sizeof(char) * 400)))
    return (false);
  if (nb_player_in_team(server, team_name) + 1 > server->team_size)
    {
      send_socket(client->fd, "ko\n");
      return (false);
    }
  x = my_rand(0, server->map->width);
  y = my_rand(0, server->map->height);
  if (server->players == NULL)
    server->players = init_players_list(client->fd, y, x);
  else
    add_player(server->players, client->fd, y, x);
  if (!(player = get_player(server->players, client->fd)))
    return (false);
  if (!(assign_player_to_team(server, player, team_name)))
    return (false);
  set_client_type(client, AI);
  mod = server->team_size - nb_player_in_team(server, team_name);
  sprintf(buf, "%d\n%d %d\n", mod, server->map->width, server->map->height);
  send_socket(client->fd, buf);
  command_pnw(server, player);
  return (true);
}

void	command_pnw(t_server *server, t_player *player)
{
  char	*buf;
  char	*n;

  if (!(buf = strdup("pnw ")) || !(n = itos(player->id)))
    return;
  if (!(buf = realloc(buf, strlen(buf) + strlen(n) + 3)))
    return;
  if (!(buf = strcat(buf, n)) || !(buf = strcat(buf, " ")))
    return;
  if (!(n = itos(player->x)))
    return;
  if (!(buf = realloc(buf, strlen(buf) + strlen(n) + 3)))
    return;
  if (!(buf = strcat(buf, n)) || !(buf = strcat(buf, " ")))
    return;
  if (!(n = itos(player->y)))
    return;
  if (!(buf = realloc(buf, strlen(buf) + strlen(n) + 3)))
    return;
  if (!(buf = strcat(buf, n)) || !(buf = strcat(buf, " ")))
    return;
  if (!(n = itos((int)player->direction)))
    return;
  if (!(buf = realloc(buf, strlen(buf) + strlen(n) + 3)))
    return;
  if (!(buf = strcat(buf, n)) || !(buf = strcat(buf, " ")))
    return;
  if (!(n = itos(player->lv)))
    return;
  if (!(buf = realloc(buf, strlen(buf) + strlen(n) + 3)))
    return;
  if (!(buf = strcat(buf, n)) || !(buf = strcat(buf, " ")))
    return;
  if (!(buf = realloc(buf, strlen(buf) + strlen(player->team->name) + 3)))
    return;
  if (!(buf = strcat(buf, player->team->name)))
    return;
  if (!(buf = strcat(buf, "\n")))
    return;
  send_all_graphics(server, buf);
}
