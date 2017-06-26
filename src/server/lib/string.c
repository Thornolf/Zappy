/*
** string.c for PSU_2016_zappy
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Sat Jun 24 11:45:51 2017 Guillaume CAUCHOIS
** Last update Sat Jun 24 11:45:51 2017 Guillaume CAUCHOIS
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