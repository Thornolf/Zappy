/*
** stuff.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Jun 20 15:09:44 2017 Guillaume CAUCHOIS
** Last update Wed Jun 21 11:03:51 2017 Guillaume CAUCHOIS
*/

# include "server/stuff.h"

t_stuff		*create_stuff_node(t_stuff_type type, t_stuff *next)
{
  t_stuff	*node;

  if (!(node = malloc(sizeof(t_stuff))))
    return (NULL);
  node->stuff = type;
  node->next = next;
  return (node);
}

bool		stuff_type_in_stuff_list(t_stuff_type type, t_stuff *list)
{
  t_stuff	*cur;

  cur = list;
  while (cur)
    {
      if (cur->stuff == type)
	return (true);
    }
  return (false);
}

void		delete_stuff_list(t_stuff *list)
{
  t_stuff	*next;
  t_stuff	*cur;

  cur = list;
  while (cur)
    {
      next = cur->next;
      free(cur);
      cur = next;
    }
}
