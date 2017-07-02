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

bool start_incantation(t_server *server, t_client *client)
{
  t_player *player;

  player = get_player(server->players, client->fd);
  if (player->lv == 8)
  {
    send_socket(client->fd, "ko\n");
    return (false);
  }
  if ((*server->check_level_cmds[player->lv - 1])(server, player->y, player->x) == 0)
  {
    printf("pas bon\n");
    send_socket(client->fd, "ko\n");
    return (false);
  }
  client->incant = true;
  printf("on lance l'incant\n");
  send_socket(client->fd, "Elevation underway\n");
  return (true);
  //start incantation graphique
}

void command_incantation(t_server *server, t_client *client, char *arg)
{
  t_player *player;
  char *str;

  (void)arg;
  player = get_player(server->players, client->fd);
  if (player->lv == 8)
  {
    send_socket(client->fd, "ko\n");
    return ;
  }
  if ((*server->check_level_cmds[player->lv - 1])(server, player->y, player->x) == 0)
  {
    send_socket(client->fd, "ko\n");
    return ;
  }
  player->lv++;
  client->incant = false;
  printf("incant finie\n");
  if (!(str = malloc(sizeof(char) * 18)))
    return ;
  snprintf(str, 18, "Current level: %d\n", player->lv);
  send_socket(client->fd, str);
  //stop incantation graphique
}
