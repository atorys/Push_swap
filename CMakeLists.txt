cmake_minimum_required(VERSION 3.19)
project(pushswap C)

set(CMAKE_C_STANDARD 99)
include_directories(./)

add_executable(pushswap
        main.c)