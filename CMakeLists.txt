cmake_minimum_required(VERSION 3.8)
project(hashmap)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c item.h item.c)
add_executable(hashmap ${SOURCE_FILES})
