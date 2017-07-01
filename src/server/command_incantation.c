/*
** command_incantation.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sat Jul 01 13:23:04 2017 Pierre
** Last update Sat Jul 01 15:13:52 2017 Pierre
*/

#include "server/command.h"

void start_incantation(t_server *server, t_client *client)
{
  t_player *player;

  player = get_player(server->players, client->fd);
  if (player->lv == 8)
  {
    send_socket(client->fd, "ko\n");
    return ;
  }
  if (server->check_level_cmds[player->lv - 1] == 0)
  {
    send_socket(client->fd, "ko\n");
    return ;
  }
  //start incantation graphique
}

void command_incantation(t_server *server, t_client *client, char *arg)
{
  t_player *player;

  (void)arg;
  player = get_player(server->players, client->fd);
  if (player->lv == 8)
  {
    send_socket(client->fd, "ko\n");
    return ;
  }
  if (server->check_level_cmds[player->lv - 1] == 0)
  {
    send_socket(client->fd, "ko\n");
    return ;
  }
  player->lv++;
  send_socket(client->fd, "ok\n");
  //stop incantation graphique
}
