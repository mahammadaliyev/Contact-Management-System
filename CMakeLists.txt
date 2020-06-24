cmake_minimum_required(VERSION 3.15)
project(ContactManagementSys C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ContactManagementSys
        function.c
        function.h
        main.c
        sort.c
        sort.h)
