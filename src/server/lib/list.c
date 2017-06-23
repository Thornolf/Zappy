/*
** list.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:40:51 2017 Guillaume CAUCHOIS
** Last update Tue Jun 20 09:40:51 2017 Guillaume CAUCHOIS
*/

#include "server/list.h"

t_list		*create_node(void *data, t_list *next)
{
  t_list	*node;

  if (!(node = malloc(sizeof(t_list))))
    return (NULL);
  node->data = data;
  node->next = next;
  return (node);
}

void		remove_node(t_list *list, t_list *node, void(*fn_delete_node)(void *))
{
  t_list	*prev;
  t_list	*cur;

  if (!list || !node)
    return;
  prev = list;
  if (prev == node)
  {
    list = prev->next;
    fn_delete_node(prev->data);
  }
  cur = prev->next;
  while (cur)
  {
    if (cur == node)
    {
      prev->next = cur->next;
      fn_delete_node(cur->data);
      return;
    }
    prev = cur;
    cur = cur->next;
  }
}

void		remove_list(t_list *list, void(*remove_node)(void *))
{
  t_list	*cur;
  t_list	*next;

  cur = list;
  while (cur)
  {
    next = cur->next;
    remove_node(cur->data);
    free(cur);
    cur = next;
  }
}