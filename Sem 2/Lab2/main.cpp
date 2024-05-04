#include <iostream>
#include "Sequences/Sequences.hpp"
#include "Menus/menus.hpp"

using namespace std;




int main() {
    ArraySequence<int> array_seq;
    LinkedListSequence<int> linked_list_seq;
    
    while (true) {
        cout << array_seq.to_string() << endl;
        cout << linked_list_seq.to_string() << endl;

        actions action = get_action();

        Sequence<int>* seq;
        if (action != EXIT)
            seq = select_seq(&array_seq, &linked_list_seq);

        switch (action) {
            case INPUT: {
                input_menu(seq);
                break;
            }
            case GET_FIRST: {
                get_first_menu(seq);
                break;
            }
            case GET_LAST: {
                get_last_menu(seq);
                break;
            }
            case GET: {
                get_menu(seq);
                break;
            }
             case GET_SUB: {
                get_sub_menu(seq);
                break;
            }
            case GET_LEN: {
                get_len_menu(seq);
                break;
            }
            case SET: {
                set_menu(seq);
                break;
            }
            case APPEND: {
                append_menu(seq);
                break;
            }
            case PREPEND: {
                prepend_menu(seq);
                break;
            }
            case INSERT: {
                insert_menu(seq);
                break;
            }
            case CONCAT: {
                concat_menu(seq);
                break;
            }
            case CLEAR: {
                clear_menu(seq);
                break;
            }
            case REMOVE: {
                remove_menu(seq);
                break;
            }
            case EXIT: {
                return 0;
            }
        }
    }
    
    return 0;
}
