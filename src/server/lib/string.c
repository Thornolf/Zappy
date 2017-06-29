/*
** string.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Sat Jun 24 11:45:51 2017 Guillaume CAUCHOIS
** Last update Thu Jun 29 14:47:29 2017 Guillaume CAUCHOIS
*/

#include "server/string.h"

bool	string_is_number(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  if (i != 0 || str[i] != '-')
	    return (false);
	}
    }
  return (true);
}

char		*itos(int nb)
{
  int		nb_save;
  size_t	len;
  char		*buf;

  nb_save = nb;
  len = 0;
  while (nb > 0)
    {
      nb = nb / 10;
      len++;
    }
  if (!(buf = malloc(sizeof(char) * (len + 2))))
    return (NULL);
  if (nb_save == 0)
    {
      buf[0] = '0';
      buf[1] = 0;
    }
  else
    snprintf(buf, len + 1, "%d", nb_save);
  return (buf);
}
