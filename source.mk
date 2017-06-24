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
			$(SRC_SERVER_DIR)look.c	\
			$(SRC_SERVER_DIR)look_utils.c	\
			$(SRC_SERVER_DIR)print_vision_a.c \
			$(SRC_SERVER_DIR)print_vision_b.c \
			$(SRC_SERVER_DIR)add_to_inventory.c \
			$(SRC_SERVER_DIR)inventory_cmds_a.c \
			$(SRC_SERVER_DIR)inventory_cmds_b.c \
			$(SRC_SERVER_DIR)stuff.c    \
			$(SRC_SERVER_DIR)socket.c	\
			$(SRC_SERVER_DIR)server.c	\
			$(SRC_SERVER_DIR)client.c	\
			$(SRC_SERVER_DIR)command.c	\
			$(SRC_SERVER_DIR)command_map.c	\
			$(SRC_SERVER_DIR)lib/list.c	\
			$(SRC_SERVER_DIR)lib/send.c

SRC_AI		=	$(SRC_AI_DIR)main.c

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)
OBJ_AI		=	$(SRC_AI:.c=.o)
