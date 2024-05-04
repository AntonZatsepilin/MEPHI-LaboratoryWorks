#ifndef menus_hpp
#define menus_hpp

#include <iostream>
#include "../Sequences/Sequences.hpp"

enum actions {
    INPUT, 
    GET_FIRST,
    GET_LAST,
    GET,
    GET_SUB,
    GET_LEN,
    SET,
    APPEND,
    PREPEND,
    INSERT,
    CONCAT,
    CLEAR,
    REMOVE,
    EXIT
};

actions get_action();
Sequence<int>* select_seq(ArraySequence<int>* arr, LinkedListSequence<int>* list);
void input_menu(Sequence<int>* seq);
void get_first_menu(Sequence<int>* seq);
void get_last_menu(Sequence<int>* seq);
void get_menu(Sequence<int>* seq);
void get_sub_menu(Sequence<int>* seq);
void get_len_menu(Sequence<int>* seq);
void set_menu(Sequence<int>* seq);
void append_menu(Sequence<int>* seq);
void prepend_menu(Sequence<int>* seq);
void insert_menu(Sequence<int>* seq);
void concat_menu(Sequence<int>* seq);
void clear_menu(Sequence<int>* seq);
void remove_menu(Sequence<int>* seq);

#endif /* menus_hpp */
