cmake_minimum_required(VERSION 3.22)
project(Lab4)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp Data_structures/data_structures.hpp Data_structures/data_structures.cpp Sequences/Sequences.hpp Sequences/Sequences.cpp Menus/menus.hpp Menus/menus.cpp nary_tree.hpp) 
add_executable(test Tests.cpp Data_structures/data_structures.hpp Data_structures/data_structures.cpp Sequences/Sequences.hpp Sequences/Sequences.cpp doctest.h nary_tree.hpp) 