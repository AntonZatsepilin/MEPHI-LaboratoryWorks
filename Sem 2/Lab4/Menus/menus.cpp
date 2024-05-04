#include "menus.hpp"


action select_action_menu() {
    std::cout << "Select action: " << std::endl;
    std::cout << "0 - exit program" << std::endl;
    std::cout << "1 - size" << std::endl;
    std::cout << "2 - count children" << std::endl;
    std::cout << "3 - height" << std::endl;
    std::cout << "4 - set" << std::endl;
    std::cout << "5 - add child" << std::endl;
    std::cout << "6 - remove child" << std::endl;
    std::cout << "7 - get child" << std::endl;
    std::cout << "8 - traverse" << std::endl;
    std::cout << "9 - count" << std::endl;

    int user_input;
    std::cout << ">>> ";
    std::cin >> user_input;
    panic_if_invalid_input("action");

    switch (user_input) {
        case 0:
            return EXIT;
        case 1:
            return SIZE;
        case 2:
            return CHILDREN_COUNT;
        case 3:
            return HEIGHT;
        case 4:
            return SET;
        case 5:
            return ADD_CHILD;
        case 6:
            return REMOVE_CHILD;
        case 7:
            return GET_CHILD;
        case 8:
            return TRAVERSE;
        case 9:
            return COUNT;
        default:
            throw out_of_range("Index is out of range.");
    }
}


void size_menu(NaryTree<char>* tree) {
    std::cout << "Get size" << std::endl;

    std::cout << "size: " << tree->size() << std::endl;
}


void children_count_menu(NaryTree<char>* tree) {
    std::cout << "Count children" << std::endl;

    std::cout << "amount of children: " << tree->children_count() << std::endl;
}


void height_menu(NaryTree<char>* tree) {
    std::cout << "Get height" << std::endl;

    std::cout << "height: " << tree->height() << std::endl;
}


void set_menu(NaryTree<char>* tree) {
    std::cout << "Set value" << std::endl;

    std::cout << "value: ";
    char value; std::cin >> value;
    panic_if_invalid_input("value");

    tree->set_data(value);
}


void add_child_menu(NaryTree<char>* tree) {
    std::cout << "Add child" << std::endl;

    std::cout << "value: ";
    char value; std::cin >> value;
    panic_if_invalid_input("value");

    tree->add_child(value);
}


void remove_child_menu(NaryTree<char>* tree) {
    std::cout << "Remove child" << std::endl;

    std::cout << "index: ";
    int index; std::cin >> index;
    panic_if_invalid_input("index");

    tree->remove_child(index);
}


void get_child_menu(NaryTree<char>* tree) {
    std::cout << "Get child" << std::endl;

    std::cout << "index: ";
    int index; std::cin >> index;
    panic_if_invalid_input("index");
    
    std::cout << tree->get_child(index)->to_string() << std::endl;
}


void traverse_menu(NaryTree<char>* tree) {
    std::cout << "Traverse" << std::endl;

    Sequence<char>* NLR = tree->traverse(NaryTree<char>::TraverseType::ROOT_LEFT_RIGHT);
    Sequence<char>* NRL = tree->traverse(NaryTree<char>::TraverseType::ROOT_RIGHT_LEFT);
    Sequence<char>* LRN = tree->traverse(NaryTree<char>::TraverseType::LEFT_RIGHT_ROOT);
    Sequence<char>* RLN = tree->traverse(NaryTree<char>::TraverseType::RIGHT_LEFT_ROOT);

    std::cout << "Root-Left-Right: " << *NLR << std::endl;
    std::cout << "Root-Right-Left: " << *NRL << std::endl;
    std::cout << "Left-Right-Root: " << *LRN << std::endl;
    std::cout << "Right-Left-Root: " << *RLN << std::endl;

    delete NLR;
    delete NRL;
    delete LRN;
    delete RLN;
}


void count_menu(NaryTree<char>* tree) {
    std::cout << "Count" << std::endl;

    std::cout << "value: ";
    char value; std::cin >> value;
    panic_if_invalid_input("value");

    std::cout << "amount of '" << value << "': " << tree->count(value) << std::endl;
}


void panic_if_invalid_input(const std::string& argument_name) {
    if (!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw out_of_range("Index is out of range.");
    }
}