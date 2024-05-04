#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Sequences/Sequences.hpp"
#include "Stack.hpp"
#include "Deque.hpp"
#include "nary_tree.hpp"

TEST_CASE("ArraySequence tests") {
    ArraySequence<int> arrSeq;

    CHECK(arrSeq.get_length() == 0);

    arrSeq.append(1);
    arrSeq.append(2);
    arrSeq.append(3);

    CHECK(arrSeq.get_length() == 3);
    CHECK(arrSeq.get_first() == 1);
    CHECK(arrSeq.get_last() == 3);
    
    CHECK(arrSeq.get(1) == 2);

    arrSeq.prepend(0);
    CHECK(arrSeq.get_length() == 4);
    CHECK(arrSeq.get_first() == 0);

    arrSeq.insert(2, 1);
    CHECK(arrSeq.get_length() == 5);
    CHECK(arrSeq.get(2) == 1);

    ArraySequence<int>* subSeq = dynamic_cast<ArraySequence<int>*>(arrSeq.get_subsequence(1, 3));
    CHECK(subSeq != nullptr);
    CHECK(subSeq->get_length() == 3);
    CHECK(subSeq->get_first() == 1);
    CHECK(subSeq->get_last() == 2);

    delete subSeq;

    ArraySequence<int>* concatSeq = dynamic_cast<ArraySequence<int>*>(arrSeq.concat(&arrSeq));
    CHECK(concatSeq != nullptr);
    CHECK(concatSeq->get_length() == arrSeq.get_length() * 2);

    delete concatSeq;

    arrSeq.remove(2);
    CHECK(arrSeq.get_length() == 4);
    CHECK(arrSeq.get(2) == 2);

    arrSeq.clear();
    CHECK(arrSeq.get_length() == 0);
}

TEST_CASE("LinkedListSequence tests") {
    LinkedListSequence<int> linkedSeq;

    CHECK(linkedSeq.get_length() == 0);

    linkedSeq.append(1);
    linkedSeq.append(2);
    linkedSeq.append(3);

    CHECK(linkedSeq.get_length() == 3);
    CHECK(linkedSeq.get_first() == 1);
    CHECK(linkedSeq.get_last() == 3);
    CHECK(linkedSeq.get(1) == 2);

    linkedSeq.prepend(0);
    CHECK(linkedSeq.get_length() == 4);
    CHECK(linkedSeq.get_first() == 0);

    linkedSeq.insert(2, 1);
    CHECK(linkedSeq.get_length() == 5);
    CHECK(linkedSeq.get(2) == 1);

    LinkedListSequence<int>* subSeq = dynamic_cast<LinkedListSequence<int>*>(linkedSeq.get_subsequence(1, 3));
    CHECK(subSeq != nullptr);
    CHECK(subSeq->get_length() == 3);
    CHECK(subSeq->get_first() == 1);
    CHECK(subSeq->get_last() == 2);

    delete subSeq;

    LinkedListSequence<int>* concatSeq = dynamic_cast<LinkedListSequence<int>*>(linkedSeq.concat(&linkedSeq));
    CHECK(concatSeq != nullptr);
    CHECK(concatSeq->get_length() == linkedSeq.get_length() * 2);

    delete concatSeq;

    linkedSeq.remove(2);
    CHECK(linkedSeq.get_length() == 4);
    CHECK(linkedSeq.get(2) == 2);

    linkedSeq.clear();
    CHECK(linkedSeq.get_length() == 0);
}


TEST_CASE("ArraySequence::get with empty sequence") {
    ArraySequence<int> arrSeq;
    CHECK_THROWS_AS(arrSeq.get(0), std::out_of_range);
}

TEST_CASE("ArraySequence::get with invalid index") {
    ArraySequence<int> arrSeq;
    arrSeq.append(1);
    CHECK_THROWS_AS(arrSeq.get(-1), std::out_of_range);
    CHECK_THROWS_AS(arrSeq.get(1), std::out_of_range);
}

TEST_CASE("ArraySequence::remove with empty sequence") {
    ArraySequence<int> arrSeq;
    CHECK_THROWS_AS(arrSeq.remove(0), std::out_of_range);
}

TEST_CASE("ArraySequence::remove with invalid index") {
    ArraySequence<int> arrSeq;
    arrSeq.append(1);
    CHECK_THROWS_AS(arrSeq.remove(-1), std::out_of_range);
    CHECK_THROWS_AS(arrSeq.remove(1), std::out_of_range);
}


TEST_CASE("LinkedListSequence::get with empty sequence") {
    LinkedListSequence<int> linkedSeq;
    CHECK_THROWS_AS(linkedSeq.get(0), std::out_of_range);
}

TEST_CASE("LinkedListSequence::get with invalid index") {
    LinkedListSequence<int> linkedSeq;
    linkedSeq.append(1);
    CHECK_THROWS_AS(linkedSeq.get(-1), std::out_of_range);
    CHECK_THROWS_AS(linkedSeq.get(1), std::out_of_range);
}

TEST_CASE("LinkedListSequence::remove with empty sequence") {
    LinkedListSequence<int> linkedSeq;
    CHECK_THROWS_AS(linkedSeq.remove(0), std::out_of_range);
}

TEST_CASE("LinkedListSequence::remove with invalid index") {
    LinkedListSequence<int> linkedSeq;
    linkedSeq.append(1);
    CHECK_THROWS_AS(linkedSeq.remove(-1), std::out_of_range);
    CHECK_THROWS_AS(linkedSeq.remove(1), std::out_of_range);
}

TEST_CASE("ArraySequence::append multiple items") {
    ArraySequence<int> arrSeq;
    for (int i = 0; i < 10; i++) {
        arrSeq.append(i);
        CHECK(arrSeq.get_length() == i + 1);
        CHECK(arrSeq.get_last() == i);
    }
}

TEST_CASE("ArraySequence::prepend multiple items") {
    ArraySequence<int> arrSeq;
    for (int i = 0; i < 10; i++) {
        arrSeq.prepend(i);
        CHECK(arrSeq.get_length() == i + 1);
        CHECK(arrSeq.get_first() == i);
    }
}

TEST_CASE("ArraySequence::insert at different positions") {
    ArraySequence<int> arrSeq;
    for (int i = 0; i < 10; i++) {
        arrSeq.insert(i, i);
        CHECK(arrSeq.get_length() == i + 1);
        CHECK(arrSeq.get(i) == i);
    }
}


TEST_CASE("LinkedListSequence::append multiple items") {
    LinkedListSequence<int> linkedSeq;
    for (int i = 0; i < 10; i++) {
        linkedSeq.append(i);
        CHECK(linkedSeq.get_length() == i + 1);
        CHECK(linkedSeq.get_last() == i);
    }
}

TEST_CASE("LinkedListSequence::prepend multiple items") {
    LinkedListSequence<int> linkedSeq;
    for (int i = 0; i < 10; i++) {
        linkedSeq.prepend(i);
        CHECK(linkedSeq.get_length() == i + 1);
        CHECK(linkedSeq.get_first() == i);
    }
}

TEST_CASE("LinkedListSequence::insert at different positions") {
    LinkedListSequence<int> linkedSeq;
    for (int i = 0; i < 10; i++) {
        linkedSeq.insert(i, i);
        CHECK(linkedSeq.get_length() == i + 1);
        CHECK(linkedSeq.get(i) == i);
    }
}



TEST_CASE("ArraySequence::out_of_range") {
    ArraySequence<int> arrSeq;
    for (int i = 0; i < 10; i++) {
        arrSeq.append(i);
    }
    CHECK_THROWS(arrSeq.get(-1));
    CHECK_THROWS(arrSeq.get(10));
}

TEST_CASE("ArraySequence::set") {
    ArraySequence<int> arrSeq;
    for (int i = 0; i < 10; i++) {
        arrSeq.append(i);
    }
    arrSeq.set(5, 100);
    CHECK(arrSeq.get(5) == 100);
}


TEST_CASE("LinkedListSequence::out_of_range") {
    LinkedListSequence<int> linkedSeq;
    for (int i = 0; i < 10; i++) {
        linkedSeq.append(i);
    }
    CHECK_THROWS(linkedSeq.get(-1));
    CHECK_THROWS(linkedSeq.get(10));
}

TEST_CASE("LinkedListSequence::set") {
    LinkedListSequence<int> linkedSeq;
    for (int i = 0; i < 10; i++) {
        linkedSeq.append(i);
    }
    linkedSeq.set(5, 100);
    CHECK(linkedSeq.get(5) == 100);
}

TEST_CASE("Testing the Stack class") {
    Stack<int> stack;

    SUBCASE("Testing push and top methods") {
        stack.push(1);
        CHECK(stack.top() == 1);
        stack.push(2);
        CHECK(stack.top() == 2);
    }

    SUBCASE("Testing pop method") {
        stack.push(1);
        stack.push(2);
        stack.pop();
        CHECK(stack.top() == 1);
    }

    SUBCASE("Testing get_length method") {
        stack.push(1);
        stack.push(2);
        CHECK(stack.get_length() == 2);
    }
}

TEST_CASE("Testing the Deque class") {
    Deque<int> deque;

    SUBCASE("Testing push_front and front methods") {
        deque.push_front(1);
        CHECK(deque.front() == 1);
        deque.push_front(2);
        CHECK(deque.front() == 2);
    }

    SUBCASE("Testing push_back and back methods") {
        deque.push_back(1);
        CHECK(deque.back() == 1);
        deque.push_back(2);
        CHECK(deque.back() == 2);
    }

    SUBCASE("Testing pop_front method") {
        deque.push_front(1);
        deque.push_front(2);
        deque.pop_front();
        CHECK(deque.front() == 1);
    }

    SUBCASE("Testing pop_back method") {
        deque.push_back(1);
        deque.push_back(2);
        deque.pop_back();
        CHECK(deque.back() == 1);
    }

    SUBCASE("Testing get_length method") {
        deque.push_front(1);
        deque.push_back(2);
        CHECK(deque.get_length() == 2);
    }
}

TEST_CASE("Testing the Stack class") {
    Stack<int> stack;

    // ... (previous tests)

    SUBCASE("Testing top method on an empty stack") {
        CHECK_THROWS_AS(stack.top(), std::logic_error);
    }

    SUBCASE("Testing pop method on an empty stack") {
        CHECK_THROWS_AS(stack.pop(), std::logic_error);
    }

    SUBCASE("Testing get_length on an empty stack") {
        CHECK(stack.get_length() == 0);
    }

    SUBCASE("Testing push, pop, and get_length methods") {
        stack.push(1);
        stack.push(2);
        stack.pop();
        CHECK(stack.get_length() == 1);
        stack.pop();
        CHECK(stack.get_length() == 0);
    }
}

TEST_CASE("Testing the Deque class") {
    Deque<int> deque;

    // ... (previous tests)

    SUBCASE("Testing front method on an empty deque") {
        CHECK_THROWS_AS(deque.front(), std::logic_error);
    }

    SUBCASE("Testing back method on an empty deque") {
        CHECK_THROWS_AS(deque.back(), std::logic_error);
    }

    SUBCASE("Testing pop_front method on an empty deque") {
        CHECK_THROWS_AS(deque.pop_front(), std::logic_error);
    }

    SUBCASE("Testing pop_back method on an empty deque") {
        CHECK_THROWS_AS(deque.pop_back(), std::logic_error);
    }

    SUBCASE("Testing get_length on an empty deque") {
        CHECK(deque.get_length() == 0);
    }

    SUBCASE("Testing push_front, push_back, pop_front, pop_back, and get_length methods") {
        deque.push_front(1);
        deque.push_back(2);
        deque.pop_front();
        CHECK(deque.get_length() == 1);
        deque.pop_back();
        CHECK(deque.get_length() == 0);
    }
}



TEST_CASE("NaryTree constructor") {
    NaryTree<int> tree(1, 3);
    CHECK(tree.get_data() == 1);
    CHECK(tree.max_children_count() == 3);
    CHECK(tree.children_count() == 0);
    CHECK(tree.size() == 1);
    CHECK(tree.height() == 1);
}


TEST_CASE("NaryTree add_child") {
    NaryTree<int> tree(1, 2);
    tree.add_child(2);
    tree.add_child(3);
    CHECK(tree.children_count() == 2);
    CHECK(tree[0].get_data() == 2);
    CHECK(tree[1].get_data() == 3);
}


TEST_CASE("NaryTree get_subtree") {
    NaryTree<int> tree(1, 2);
    tree.add_child(2);
    tree.add_child(3);
    CHECK(tree[0].get_data() == 2);
    CHECK(tree[1].get_data() == 3);
}


TEST_CASE("NaryTree delete_subtree") {
    NaryTree<int> tree(1, 2);
    tree.add_child(2);
    tree.add_child(3);
    tree.remove_child(0);
    CHECK(tree.children_count() == 1);
    CHECK(tree[0].get_data() == 3);
}


TEST_CASE("NaryTree operator[]") {
    NaryTree<int> tree(1, 2);
    tree.add_child(2);
    tree.add_child(3);
    CHECK(tree[0].get_data() == 2);
    CHECK(tree[1].get_data() == 3);
}


TEST_CASE("NaryTree operator==") {
    NaryTree<int> tree1(1, 2);
    tree1.add_child(2);
    tree1.add_child(3);

    NaryTree<int> tree2(1, 2);
    tree2.add_child(2);
    tree2.add_child(3);

    CHECK(tree1 == tree2);
}


TEST_CASE("NaryTree operator!=") {
    NaryTree<int> tree1(1, 2);
    tree1.add_child(2);
    tree1.add_child(3);

    NaryTree<int> tree2(1, 2);
    tree2.add_child(2);
    tree2.add_child(4);

    CHECK(tree1 != tree2);
}




TEST_CASE("NaryTree size") {
    NaryTree<int> tree(1, 3);
    tree.add_child(2);
    tree.add_child(3);
    tree.add_child(4);

    CHECK(tree.size() == 4);
}


TEST_CASE("NaryTree height") {
    NaryTree<int> tree(1, 3);
    tree.add_child(2);
    tree.add_child(3);
    tree.add_child(4);
    tree[0].add_child(5);

    CHECK(tree.height() == 3);
}






TEST_CASE("NaryTree - size") {
    NaryTree<int> tree(1);
    CHECK(tree.size() == 1);

    tree.add_child(2);
    CHECK(tree.size() == 2);

    NaryTree<int> child(3);
    tree.add_child(&child);
    CHECK(tree.size() == 3);

    NaryTree<int> grandchild(4);
    child.add_child(&grandchild);
    CHECK(tree.size() == 3);
}

TEST_CASE("NaryTree - traverse") {
    NaryTree<int> tree(1);
    tree.add_child(2);
    tree.add_child(3);
    tree.add_child(4);
    tree.add_child(5);

    SUBCASE("TraverseType::ROOT_LEFT_RIGHT") {
        Sequence<int>* result = tree.traverse(NaryTree<int>::ROOT_LEFT_RIGHT);
        CHECK(result->to_string() == "[1, 2, 3, 4, 5]");
        delete result;
    }

    SUBCASE("TraverseType::ROOT_RIGHT_LEFT") {
        Sequence<int>* result = tree.traverse(NaryTree<int>::ROOT_RIGHT_LEFT);
        CHECK(result->to_string() == "[1, 5, 4, 3, 2]");
        delete result;
    }

    SUBCASE("TraverseType::LEFT_RIGHT_ROOT") {
        Sequence<int>* result = tree.traverse(NaryTree<int>::LEFT_RIGHT_ROOT);
        CHECK(result->to_string() == "[2, 3, 4, 5, 1]");
        delete result;
    }

    SUBCASE("TraverseType::RIGHT_LEFT_ROOT") {
        Sequence<int>* result = tree.traverse(NaryTree<int>::RIGHT_LEFT_ROOT);
        CHECK(result->to_string() == "[5, 4, 3, 2, 1]");
        delete result;
    }
}

TEST_CASE("NaryTree - map") {
    NaryTree<int> tree(1);
    tree.add_child(2);
    tree.add_child(3);
    tree.add_child(4);
    tree.add_child(5);

    auto increment = [](int value) { return value + 1; };

    NaryTree<int>* mapped = tree.map(increment);

    Sequence<int>* result = mapped->traverse(NaryTree<int>::ROOT_LEFT_RIGHT);
    CHECK(result->to_string() == "[2, 3, 4, 5, 6]");
    delete result;

    delete mapped;
}

TEST_CASE("NaryTree - where") {
    // Create a sample tree
    NaryTree<int> tree(1);
    tree.add_child(2);
    tree.add_child(3);
    tree.add_child(4);
    tree.add_child(5);
    tree.get_child(0)->add_child(6);
    tree.get_child(1)->add_child(7);
    tree.get_child(2)->add_child(8);
    tree.get_child(3)->add_child(9);

    // Create a predicate function that filters odd numbers
    auto isOdd = [](int value) { return value % 2 != 0; };

    // Apply the where method to filter the tree
    NaryTree<int>* filtered = tree.where(isOdd);

    // Check the filtered tree
    CHECK(filtered->get_data() == 1);
    CHECK(filtered->children_count() == 2);
    CHECK(filtered->get_child(0)->get_data() == 3);
    CHECK(filtered->get_child(1)->get_data() == 5);
    CHECK(filtered->get_child(0)->children_count() == 1);
    CHECK(filtered->get_child(1)->children_count() == 1);
    CHECK(filtered->get_child(1)->get_child(0)->get_data() == 9);

    delete filtered;
}


TEST_CASE("NaryTree - count") {
    NaryTree<int> tree(1);
    tree.add_child(2);
    tree.add_child(3);
    tree.add_child(2);
    tree.add_child(4);
    tree.add_child(2);

    CHECK(tree.count(2) == 3);
    CHECK(tree.count(1) == 1);
    CHECK(tree.count(3) == 1);
    CHECK(tree.count(4) == 1);
    CHECK(tree.count(5) == 0);
}



TEST_CASE("NaryTree - remove") {
    NaryTree<int> tree(1);
    tree.add_child(2);
    tree.add_child(3);
    tree.add_child(4);
    tree.add_child(5);

    tree.remove_child(3);

    Sequence<int>* result = tree.traverse(NaryTree<int>::ROOT_LEFT_RIGHT);
    CHECK(result->to_string() == "[1, 2, 3, 4]");
    delete result;
}





TEST_CASE("NaryTree - size") {
    NaryTree<int> tree(1);
    tree.add_child(2);
    tree.get_child(0)->add_child(3);
    tree.get_child(0)->add_child(4);
    tree.add_child(5);

    CHECK(tree.size() == 5);
    CHECK(tree.get_child(0)->size() == 3);
}

TEST_CASE("NaryTree - height") {
    NaryTree<int> tree(1);
    tree.add_child(2);
    tree.get_child(0)->add_child(3);
    tree.get_child(0)->add_child(4);
    tree.add_child(5);

    CHECK(tree.height() == 3);
    CHECK(tree.get_child(0)->height() == 2);
}

TEST_CASE("NaryTree - map") {
    NaryTree<int> tree(1);
    tree.add_child(2);
    tree.get_child(0)->add_child(3);
    tree.get_child(0)->add_child(4);
    tree.add_child(5);

    auto increment = [](int value) { return value + 1; };

    NaryTree<int>* mapped = tree.map(increment);

    Sequence<int>* result = mapped->traverse(NaryTree<int>::ROOT_LEFT_RIGHT);
    CHECK(result->to_string() == "[2, 3, 4, 5, 6]");
    delete result;

    delete mapped;
}

TEST_CASE("NaryTree - count") {
    NaryTree<int> tree(1);
    tree.add_child(2);
    tree.get_child(0)->add_child(3);
    tree.get_child(0)->add_child(4);
    tree.add_child(2);

    CHECK(tree.count(2) == 2);
    CHECK(tree.count(3) == 1);
    CHECK(tree.count(5) == 0);
}


