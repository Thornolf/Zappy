/*
** vision.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Sun Jul 02 19:22:50 2017 Guillaume CAUCHOIS
** Last update Sun Jul  2 21:24:22 2017 Guillaume CAUCHOIS
*/

#include "server/look.h"

void	delete_vision_list(t_vision *head)
{
  t_vision	*cur;
  t_vision	*next;

  cur = head;
  while (cur)
    {
      next = cur->next;
      free(cur);
      cur = next;
    }
}
