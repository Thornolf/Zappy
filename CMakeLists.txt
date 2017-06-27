cmake_minimum_required(VERSION 3.7)
project(PSU_2016_zappy)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        inc/server/client.h
        inc/server/command.h
        inc/server/funcs.h
        inc/server/functions.h
        inc/server/list.h
        inc/server/look.h
        inc/server/map.h
        inc/server/player.h
        inc/server/server.h
        inc/server/socket.h
        inc/server/string.h
        inc/server/stuff.h
        inc/server/team.h
        src/ai/include/EventHandler.hpp
        src/ai/include/Socket.hpp
        src/ai/include/ZappException.hpp
        src/ai/include/zappy.hpp
        src/ai/EventHandler.cpp
        src/ai/main.cpp
        src/ai/Socket.cpp
        src/ai/ZappException.cpp
        src/ai/zappy.cpp
        src/server/lib/list.c
        src/server/lib/send.c
        src/server/lib/string.c
        src/server/client.c
        src/server/command.c
        src/server/command_client.c
        src/server/command_map.c
        src/server/command_team.c
        src/server/handle_parsing.c
        src/server/look.c
        src/server/look_utils.c
        src/server/main.c
        src/server/map.c
        src/server/player.c
        src/server/print_vision_a.c
        src/server/print_vision_b.c
        src/server/server.c
        src/server/socket.c
        src/server/stuff.c
        src/server/utils_parsing.c)

include_directories(inc)

set(CFLAGS "-W -Wall -Wextra -Werror")

add_executable(PSU_2016_zappy ${SOURCE_FILES})