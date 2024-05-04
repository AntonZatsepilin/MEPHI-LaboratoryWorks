#ifndef Stack_hpp
#define Stack_hpp
#include"Sequences/Sequences.hpp"
template <class T> class Stack: public LinkedListSequence<T>{
    public:
        void push(T item);
        T pop();
        T top() const;
        bool empty() const;
};

template <class T>
void Stack<T>::push(T item) {
    this->prepend(item);
}

template <class T>
T Stack<T>::pop() {
    T val = (*this)[0];
    this->remove(0);
    return val;
}

template <class T>
T Stack<T>::top() const {
    return this->get_first();
}

template <class T>
bool Stack<T>::empty() const {
    return this->get_length() == 0;
}


#endif /* Stack_hpp */