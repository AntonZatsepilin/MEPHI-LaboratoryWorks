#ifndef Stack_hpp
#define Stack_hpp
#include"Sequences/Sequences.hpp"
template <class T> class Stack: public LinkedListSequence<T>{
    public:
        void push(T item);
        void pop();
        T top() const;
};

template <class T>
void Stack<T>::push(T item) {
    this->prepend(item);
}

template <class T>
void Stack<T>::pop() {
    this->remove(0);
}

template <class T>
T Stack<T>::top() const {
    return this->get_first();
}


#endif /* Stack_hpp */