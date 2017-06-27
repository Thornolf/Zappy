/*
** player.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:53:04 2017 Guillaume CAUCHOIS
** Last update Fri Jun 23 18:47:19 2017 Pierre
*/

#include	"server/player.h"

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

t_player	*create_player(int y, int x)
{
  t_player	*player;
  static int	id = 0;

  if (!(player = malloc(sizeof(t_player))))
    return (NULL);
  player->id = id++;
  player->lv = 1;
  player->x = x;
  player->y = y;
  player->team = NULL;
  player->stuff = init_stuff();
  player->direction = (t_direction)my_rand(DIRECTION_MIN, DIRECTION_MAX);
  printf("Player %d en [%d][%d], direction %d\n", player->id, y, x, player->direction);
  return (player);
}

t_list		*init_players_list(int y, int x)
{
  t_list	*head;
  t_player	*player;

  head = NULL;
  if ((head = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  player = create_player(y, x);
  head->data = player;
  head->next = NULL;
  return (head);
}

void		add_player(t_list *head, int y, int x)
{
  t_list	*current;

  current = head;
  while (current->next != NULL)
    current = current->next;
  if ((current->next = malloc(sizeof(t_player))) == NULL)
    return ;
  current->next->data = create_player(y, x);
  current->next->next = NULL;
}
