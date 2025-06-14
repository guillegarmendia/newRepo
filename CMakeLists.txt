cmake_minimum_required(VERSION 3.29)
project(newRepo_dev C)

set(CMAKE_C_STANDARD 11)

include_directories(Desktop/recu)

add_executable(newRepo_dev
    Desktop/recu/main.c
    Desktop/recu/Register.c
    Desktop/recu/Register.h
        Desktop/recu/Shop.c
        Desktop/recu/Shop.h)
