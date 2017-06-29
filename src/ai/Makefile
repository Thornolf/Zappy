#*
## Makefile for PSU_2016_zappy in /home/fossae_t/rendu2/PSU_2016_zappy/src/ai
##
## Made by Thomas Fossaert
## Login   <fossae_t@epitech.net>
##
## Started on  Tue Jun 20 10:59:59 2017 Thomas Fossaert
## Last update Sat Jun 24 14:58:39 2017 Thomas Fossaert
##

CXX		=	g++

NAME		=	zappy_ai

RM		=	rm -f

CXXFLAGS	+=	-std=c++11
CXXFLAGS	+=	-Werror -Wall -Wextra
CXXFLAGS	+=	-Iinclude/

SRCS		=	src/main.cpp \
			src/ZappException.cpp \
			src/EventHandler.cpp \
			src/Socket.cpp \
			src/Utils.cpp \
			src/zappy.cpp

OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
