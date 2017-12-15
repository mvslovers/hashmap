cmake_minimum_required(VERSION 3.8)
project(hashmap)

set(CMAKE_C_STANDARD 11)

add_subdirectory(src)

add_executable(hashmap_exec main.c ${SOURCE_FILES})
target_link_libraries(hashmap_exec hashmap)
