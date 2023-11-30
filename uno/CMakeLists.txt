cmake_minimum_required(VERSION 3.0)

project(game C)

set(CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_C_FLAFS "-std=c99 -g -Wall")

add_executable(game game.c deck.c card.c error.c)

target_link_libraries(game m bsd)