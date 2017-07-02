/*
** move_player.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sun Jun 25 15:16:16 2017 Pierre
** Last update Sat Jul 01 10:21:42 2017 Pierre
*/

#include "server/server.h"
#include "server/command.h"

void		command_turn_left(t_server *server, t_client *client, char *arg)
{
  int		new_dir;
  t_player	*player;

  (void)arg;
  if (!(player = get_player(server->players, client->fd)))
    return;
  new_dir = player->direction;
  new_dir--;
  if (new_dir < 0)
    new_dir = LEFT;
  player->direction = (t_direction)new_dir;
  send_socket(client->fd, "ok\n");
}

void command_turn_right(t_server *server, t_client *client, char *arg)
{
  t_player	*player;
  int		new_dir;

  (void)arg;
  if (!(player = get_player(server->players, client->fd)))
    return;
  new_dir = player->direction;
  new_dir++;
  if (new_dir > 3)
    new_dir = TOP;
  player->direction = (t_direction)new_dir;
  send_socket(client->fd, "ok\n");
}

void command_move_player(t_server *server, t_client *client, char *arg)
{
  t_player *player;

  (void)arg;
  if (!(player = get_player(server->players, client->fd)))
    return;
  if (player->direction == TOP)
    player->y = check_y(server->map->height, player->y - 1);
  else if (player->direction == BOTTOM)
    player->y = check_y(server->map->height, player->y + 1);
  else if (player->direction == LEFT)
    player->x = check_x(server->map->width, player->x - 1);
  else if (player->direction == RIGHT)
    player->x = check_x(server->map->width, player->x + 1);
  send_socket(client->fd, "ok\n");
}
