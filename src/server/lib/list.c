/*
** list.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 09:40:51 2017 Guillaume CAUCHOIS
** Last update Tue Jun 20 09:40:51 2017 Guillaume CAUCHOIS
*/

#include "list.h"

t_list		*create_node(void *data, t_list *next)
{
  t_list	*node;

  if (!(node = malloc(sizeof(t_list))))
    return (NULL);
  node->data = data;
  node->next = next;
  return (node);
}