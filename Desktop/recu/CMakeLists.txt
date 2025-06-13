cmake_minimum_required(VERSION 3.29)
project(recu C)

set(CMAKE_C_STANDARD 11)

add_executable(recu main.c
        Register.h
        Register.c)
