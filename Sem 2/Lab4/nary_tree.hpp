#ifndef LAB4_N_ARY_TREE_HPP
#define LAB4_N_ARY_TREE_HPP

#include"Sequences/Sequences.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
#include"Stack.hpp"
#include <limits>



template <class T> class NaryTree {
    T data;
    int max_children;
    Sequence<NaryTree<T>*>* children;

    Sequence<T>* traverse_root_left_right() const;
    Sequence<T>* traverse_root_right_left() const;
    Sequence<T>* traverse_left_right_root() const;
    Sequence<T>* traverse_right_left_root() const;

public:
    enum TraverseType {
        ROOT_LEFT_RIGHT,
        ROOT_RIGHT_LEFT,
        LEFT_RIGHT_ROOT,
        RIGHT_LEFT_ROOT,
    };

public:
    NaryTree(T root_value, int max_children);
    explicit NaryTree(T root_value);
    NaryTree(const NaryTree<T>& tree);

    ~NaryTree();

    [[nodiscard]] size_t size() const;
    [[nodiscard]] size_t children_count() const;
    [[nodiscard]] size_t max_children_count() const;
    [[nodiscard]] size_t height() const;
    T get_data() const;
    void set_data(T new_data);

    void add_child(T child);
    void add_child(NaryTree<T>* child);
    NaryTree<T>* get_child(int index) const;
    void remove_child(int index);

    Sequence<T>* traverse() const;
    Sequence<T>* traverse(TraverseType traverse_type) const;

    [[nodiscard]] std::string to_string() const;
    [[nodiscard]] std::string to_string(TraverseType traverse_type) const;

    NaryTree<T>* map(T (*func)(T)) const;
    NaryTree<T>* where(bool (*func)(T)) const;

    int count(T get_data) const;
    bool contains(const NaryTree<T>& subtree) const;

    NaryTree<T>& operator[](int index);

    friend bool operator!=(const NaryTree<T> &l, const NaryTree<T> &r) {
        if (l.get_data() != r.get_data())
            return true;
        if (l.max_children_count() != r.max_children_count())
            return true;
        if (l.children_count() != r.children_count())
            return true;

        for (int i = 0; i < l.children_count(); ++i)
            if (*l.get_child(i) != *r.get_child(i))
                return true;

        return false;
    }

    friend bool operator==(const NaryTree<T> &l, const NaryTree<T> &r) {
        if (l.get_data() != r.get_data())
            return false;
        if (l.max_children_count() != r.max_children_count())
            return false;
        if (l.children_count() != r.children_count())
            return false;

        for (int i = 0; i < l.children_count(); ++i)
            if (*l.get_child(i) != *r.get_child(i))
                return false;

        return true;
    }

    friend std::ostream& operator<<(std::ostream& os, const NaryTree<T>& tree) {
        os << tree.to_string();
        return os;
    }
};

template<class T>
NaryTree<T>::NaryTree(T root_value): NaryTree(root_value, std::numeric_limits<int>::max()) {} 
template<class T>
NaryTree<T>::NaryTree(T root_value, int max_children): max_children(max_children) {
    if (max_children < 1)
        throw out_of_range("Index is out of range.");

    children = new LinkedListSequence<NaryTree<T>*>;
    data = root_value;
}

template<class T>
NaryTree<T>::NaryTree(const NaryTree<T> &tree) {
    children = new LinkedListSequence<NaryTree<T>*>;
    max_children = tree.max_children;
    data = tree.data;

    for (int i = 0; i < tree.children_count(); ++i)
        children->append(new NaryTree<T>(*tree.get_child(i)));
}

template<class T>
NaryTree<T>::~NaryTree() {
    for (int i = 0; i < children->get_length(); ++i)
        delete children->get(i);
    delete children;
}

template<class T>
size_t NaryTree<T>::size() const {
    size_t result = 1;
    for (int i = 0; i < children->get_length(); ++i)
        result += children->get(i)->size();
    return result;
}

template<class T>
size_t NaryTree<T>::children_count() const {
    return children->get_length();
}

template<class T>
size_t NaryTree<T>::max_children_count() const {
    return (size_t)max_children;
}

template<class T>
size_t NaryTree<T>::height() const {
    if (children->get_length() == 0)
        return 1;

    size_t max_child_height = 0;
    for (int i = 0; i < children_count(); ++i) {
        size_t child_height = get_child(i)->height();
        if (child_height > max_child_height)
            max_child_height = child_height;
    }

    return max_child_height + 1;
}

template<class T>
T NaryTree<T>::get_data() const {
    return data;
}

template<class T>
void NaryTree<T>::set_data(T new_data) {
    data = new_data;
}

template<class T>
void NaryTree<T>::add_child(T child) {
    if (children->get_length() == max_children)
        throw out_of_range("Index is out of range.");

    children->append(new NaryTree<T>(child, max_children));
}

template<class T>
void NaryTree<T>::add_child(NaryTree<T> *child) {
    if (children->get_length() == max_children)
        throw out_of_range("Index is out of range.");
    if (child->max_children != max_children)
        throw out_of_range("Index is out of range.");
    
    children->append(new NaryTree<T>(*child));
}

template<class T>
NaryTree<T>* NaryTree<T>::get_child(int index) const {
    return children->get(index);
}

template<class T>
void NaryTree<T>::remove_child(int index) {
    delete children->get(index);
    children->remove(index);
}

template<class T>
Sequence<T> *NaryTree<T>::traverse() const {
    return traverse(ROOT_LEFT_RIGHT);
}

template<class T>
Sequence<T> *NaryTree<T>::traverse(NaryTree::TraverseType traverse_type) const {
    switch (traverse_type) {
        case ROOT_LEFT_RIGHT:
            return traverse_root_left_right();
        case ROOT_RIGHT_LEFT:
            return traverse_root_right_left();
        case LEFT_RIGHT_ROOT:
            return traverse_left_right_root();
        case RIGHT_LEFT_ROOT:
            return traverse_right_left_root();
        default:
            throw out_of_range("Index is out of range.");
    }
}

template<class T>
Sequence<T> *NaryTree<T>::traverse_root_left_right() const {
    Sequence<T>* result = new LinkedListSequence<T>;
    Stack<const NaryTree<T>*> stack;
    stack.push(this);

    while (!stack.empty()) {
        const NaryTree<T>* current = stack.pop();
        result->append(current->get_data());

        for (int i = current->children_count() - 1; i >= 0; --i)
            stack.push(current->get_child(i));
    }

    return result;
}

template<class T>
Sequence<T> *NaryTree<T>::traverse_root_right_left() const {
    Sequence<T>* result = new LinkedListSequence<T>;
    Stack<const NaryTree<T>*> stack;
    stack.push(this);

    while (!stack.empty()) {
        const NaryTree<T>* current = stack.pop();
        result->append(current->get_data());

        for (int i = 0; i < current->children_count(); ++i)
            stack.push(current->get_child(i));
    }

    return result;
}

template<class T>
Sequence<T> *NaryTree<T>::traverse_left_right_root() const {
    Sequence<T>* result = new LinkedListSequence<T>;

    if (children_count() == 0) {
        result->append(get_data());
        return result;
    }

    for (int i = 0; i < children_count(); ++i) {
        Sequence<T> *child_traverse = get_child(i)->traverse_left_right_root();
        Sequence<T>* concatenation = result->concat(child_traverse);
        delete result;
        delete child_traverse;
        result = concatenation;
    }
    result->append(get_data());

    return result;
}

template<class T>
Sequence<T> *NaryTree<T>::traverse_right_left_root() const {
    Sequence<T>* result = new LinkedListSequence<T>;

    if (children_count() == 0) {
        result->append(get_data());
        return result;
    }

    for (int i = children_count() - 1; i >= 0; --i) {
        Sequence<T> *child_traverse = get_child(i)->traverse_right_left_root();
        Sequence<T>* concatenation = result->concat(child_traverse);
        delete result;
        delete child_traverse;
        result = concatenation;
    }
    result->append(get_data());

    return result;
}

template<class T>
std::string NaryTree<T>::to_string() const {
    Sequence<T>* path = traverse();
    std::string result = path->to_string();
    delete path;
    return result;
}

template<class T>
std::string NaryTree<T>::to_string(NaryTree::TraverseType traverse_type) const {
    Sequence<T>* path = traverse(traverse_type);
    std::string result = path->to_string();
    delete path;
    return result;
}

template<class T>
NaryTree<T> *NaryTree<T>::map(T (*func)(T)) const {
    auto* result = new NaryTree<T>(*this);

    Stack<NaryTree<T>*> stack;
    stack.push(result);

    while (!stack.empty()) {
        NaryTree<T>* current = stack.pop();
        current->set_data(func(current->get_data()));

        for (int i = 0; i < current->children_count(); ++i)
            stack.push(current->get_child(i));
    }

    return result;
}

template<class T>
NaryTree<T> *NaryTree<T>::where(bool (*func)(T)) const {
    if (!func(get_data()))
        return nullptr;

    auto* result = new NaryTree<T>(*this);

    Stack<NaryTree<T>*> stack;
    stack.push(result);

    while (!stack.empty()) {
        NaryTree<T>* current = stack.pop();

        for (int i = 0; i < current->children_count(); ++i) {
            if (!func(current->get_child(i)->get_data())) {
                current->remove_child(i);
                --i;
                continue;
            }
            stack.push(current->get_child(i));
        }
    }

    return result;
}

template<class T>
int NaryTree<T>::count(T get_data) const {
    Sequence<T>* path = traverse();
    int result = 0;
    for (int i = 0; i < path->get_length(); ++i)
        result += (path->get(i) == get_data);
    delete path;
    return result;
}

template<class T>
bool NaryTree<T>::contains(const NaryTree<T> &subtree) const {
    if (subtree == *this)
        return true;

    for (int i = 0; i < children_count(); ++i)
        if (get_child(i)->contains(subtree))
            return true;

    return false;
}

template<class T>
NaryTree<T>& NaryTree<T>::operator[](int index) {
    return *(children->operator[](index));
}

    

#endif //LAB4_N_ARY_TREE_HPP