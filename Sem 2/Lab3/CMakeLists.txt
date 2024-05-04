cmake_minimum_required(VERSION 3.22)
project(Lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp Data_structures/data_structures.hpp Data_structures/data_structures.cpp Sequences/Sequences.hpp Sequences/Sequences.cpp Menus/menus.hpp Menus/menus.cpp doctest.h) 