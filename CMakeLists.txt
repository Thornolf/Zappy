cmake_minimum_required(VERSION 3.7)
project(PSU_2016_zappy)

set(CMAKE_CXX_STANDARD 11)

include_directories("inc")

set("CFLAGS -W -Wall -Wextra -Werror")

set(SOURCE_FILES_IA
        src/ia/main.c)

set(SOURCE_FILES_SERVER
        src/server/lib/list.c
        src/server/main.c
        src/server/map.c
        src/server/stuff.c
        src/server/player.c)

add_executable(server ${SOURCE_FILES_SERVER})
add_executable(ia ${SOURCE_FILES_IA})