cmake_minimum_required(VERSION 3.20)
project(ft_nm C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_nm main.c sources/main.c sources/handle_file.c headers/main.h)
