#include "menus.hpp"


actions get_action(){
    int steps = 0;
    while(steps < 1000){
        steps++;

        std::cout << "Select an action:" << std::endl;
        std::cout << "1. Input sequence" << std::endl;
        std::cout << "2. Get the first item" << std::endl;
        std::cout << "3. Get the last item" << std::endl;
        std::cout << "4. Get an item at a specific index" << std::endl;
        std::cout << "5. Get a subsequence" << std::endl;
        std::cout << "6. Get the length" << std::endl;
        std::cout << "7. Set an item at a specific index" << std::endl;
        std::cout << "8. Append an item" << std::endl;
        std::cout << "9. Prepend an item" << std::endl;
        std::cout << "10. Insert an item at a specific index" << std::endl;
        std::cout << "11. Concatenate with another sequence" << std::endl;
        std::cout << "12. Clear the sequence" << std::endl;
        std::cout << "13. Remove an item at a specific index" << std::endl;
        std::cout << "14. Exit" << std::endl;
        int action;
        std::cin >> action;

        switch (action)
        {
        case 1:
            return INPUT;
        case 2:
            return GET_FIRST;
        case 3:
            return GET_LAST;
        case 4:
            return GET;
        case 5:
            return GET_SUB;
        case 6:
            return GET_LEN;
        case 7:
            return SET;
        case 8:
            return APPEND;
        case 9:
            return PREPEND;
        case 10:
            return INSERT;
        case 11:
            return CONCAT;
        case 12:
            return CLEAR;
        case 13:
            return REMOVE;
        case 14:
            return EXIT;

        default:
            std::cout << "Error, try again." << std::endl;
            break;
        }
    }
    return EXIT;
}


Sequence<int>* select_seq(ArraySequence<int>* arr, LinkedListSequence<int>* list){
    int steps = 0;
    while(steps < 1000){
        steps++;

        std::cout << "Select sequence:" << endl;
        std::cout << "1. ArraySequence" << endl;
        std::cout << "2. LinkedListSequence" << endl;
        int seq;
        std::cin >> seq;
        if (seq == 1) return arr;
        else if (seq == 2) return list;
        else std::cout << "Error, try again." << std::endl;
    }
    return arr;
}


void input_menu(Sequence<int>* seq){
    std::cout << "Enter a number of items: ";

    int size;
    std::cin >> size;

    if (size < 0)
        throw out_of_range("Size cannot be less than 0");

    seq->clear();
    if (size == 0) return;

    std::cout << "Enter items: ";
    for (int i = 0; i < size; i++){
        int x;
        cin >> x;
        seq->append(x);
    }
}

void get_first_menu(Sequence<int>* seq){
    std::cout << "The first element of the sequence: " << seq->get_first() << std::endl;
}

void get_last_menu(Sequence<int>* seq){
    std::cout << "The last element of the sequence: " << seq->get_last() << std::endl;
}

void get_menu(Sequence<int>* seq){
    std::cout << "Enter the index of the item you want to output: ";

    int index;
    std::cin >> index;

    std::cout << "Item at index " << index << " " << seq->get(index) << std::endl;;
}

void get_sub_menu(Sequence<int>* seq){
    std::cout << "Enter from which to which indexes you want to output the subsequence: ";
    
    int start_index, end_index;
    std::cin >> start_index >> end_index;
    std::cout << "At your request ";
    std::cout << seq->get_subsequence(start_index, end_index)->to_string();
    std::cout << endl;
}

void get_len_menu(Sequence<int>* seq){
    cout << "The length of your sequence: " << seq->get_length() << endl;
}

void set_menu(Sequence<int>* seq){
    int item, index;
    std::cout << "Enter the element index and the element you want to replace it with: ";
    std::cin >> index >> item;
    seq->set(index, item);
    std::cout << endl;
}

void append_menu(Sequence<int>* seq){
    std::cout << "Enter the item you want to append: ";

    int item;
    std::cin >> item;
    seq->append(item);

    std::cout << endl;
}

void prepend_menu(Sequence<int>* seq){
     std::cout << "Enter the item you want to prepend: ";

    int item;
    std::cin >> item;
    seq->prepend(item);

    std::cout << endl;
}

void insert_menu(Sequence<int>* seq){
    std::cout << "Enter the index and the item you want to insert: ";

    int index, item;
    std::cin >> index >> item;
    seq->insert(index, item);
    cout << endl;
}

void concat_menu(Sequence<int>* seq){
    Sequence<int>* concat_seq;
    std::cout << "Enter a number of items: ";

    int size;
    std::cin >> size;

    if (size < 0)
        throw out_of_range("Size cannot be less than 0");

    if (size == 0) return;

    std::cout << "Enter items: ";
    for (int i = 0; i < size; i++){
        int x;
        std::cin >> x;
        concat_seq->append(x);
    }
    seq->concat(concat_seq);
    std::cout << endl;
}

void clear_menu(Sequence<int>* seq){
    seq->clear();
    std::cout << endl;
}

void remove_menu(Sequence<int>* seq){
    std::cout << "Enter the index of the item you want to delete: ";

    int index;
    std::cin >> index;

    seq->remove(index);
    std::cout << endl;
}