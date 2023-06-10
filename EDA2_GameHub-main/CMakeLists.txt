cmake_minimum_required(VERSION 3.24)
project(untitled16 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled16 main.c main.h visual_functions.c services.c dictionary.c queue_functions.c dictionary.h visual_functions.h services.h queue_functions.h user_functions.c user_functions.h)
add_custom_command(TARGET untitled16 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/resources/
        $<TARGET_FILE_DIR:untitled16>/)