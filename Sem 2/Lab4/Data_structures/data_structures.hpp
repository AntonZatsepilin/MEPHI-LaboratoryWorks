#ifndef data_structures_hpp
#define data_structures_hpp

#include <stdio.h>
#include <stdexcept>
using namespace std;
template <class T> class DynamicArray{
    int length;
    T* data;
public:
    DynamicArray(T* items, int size);
    DynamicArray(int size);
    DynamicArray(const DynamicArray<T> &dynamicArray);
    ~DynamicArray();
    T get(int index) const;
    int get_length() const;
    void set(int index, T item);
    void resize(int new_size);
    T& operator[](int index);
};



template <class T>
DynamicArray<T>::DynamicArray(T* items, int size){
    length = size;
    data = new T[length];
    for(int i = 0; i < size; ++i)
        data[i] = items[i];
}

template <class T>
DynamicArray<T>::DynamicArray(int size){
    length = size;
    data = new T[length];
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &dynamicArray) {
    length = dynamicArray.get_length();
    data = new T[length];
    for (int i = 0; i < length; ++i)
        data[i] = dynamicArray.get(i);
}

template<class T>
DynamicArray<T>::~DynamicArray(){
    delete [] data;
}

template<class T>
T DynamicArray<T>::get(int index) const{
    if (index < 0 || index >= length)
        throw out_of_range("Index is out of range.");
    return data[index];
}

template<class T>
int DynamicArray<T>::get_length() const{
    return length;
}

template<class T>
void DynamicArray<T>::set(int index, T item){
    if (index < 0 || index >= length)
        throw out_of_range("Index is out of range.");
    data[index] = item;
}

template<class T>
void DynamicArray<T>::resize(int new_size){
    if (new_size < 0) {
        throw invalid_argument("New size cannot be negative.");
    }
    
    if (new_size == length) {
        return;
    }
    
    T* new_data = new T[new_size];
    
    for(int i = 0; i < length && i < new_size; i++)
        new_data[i] = data[i];
    
    delete [] data;
    data = new_data;
    length = new_size;
    
}

template<class T>
T &DynamicArray<T>::operator[](int index) {
    if (index < 0 || index >= length)
        throw out_of_range("Index is out of range.");

    return data[index];
}



template <class T> class LinkedList{
    typedef struct Node{
        T value;
        Node* prev;
        Node* next;
    } node;
    
    typedef struct ListRoot{
        Node* head;
        Node* tail;
    } list_root;
    int length;
    list_root* root;
    node* get_node(int index);
public:
    LinkedList(T* items, int size);
    LinkedList();
    LinkedList(const LinkedList<T> &linkedList);
    ~LinkedList();
    
    T get_first();
    T get_last();
    T get(int index);
    LinkedList<T> get_sublist(int start_index, int end_index);
    int get_length();
    
    void set(int index, T item);
    void append(T item);
    void prepend(T item);
    void insert(int index, T item);
    LinkedList<T> concat(LinkedList<T> list);
    void remove(int index);
    void clear();
    T& operator[](int index);
};

template<class T>
LinkedList<T>::LinkedList(T* items, int size){
    length = size;
    root = new list_root;
    
    if(length == 0){
        root->head = NULL;
        root->tail = NULL;
        return;
    }
    node* start_node = new node;
    start_node->value = items[0];
    start_node->next = NULL;
    start_node->prev = NULL;
    root->head = start_node;
    root->tail = start_node;
    
    for(int i = 1; i < length; ++i){
        node* new_node = new node;
        new_node->value = items[i];
        new_node->next = NULL;
        new_node->prev = start_node;
        start_node->next = new_node;
        start_node = new_node;
        root->tail = new_node;
    }
}

template<class T>
LinkedList<T>::LinkedList(){
    length = 0;
    root = new list_root;
    root->head = NULL;
    root->tail = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &linkedList){
    length = linkedList.length;
    root = new list_root;
    
    if(length == 0){
        root->head = NULL;
        root->tail = NULL;
        return;
    }
    
    node* start_node = new node;
    node* other_start_node = linkedList.root->head;
    start_node->value = other_start_node->value;
    start_node->next = NULL;
    start_node->prev = NULL;
    root->head = start_node;
    root->tail = start_node;
    
    for(int i = 1; i<length; ++i){
        other_start_node = other_start_node->next;
        node* new_node = new node;
        new_node->value = other_start_node->value;
        new_node->next = NULL;
        new_node->prev = start_node;
        start_node->next = new_node;
        start_node = new_node;
        root->tail = start_node;
    }
}

template<class T>
LinkedList<T>::~LinkedList(){
    node* start_node = root->head;
    node* next = NULL;
    while (start_node != NULL) {
        next = start_node->next;
        delete start_node;
        start_node = next;
    }
    delete root;
}

template<class T>
typename LinkedList<T>::node *LinkedList<T>::get_node(int index){
    if (index < 0 || index >= length)
        throw out_of_range("Index is out of range.");
    
    if(index == 0)
        return root->head;
    if(index == length - 1)
        return root->tail;
    if(index < length / 2){
        int start_index = 0;
        node *start_node = root->head;
        while (start_index < index) {
            start_index++;
            start_node = start_node->next;
        }
        
        return start_node;
    } else {
        int start_index = length - 1;
        node *start_node = root->tail;
        while (start_index > index) {
            start_index--;
            start_node = start_node->prev;
        }
        
        return start_node;
    }
}

template<class T>
T LinkedList<T>::get_first(){
    if(length == 0)
        throw out_of_range("Index is out of range.");
    return root->head->value;
}

template<class T>
T LinkedList<T>::get_last(){
    if(length == 0)
        throw out_of_range("Index is out of range.");
    return root->tail->value;
}

template<class T>
T LinkedList<T>::get(int index){
    if (index < 0 || index >= length)
        throw out_of_range("Index is out of range.");
    return get_node(index)->value;
}

template<class T>
LinkedList<T> LinkedList<T>::get_sublist(int onset_index, int end_index) {
    if (onset_index < 0 || onset_index >= length)
        throw out_of_range("Index is out of range.");
    
    if (end_index < 0 || end_index >= length)
        throw out_of_range("Index is out of range.");
    
    if (end_index < onset_index)
        throw out_of_range("Index is out of range.");
    
    LinkedList<T> sublist;
    int start_index = onset_index;
    node* start_node = get_node(onset_index);
    while (start_index <= end_index) {
        sublist.append(start_node->value);
        
        start_index++;
        start_node = start_node->next;
    }
    
    return sublist;
}

template<class T>
int LinkedList<T>::get_length(){
    return length;
}

template<class T>
void LinkedList<T>::set(int index, T item) {
    if (index < 0 || index >= length)
        throw out_of_range("Index is out of range.");
    
    get_node(index)->value = item;
}

template<class T>
void LinkedList<T>::append(T item) {
    node* new_node = new node;
    new_node->value = item;
    new_node->next = NULL;
    length++;
    
    if (length == 1) {
        new_node->prev = NULL;
        root->head = new_node;
        root->tail = new_node;
        return;
    }
    
    new_node->prev = root->tail;
    root->tail->next = new_node;
    root->tail = new_node;
}

template<class T>
void LinkedList<T>::prepend(T item) {
    node* new_node = new node;
    new_node->value = item;
    new_node->prev = NULL;
    length++;
    
    if (length == 1) {
        new_node->next = NULL;
        root->head = new_node;
        root->tail = new_node;
        return;
    }
    
    new_node->next = root->head;
    root->head->prev = new_node;
    root->head = new_node;
}

template<class T>
void LinkedList<T>::insert(int index, T item) {
    if (index < 0 || index > length)
        throw out_of_range("Index is out of range.");
    
    if (index == 0)
        prepend(item);
    else if (index == length)
        append(item);
    else {
        node* prev_node = get_node(index - 1);
        node* new_node = new node;
        new_node->value = item;
        new_node->next = prev_node->next;
        new_node->next->prev = new_node;
        new_node->prev = prev_node;
        prev_node->next = new_node;
        length++;
    }
}

template<class T>
LinkedList<T> LinkedList<T>::concat(LinkedList<T> list) {
    LinkedList<T> concatenation;
    
    node* start_node = root->head;
    while (start_node != NULL) {
        concatenation.append(start_node->value);
        start_node = start_node->next;
    }
    start_node = list.root->head;
    while (start_node != NULL) {
        concatenation.append(start_node->value);
        start_node = start_node->next;
    }
    return concatenation;
}

template<class T>
void LinkedList<T>::clear() {
    node* start_node = root->head;
    node* next = NULL;
    while (start_node != NULL) {
        next = start_node->next;
        delete start_node;
        start_node = next;
    }
    
    root->head = NULL;
    root->tail = NULL;
    length = 0;
}

template<class T>
void LinkedList<T>::remove(int index) {
    if (index < 0 || index >= length)
        throw out_of_range("Index is out of range.");
    
    if (length == 1) {
        delete root->head;
        root->head = NULL;
        root->tail = NULL;
        length = 0;
        return;
    }
    
    if (index == 0) {
        node *new_head = root->head->next;
        new_head->prev = NULL;
        delete root->head;
        root->head = new_head;
    } else if (index == length - 1) {
        node* new_tail = root->tail->prev;
        new_tail->next = NULL;
        delete root->tail;
        root->tail = new_tail;
    } else {
        node* mid_node = get_node(index);
        mid_node->prev->next = mid_node->next;
        mid_node->next->prev = mid_node->prev;
        delete mid_node;
    }
    
    length--;
}

template<class T>
T &LinkedList<T>::operator[](int index) {
    if (index < 0 || index >= length)
        throw out_of_range("Index is out of range.");

    return get_node(index)->value;
}


#endif /* data_structures_hpp */
