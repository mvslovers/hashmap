cmake_minimum_required(VERSION 3.8)
project(hashmap)

set(CMAKE_C_STANDARD 11)

set(
    SOURCE_FILES
    src/list.h
    src/list.c
    src/hashing.h
    src/hashing.c
)

add_library(hashmap SHARED ${SOURCE_FILES})
