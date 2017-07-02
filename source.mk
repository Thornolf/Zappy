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

SRC_SERVER	=	$(SRC_SERVER_DIR)main.c				\
			$(SRC_SERVER_DIR)utils_parsing.c		\
			$(SRC_SERVER_DIR)handle_parsing.c		\
			$(SRC_SERVER_DIR)map.c				\
			$(SRC_SERVER_DIR)player.c			\
			$(SRC_SERVER_DIR)player_b.c			\
			$(SRC_SERVER_DIR)command_look.c			\
			$(SRC_SERVER_DIR)look_utils.c			\
			$(SRC_SERVER_DIR)print_vision_a.c		\
			$(SRC_SERVER_DIR)print_vision_b.c		\
			$(SRC_SERVER_DIR)socket.c			\
			$(SRC_SERVER_DIR)server.c			\
			$(SRC_SERVER_DIR)handle_io.c			\
			$(SRC_SERVER_DIR)client.c			\
			$(SRC_SERVER_DIR)waiting_cmds.c			\
			$(SRC_SERVER_DIR)execute_command.c		\
			$(SRC_SERVER_DIR)command.c			\
			$(SRC_SERVER_DIR)command_b.c			\
			$(SRC_SERVER_DIR)command_map.c			\
			$(SRC_SERVER_DIR)connection_client.c		\
			$(SRC_SERVER_DIR)command_team.c			\
			$(SRC_SERVER_DIR)command_sgt.c			\
			$(SRC_SERVER_DIR)command_broadcast.c		\
			$(SRC_SERVER_DIR)command_inventory.c		\
			$(SRC_SERVER_DIR)command_incantation.c		\
			$(SRC_SERVER_DIR)utils_incantation_a.c		\
			$(SRC_SERVER_DIR)utils_incantation_b.c		\
			$(SRC_SERVER_DIR)utils_object_commands.c	\
			$(SRC_SERVER_DIR)command_take_object.c		\
			$(SRC_SERVER_DIR)command_put_object.c		\
			$(SRC_SERVER_DIR)command_move_player.c		\
			$(SRC_SERVER_DIR)command_connect_nbr.c		\
			$(SRC_SERVER_DIR)command_player.c		\
			$(SRC_SERVER_DIR)command_pin.c			\
			$(SRC_SERVER_DIR)team.c				\
			$(SRC_SERVER_DIR)communication.c		\
			$(SRC_SERVER_DIR)lib/list.c			\
			$(SRC_SERVER_DIR)lib/send.c			\
			$(SRC_SERVER_DIR)lib/string.c

SRC_AI		=	$(SRC_AI_DIR)main.cpp				\
			$(SRC_AI_DIR)ZappException.cpp			\
			$(SRC_AI_DIR)EventHandler.cpp			\
			$(SRC_AI_DIR)Socket.cpp				\
			$(SRC_AI_DIR)Utils.cpp				\
			$(SRC_AI_DIR)zappy.cpp

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)
OBJ_AI		=	$(SRC_AI:.cpp=.o)
