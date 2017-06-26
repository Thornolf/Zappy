/*
** player.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:53:04 2017 Guillaume CAUCHOIS
** Last update Sun Jun 25 15:39:06 2017 Pierre
*/

#include        "server/player.h"

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
  player->inventory = init_inventory();
  player->direction = my_rand(0, 4);
  printf("Player %d en [%d][%d], direction %d\n", player->id, y, x, player->direction);
  return (player);
}

void      print_players(t_list *head)
{
  t_list *tmp;
  t_player *player;

  tmp = head;
  while (tmp)
  {
    player = tmp->data;
    printf("Joueur %d, se dirige vers ", player->id);
    if (player->direction == LEFT)
      printf("la GAUCHE\n");
    else if (player->direction == RIGHT)
      printf("la DROITE\n");
    else if (player->direction == BOTTOM)
      printf("le BAS\n");
    else if (player->direction == TOP)
      printf("le HAUT\n");
    tmp = tmp->next;
  }
}

t_list    *init_players_list(int fd, int y, int x)
{
  t_list *head;
  t_player *player;

  head = NULL;
  if ((head = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  player = create_player(fd, y, x);
  head->data = player;
  head->next = NULL;
  return (head);
}

void      add_player(t_list *head, int fd, int y, int x)
{
  t_list *current;

  current = head;
  while (current->next != NULL)
    current = current->next;
  if ((current->next = malloc(sizeof(t_player))) == NULL)
    return ;
  current->next->data = create_player(fd, y, x);
  current->next->next = NULL;
}
