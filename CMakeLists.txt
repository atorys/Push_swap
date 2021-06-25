cmake_minimum_required(VERSION 3.19)
project(pushswap C)

set(CMAKE_C_STANDARD 99)
include_directories(./)

add_executable(pushswap
        files/push_swap.c
        push_swap.h
        libft/ft_atoi.c
        libft/ft_putstr_fd.c
        libft/ft_putchar_fd.c
        libft/ft_isdigit.c
        files/utils.c
        files/swap_a.c files/stack_utils.c files/operations.c)