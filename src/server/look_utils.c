/*
** vision_list.c for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/src/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Fri Jun 23 12:28:20 2017 Pierre
** Last update Fri Jun 23 12:31:30 2017 Pierre
*/

#include "server/look.h"

t_vision	*create_case_vision(int y, int x)
{
  t_vision	*vision;
  static int	case_nb = 0;

  if (!(vision = malloc(sizeof(t_vision))))
    return (NULL);
  vision->case_nb = case_nb++;
  vision->y = y;
  vision->x = x;
  vision->next = NULL;
  return (vision);
}

t_vision	*init_vision(int y, int x)
{
  t_vision	*head;

  head = create_case_vision(y, x);
  head->next = NULL;
  return (head);
}

void		add_case_vision(t_vision *head, int y, int x)
{
  t_vision *current;

  current = head;
  if (!current)
    return;
  while (current->next != NULL)
    current = current->next;
  if (!(current->next = create_case_vision(y, x)))
    return;
  current->next->next = NULL;
}

int	check_x(int width, int x)
{
  if (x > (width - 1))
    return (-1 + (x - (width - 1)));
  else if (x < 0)
    return (width + x);
  else
    return (x);
}

int	check_y(int height, int y)
{
  if (y > (height - 1))
    return (-1 + (y - (height - 1)));
  else if (y < 0)
    return (height + y);
  else
    return (y);
}
