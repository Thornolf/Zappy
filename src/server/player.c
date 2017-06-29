/*
** player.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:53:04 2017 Guillaume CAUCHOIS
** Last update Wed Jun 28 12:45:19 2017 Pierre
*/

#include "server/player.h"
#include "server/server.h"

int		my_rand(int min, int max)
{
  static int	first = 1;

  if (first == 1)
    {
      srand(time(NULL));
      first = 0;
    }
  return (rand() % (max - min) + min);
}

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
  player->team = NULL;
  if (!(player->stuff = init_stuff()))
    return (NULL);
  player->direction = (t_direction)my_rand(DIRECTION_MIN, DIRECTION_MAX);
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

void		delete_player(void *_player)
{
  t_player	*player;

  player = _player;
  free(player);
}

bool		assign_player_to_team(t_server *server, t_player *player, char *team_name)
{
  t_team	*team;

  if (!(team = get_team_by_name(server->teams, team_name)))
    return (false);
  player->team = team;
  return (true);
}

t_player	*get_player_by_id(t_list *list_player, int id)
{
  t_list	*cur;
  t_player	*player;

  cur = list_player;
  while (cur)
  {
    player = cur->data;
    if (player->id == id)
      return (player);
    cur = cur->next;
  }
  return (NULL);
}