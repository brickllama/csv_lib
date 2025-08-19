cmake_minimum_required(VERSION 4.0)
project(csv_lib C)

set(CMAKE_C_STANDARD 11)

add_library(csv_lib SHARED library.c)
