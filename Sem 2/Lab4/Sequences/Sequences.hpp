#ifndef Sequences_hpp
#define Sequences_hpp

#include <stdio.h>
#include <string>
#include <stdexcept>
#include <sstream>
#include "../Data_structures/data_structures.hpp"

template <class T> class Sequence{
public:
    virtual T get_first() const = 0;
    virtual T get_last() const = 0;
    virtual T get(int index) const = 0;
    virtual Sequence<T>* get_subsequence(int onset_index, int end_index) const = 0;
    virtual int get_length() const = 0;
    virtual void set(int index, T item) = 0;
    virtual void append(T item) = 0;
    virtual void prepend(T item) = 0;
    virtual void insert(int index, T item) = 0;
    virtual Sequence<T>* concat(Sequence<T>* sequence) = 0;
    virtual void clear() = 0;
    virtual void remove(int index) = 0;
    virtual string to_string() const = 0;

    virtual T& operator[](int index) = 0;
    friend std::ostream& operator<<(std::ostream& os, const Sequence<T>& seq) {
        os << seq.to_string();
        return os;
    }

    virtual ~Sequence() = default;
};




template <class T> class ArraySequence: public Sequence<T>{
    DynamicArray<T>* array;
    
public:
    ArraySequence(T* items, int count);
    ArraySequence();
    ArraySequence(const ArraySequence<T> &arraySequence);
    ~ArraySequence();
    T get_first() const override;
    T get_last() const override;
    T get(int index) const override;
    Sequence<T>* get_subsequence(int onset_index, int end_index) const override;
    int get_length() const override;
    void set(int index, T item) override;
    void append(T item) override;
    void prepend(T item) override;
    void insert(int index, T item) override;
    Sequence<T>* concat(Sequence<T>* sequence) override;
    void clear() override;
    void remove(int index) override;
    string to_string() const override;
    T& operator[](int index) override;
};


template <class T> class LinkedListSequence: public Sequence<T>{
    LinkedList<T>* list;
public:
    LinkedListSequence(T* items, int count);
    LinkedListSequence();
    LinkedListSequence(const LinkedListSequence<T> &linkedListSequence);
    ~LinkedListSequence();
    T get_first() const override;
    T get_last() const override;
    T get(int index) const override;
    Sequence<T>* get_subsequence(int start_index, int end_index) const override;
    int get_length() const override;
    void set(int index, T item) override;
    void append(T item) override;
    void prepend(T item) override;
    void insert(int index, T item) override;
    Sequence<T>* concat(Sequence<T>* sequence) override;
    void clear() override;
    void remove(int index) override;
    string to_string() const override;
    T& operator[](int index) override;
};


template<class T>
ArraySequence<T>::ArraySequence(T *items, int count) {
    array = new DynamicArray<T>(items, count);
}

template<class T>
ArraySequence<T>::ArraySequence() {
    array = new DynamicArray<T>(0);
}

template<class T>
ArraySequence<T>::ArraySequence(const ArraySequence<T> &arraySequence) {
    array = new DynamicArray<T>(*arraySequence.array);
}

template<class T>
ArraySequence<T>::~ArraySequence() {
    delete array;
}

template<class T>
T ArraySequence<T>::get_first() const {
    return get(0);
}

template<class T>
T ArraySequence<T>::get_last() const {
    return get(get_length() - 1);
}

template<class T>
T ArraySequence<T>::get(int index) const {
    return array->get(index);
}

template<class T>
Sequence<T>* ArraySequence<T>::get_subsequence(int start_index, int end_index) const {
    if (start_index < 0 || start_index >= get_length())
        throw out_of_range("Index is out of range.");
    
    if (end_index < 0 || end_index >= get_length())
        throw out_of_range("Index is out of range.");
    
    if (end_index < start_index)
        throw out_of_range("Index is out of range.");
    
    auto sub_seq = new ArraySequence<T>;
    for (int i = start_index; i <= end_index; ++i)
        sub_seq->append(get(i));
    return sub_seq;
}

template<class T>
int ArraySequence<T>::get_length() const {
    return array->get_length();
}

template<class T>
void ArraySequence<T>::set(int index, T item) {
    array->set(index, item);
}

template<class T>
void ArraySequence<T>::append(T item) {
    array->resize(get_length() + 1);
    set(get_length() - 1, item);
}

template<class T>
void ArraySequence<T>::prepend(T item) {
    array->resize(get_length() + 1);
    for (int i = get_length() - 1; i > 0; --i)
        set(i, get(i - 1));
    set(0, item);
}

template<class T>
void ArraySequence<T>::insert(int index, T item) {
    if (index < 0 || index > get_length())
        throw out_of_range("Index is out of range.");
    
    if (index == 0)
        prepend(item);
    else if (index == get_length())
        append(item);
    else {
        array->resize(get_length() + 1);
        for (int i = get_length() - 1; i > index; --i)
            set(i, get(i - 1));
        set(index, item);
    }
}

template<class T>
Sequence<T> *ArraySequence<T>::concat(Sequence<T> *sequence) {
    auto concatenation = new ArraySequence<T>(*this);
    for (int i = 0; i < sequence->get_length(); ++i)
        concatenation->append(sequence->get(i));
    return concatenation;
}

template<class T>
void ArraySequence<T>::clear() {
    array->resize(0);
}

template<class T>
void ArraySequence<T>::remove(int index) {
    if (index < 0 || index >= get_length())
        throw out_of_range("Index is out of range.");
    
    for (int i = index; i < get_length() - 1; ++i)
        set(i, get(i + 1));
    array->resize(get_length() - 1);
}



template<class T>
std::string ArraySequence<T>::to_string() const {
    if (get_length() == 0)
        return "[]";

    std::ostringstream oss;
    oss << "[" << get_first();
    for (int i = 1; i < get_length(); ++i)
        oss << ", " << get(i);
    oss << "]";

    return oss.str();
}

template<class T>
T &ArraySequence<T>::operator[](int index) {
    return array->operator[](index);
}








template<class T>
LinkedListSequence<T>::LinkedListSequence(T *items, int count) {
    list = new LinkedList<T>(items, count);
}

template<class T>
LinkedListSequence<T>::LinkedListSequence() {
    list = new LinkedList<T>;
}

template<class T>
LinkedListSequence<T>::LinkedListSequence(const LinkedListSequence<T> &linkedListSequence) {
    list = new LinkedList<T>(*linkedListSequence.list);
}

template<class T>
LinkedListSequence<T>::~LinkedListSequence() {
    delete list;
}

template<class T>
T LinkedListSequence<T>::get_first() const {
    return list->get_first();
}

template<class T>
T LinkedListSequence<T>::get_last() const {
    return list->get_last();
}

template<class T>
T LinkedListSequence<T>::get(int index) const {
    return list->get(index);
}

template<class T>
Sequence<T> *LinkedListSequence<T>::get_subsequence(int start_index, int end_index) const {
    LinkedList<T> sub_list = list->get_sublist(start_index, end_index);
    
    auto sub_seq = new LinkedListSequence<T>;
    for (int i = 0; i < sub_list.get_length(); ++i)
        sub_seq->append(sub_list.get(i));
    return sub_seq;
}

template<class T>
int LinkedListSequence<T>::get_length() const {
    return list->get_length();
}

template<class T>
void LinkedListSequence<T>::set(int index, T item) {
    list->set(index, item);
}

template<class T>
void LinkedListSequence<T>::append(T item) {
    list->append(item);
}

template<class T>
void LinkedListSequence<T>::prepend(T item) {
    list->prepend(item);
}

template<class T>
void LinkedListSequence<T>::insert(int index, T item) {
    list->insert(index, item);
}

template<class T>
Sequence<T> *LinkedListSequence<T>::concat(Sequence<T> *sequence) {
    auto concatenation = new LinkedListSequence<T>(*this);
    for (int i = 0; i < sequence->get_length(); ++i)
        concatenation->append(sequence->get(i));
    return concatenation;
}

template<class T>
void LinkedListSequence<T>::clear() {
    list->clear();
}

template<class T>
void LinkedListSequence<T>::remove(int index) {
    list->remove(index);
}


template<class T>
std::string LinkedListSequence<T>::to_string() const {
    if (get_length() == 0)
        return "[]";

    std::ostringstream oss;
    oss << "[" << get_first();
    for (int i = 1; i < get_length(); ++i)
        oss << ", " << get(i);
    oss << "]";

    return oss.str();
}

template<class T>
T &LinkedListSequence<T>::operator[](int index) {
    return list->operator[](index);
}


#endif /* Sequences_hpp */
