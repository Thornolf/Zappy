cmake_minimum_required(VERSION 3.7)
project(PSU_2016_zappy)

include_directories(inc)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        inc/server/client.h
        inc/server/command.h
        inc/server/communication.h
        inc/server/funcs.h
        inc/server/info.h
        inc/server/list.h
        inc/server/look.h
        inc/server/map.h
        inc/server/player.h
        inc/server/server.h
        inc/server/socket.h
        inc/server/string.h
        inc/server/stuff.h
        inc/server/team.h
        inc/ai/EventHandler.hpp
        inc/ai/Socket.hpp
        inc/ai/Utils.hpp
        inc/ai/ZappException.hpp
        inc/ai/zappy.hpp
        src/ai/EventHandler.cpp
        src/ai/main.cpp
        src/ai/Socket.cpp
        src/ai/Utils.cpp
        src/ai/ZappException.cpp
        src/ai/zappy.cpp
        src/server/lib/list.c
        src/server/lib/send.c
        src/server/lib/string.c
        src/server/client.c
        src/server/command.c
        src/server/command_b.c
        src/server/command_broadcast.c
        src/server/command_connect_nbr.c
        src/server/command_inventory.c
        src/server/command_look.c
        src/server/command_map.c
        src/server/command_move_player.c
        src/server/command_pin.c
        src/server/command_player.c
        src/server/command_put_object.c
        src/server/command_sgt.c
        src/server/command_take_object.c
        src/server/command_team.c
        src/server/communication.c
        src/server/connection_client.c
        src/server/execute_command.c
        src/server/handle_io.c
        src/server/handle_parsing.c
        src/server/look_utils.c
        src/server/main.c
        src/server/map.c
        src/server/player.c
        src/server/player_b.c
        src/server/print_vision_a.c
        src/server/print_vision_b.c
        src/server/server.c
        src/server/socket.c
        src/server/team.c
        src/server/utils_object_commands.c
        src/server/utils_parsing.c
        src/server/waiting_cmds.c)

add_executable(PSU_2016_zappy ${SOURCE_FILES})