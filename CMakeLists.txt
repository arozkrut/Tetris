cmake_minimum_required(VERSION 3.9)
project(Tetris C)

set(CMAKE_C_STANDARD 99 "${CMAKE_C_FLAGS}")

set(CMAKE_C_FLAGS "-lncurses")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Tetris main.c tetris.h randomBlocks.c menu.c display.c windows.c gameplay.c possibleMoves.c drawing.c matrix.c)

target_link_libraries(Tetris ${CURSES_LIBRARIES})