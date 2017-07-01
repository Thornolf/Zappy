/*
** incantation.h for PSU_2016_zappy in /home/pierre/PSU_2016_zappy/inc/server
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Sat Jul 01 15:08:22 2017 Pierre
** Last update Sat Jul 01 15:08:46 2017 Pierre
*/

#ifndef INCANTATION_H_
# define INCANTATION_H_

typedef int (*check_level_t)(void *_server, int y, int x);
int check_level_2(void *_server, int y, int x);
int check_level_3(void *_server, int y, int x);
int check_level_4(void *_server, int y, int x);
int check_level_5(void *_server, int y, int x);
int check_level_6(void *_server, int y, int x);
int check_level_7(void *_server, int y, int x);
int check_level_8(void *_server, int y, int x);

#endif
