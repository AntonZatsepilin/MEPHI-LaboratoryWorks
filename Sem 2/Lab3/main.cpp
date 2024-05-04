#include <iostream>
#include "Sequences/Sequences.hpp"
#include "Menus/menus.hpp"
#include "Stack.hpp"
#include "Deque.hpp"
using namespace std;




int main() {
    Stack<int> stack;
    Deque<int> deque;
    
    while (true) {
        cout << "Stack: ";
        cout << stack.to_string() << endl;
        cout << "Deque: ";
        cout << deque.to_string() << endl;
        std::cout << "Select an action:" << std::endl;
        std::cout << "1. Push item to stack" << std::endl;
        std::cout << "2. Pop item from stack" << std::endl;
        std::cout << "3. Push item to front of deque" << std::endl;
        std::cout << "4. Push item to back of deque" << std::endl;
        std::cout << "5. Pop item from front of deque" << std::endl;
        std::cout << "6. Pop item from back of deque" << std::endl;
        std::cout << "0. Exit" << std::endl;


        int c = -1;
        cin >> c;
        int item;

        if(c == 0){
            return 0;
        }

        switch(c) {
            case 1:
                std::cout << "Enter the item to push to stack: ";
                cin >> item;
                stack.push(item);
                break;
            case 2:
                if (stack.get_length() > 0) {
                    stack.pop();
                }
                break;
            case 3:
                std::cout << "Enter the item to push to front of deque: ";
                cin >> item;
                deque.push_front(item);
                break;
            case 4:
                std::cout << "Enter the item to push to back of deque: ";
                cin >> item;
                deque.push_back(item);
                break;
            case 5:
                if (deque.get_length() > 0) {
                    deque.pop_front();
                }
                break;
            case 6:
                if (deque.get_length() > 0) {
                    deque.pop_back();
                }
                break;
            default:
                std::cout << "Invalid selection. Try again." << std::endl;
        }
    }
}
