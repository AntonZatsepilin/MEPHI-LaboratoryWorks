#ifndef Deque_hpp
#define Deque_hpp
#include"Sequences/Sequences.hpp"
template <class T>

class Deque : public LinkedListSequence<T> {
public:
    void push_front(T item);
    void push_back(T item);
    void pop_front();
    void pop_back();
    T front() const;
    T back() const;
};

template <class T>
void Deque<T>::push_front(T item) {
    this->prepend(item);
}

template <class T>
void Deque<T>::push_back(T item) {
    this->append(item);
}

template <class T>
void Deque<T>::pop_front() {
    this->remove(0);
}

template <class T>
void Deque<T>::pop_back() {
    this->remove(this->get_length() - 1);
}

template <class T>
T Deque<T>::front() const {
    return this->get_first();
}

template <class T>
T Deque<T>::back() const {
    return this->get_last();
}

#endif /* Deque_hpp */