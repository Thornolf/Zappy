/*
** player.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:53:04 2017 Guillaume CAUCHOIS
** Last update Sun Jul 02 14:42:13 2017 Pierre
*/

#include <string.h>
#include "server/player.h"
#include "server/server.h"

t_player	*create_player(int fd, int y, int x)
{
  t_player	*player;
  static int	id = 0;

  if (!(player = malloc(sizeof(t_player))))
    return (NULL);
  player->id = id++;
  player->fd = fd;
  player->lv = 1;
  player->x = x;
  player->y = y;
  player->start_time = time(NULL);
  player->team = NULL;
  if (!(player->stuff = init_stuff()))
    return (NULL);
  player->stuff->quantities[FOOD] = 10;
  player->direction = (t_direction)(rand() % (DIR_MAX - DIR_MIN) + DIR_MIN);
  return (player);
}

t_list		*init_players_list(int fd, int y, int x)
{
  t_list	*head;
  t_player	*player;

  head = NULL;
  if ((head = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  player = create_player(fd, y, x);
  head->data = player;
  head->next = NULL;
  return (head);
}

void		add_player(t_list *head, int fd, int y, int x)
{
  t_list	*current;

  current = head;
  while (current->next != NULL)
    current = current->next;
  if ((current->next = malloc(sizeof(t_player))) == NULL)
    return ;
  current->next->data = create_player(fd, y, x);
  current->next->next = NULL;
}

t_player	*get_player(t_list *player_list, int fd)
{
  t_list	*cur;
  t_player	*player;

  cur = player_list;
  while (cur)
    {
      player = cur->data;
      if (player->fd == fd)
	return (player);
      cur = cur->next;
    }
  return (NULL);
}

char		*player_ids_on_plot_to_string(t_list *list,
						  int x, int y)
{
  char		*string;
  t_list	*cur_node;
  t_player	*player;
  int		len_write;
  size_t	limit;

  len_write  = 0;
  cur_node = list;
  if (!(string = malloc(sizeof(char) * 400)))
    return (NULL);
  bzero(string, sizeof(char) * 400);
  while (cur_node)
  {
    player = cur_node->data;
    if (player->x == x && player->y == y)
    {
      limit = (400 - len_write >= 0) ? (size_t)(400 - len_write) : 0;
      len_write += snprintf(string + len_write, limit, " %d", player->id);
      cur_node = cur_node->next;
    }
  }
  return (string);
}

void		delete_player(void *_player)
{
  t_player	*player;

  player = _player;
  free(player);
}
