/*
** player.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:53:04 2017 Guillaume CAUCHOIS
** Last update Thu Jun 22 12:42:22 2017 Pierre
*/

#include        "server/player.h"

t_player	*create_player(void)
{
  t_player	*player;
  static int	id = 0;

  if (!(player = malloc(sizeof(t_player))))
    return (NULL);
  player->id = id++;
  player->stuff_list = NULL;
  player->direction = BOTTOM;
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
      printf("le devant\n");
    tmp = tmp->next;
  }
}

t_list    *init_players_list()
{
  t_list *head;
  t_player *player;

  head = NULL;
  if ((head = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  player = create_player();
  head->data = player;
  head->next = NULL;
  return (head);
}

void      add_player(t_list *head, t_list *stuff_list)
{
  t_list *current;

  (void) stuff_list;
  current = head;
  while (current->next != NULL)
    current = current->next;
  if ((current->next = malloc(sizeof(t_player))) == NULL)
    return ;
  current->next->data = create_player();
  current->next->next = NULL;
}
