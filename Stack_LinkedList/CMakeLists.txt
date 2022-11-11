cmake_minimum_required(VERSION 3.23)
project(Stack_LinkedList C)

set(CMAKE_C_STANDARD 99)

add_executable(Stack_LinkedList main.c Stack.h Stack.c)
