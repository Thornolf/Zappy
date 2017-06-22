##
## source.mk for PSU_2016_zappy
##
## Made by Guillaume CAUCHOIS
## Login   <guillaume.cauchois@epitech.eu>
##
## Started on  Tue May 30 12:53:16 2017 Guillaume CAUCHOIS
## Last update Tue May 30 12:53:16 2017 Guillaume CAUCHOIS
##

SRC_DIR		=	./src/

SRC_SERVER_DIR	=	$(SRC_DIR)server/
SRC_AI_DIR	=	$(SRC_DIR)ai/

SRC_SERVER	=	$(SRC_SERVER_DIR)main.c		\
			$(SRC_SERVER_DIR)utils_parsing.c \
			$(SRC_SERVER_DIR)handle_parsing.c \
			$(SRC_SERVER_DIR)map.c		\
			$(SRC_SERVER_DIR)player.c	\
		    $(SRC_SERVER_DIR)stuff.c    \
			$(SRC_SERVER_DIR)look_function.c

SRC_AI		=	$(SRC_AI_DIR)main.c

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)
OBJ_AI		=	$(SRC_AI:.c=.o)
