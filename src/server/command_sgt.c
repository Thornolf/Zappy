/*
** command_sgt.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Jun 29 11:21:10 2017 Guillaume CAUCHOIS
** Last update Sat Jul 01 22:03:44 2017 Pierre
*/

#include "server/command.h"
#include "server/string.h"

void	command_sgt(t_server *server, t_client *client, char *arg)
{
  char	*buf;

  (void)arg;
  if (!(buf = malloc(sizeof(char) * 100)))
    return;
  snprintf(buf, 100, "sgt %d\n", server->freq);
  send_socket(client->fd, buf);
  free(buf);
}

void	command_sst(t_server *server, t_client *client, char *arg)
{
  char	*new_freq_str;
  int	new_freq;

  (void)arg;
  if (!(new_freq_str = strtok(NULL, " \t\n")) || !string_is_number(new_freq_str))
  {
    send_socket(client->fd, "sbp\n");
    return;
  }
  new_freq = atoi(new_freq_str);
  server->freq = new_freq;
  command_sgt(server, client, NULL);
}