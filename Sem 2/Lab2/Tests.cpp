#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Sequences/Sequences.hpp"

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


