cmake_minimum_required(VERSION 3.19)
project(pushswap C)

set(CMAKE_C_STANDARD 99)
include_directories(./)

add_executable(pushswap
        files/push_swap.c
        includes/push_swap.h
        libft/ft_atoi.c
        libft/ft_strdup.c
        libft/ft_split.c
        libft/ft_strchr.c
        libft/ft_substr.c
        libft/ft_strjoin.c
        libft/ft_strlen.c
        libft/ft_putstr_fd.c
        libft/ft_putchar_fd.c
        libft/ft_isdigit.c
        files/utils.c
        files/stack_manipulations/forming.c
        files/stack_manipulations/operations.c
        files/stack_manipulations/double_operations.c files/algorithm/mini_sort.c files/algorithm/tools.c files/input_checker.c files/algorithm/huge_sort.c files/checker/checker.c)