##
## Makefile for PSU_2016_zappy
##
## Made by Guillaume CAUCHOIS
## Login   <guillaume.cauchois@epitech.eu>
##
## Started on  Tue May 30 12:39:46 2017 Guillaume CAUCHOIS
## Last update Tue May 30 12:39:46 2017 Guillaume CAUCHOIS
##

include			source.mk

NAME_SERVER	=	zappy_server

NAME_AI		=	zappy_ai

CC_C		=	gcc

CC_CC		=	g++

RM		=	@rm -vf

CFLAGS		=	-W -Wall -Wextra -I./inc/

CXXFLAGS	=	-W -Wall -Wextra -I./inc/ -std=c++11

ifeq			($(DEBUG), yes)
CFLAGS		+=	-g -ggdb3
CXXFLAGS	+=	-g -ggdb3
endif			# !_DEBUG_

all:			$(NAME_SERVER) $(NAME_AI)

$(NAME_SERVER):		$(OBJ_SERVER)
			$(CC_C) -o $(NAME_SERVER) $(OBJ_SERVER)

$(NAME_AI):		$(OBJ_AI)
			$(CC_CC) -o $(NAME_AI) $(OBJ_AI)

clean:
			$(RM) $(OBJ_SERVER)
			$(RM) $(OBJ_AI)

fclean:			clean
			$(RM) $(NAME_SERVER)
			$(RM) $(NAME_AI)

re:			fclean all
