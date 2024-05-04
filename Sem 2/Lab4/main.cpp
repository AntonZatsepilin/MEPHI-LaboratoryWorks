#include "nary_tree.hpp"
#include "Menus/menus.hpp"
#include <stdexcept>

void interaction_loop(NaryTree<char>* tree) {
    action selected_action;
    do {
        try {
            for (int i = 0; i < 3; ++i)
                std::cout << std::endl;

            std::cout<< "N-ary tree: " << tree->to_string() << std::endl << std::endl;

            selected_action = select_action_menu();

            switch (selected_action) {
                case EXIT:
                    break;
                case SIZE:
                    size_menu(tree);
                    break;
                case CHILDREN_COUNT:
                    children_count_menu(tree);
                    break;
                case HEIGHT:
                    height_menu(tree);
                    break;
                case SET:
                    set_menu(tree);
                    break;
                case ADD_CHILD:
                    add_child_menu(tree);
                    break;
                case REMOVE_CHILD:
                    remove_child_menu(tree);
                    break;
                case GET_CHILD:
                    get_child_menu(tree);
                    break;
                case TRAVERSE:
                    traverse_menu(tree);
                    break;
                case COUNT:
                    count_menu(tree);
                    break;
                default:
                    throw out_of_range("Index is out of range.");
            }
        } catch (std::exception &e) {
            std::cout << (e.what());
            std::cout << std::endl;
        }
    } while (selected_action != EXIT);
}


int main() {
    NaryTree<char> tree('A', 5);

    interaction_loop(&tree);

    return 0;
}

