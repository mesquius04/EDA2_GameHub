cmake_minimum_required(VERSION 3.24)
project(untitled16 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled16 main.c main.h visual_functions.c services.c dictionary.c queue_functions.c dictionary.h visual_functions.h services.h queue_functions.h user_functions.c user_functions.h)
