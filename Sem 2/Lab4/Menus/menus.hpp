#ifndef LAB4_MENUS_HPP
#define LAB4_MENUS_HPP

#include <iostream>
#include "../nary_tree.hpp"


enum action {
    EXIT,
    SIZE,
    CHILDREN_COUNT,
    HEIGHT,
    SET,
    ADD_CHILD,
    REMOVE_CHILD,
    GET_CHILD,
    TRAVERSE,
    COUNT,
};

action select_action_menu();

void size_menu(NaryTree<char>* tree);
void children_count_menu(NaryTree<char>* tree);
void height_menu(NaryTree<char>* tree);
void set_menu(NaryTree<char>* tree);
void add_child_menu(NaryTree<char>* tree);
void remove_child_menu(NaryTree<char>* tree);
void get_child_menu(NaryTree<char>* tree);
void traverse_menu(NaryTree<char>* tree);
void count_menu(NaryTree<char>* tree);

void panic_if_invalid_input(const std::string& argument_name);

#endif //LAB4_MENUS_HPP