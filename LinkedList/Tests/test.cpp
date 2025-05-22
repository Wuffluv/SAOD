#include "pch.h"
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/BST.h"


// Тест вставки и поиска
TEST(LinkedListTest, InsertAndSearch) {
    LinkedList<int> list;
    list.insert(5);
    list.insert(10);
    list.insert(15);

    auto node = list.search(10);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->data, 10);

    auto notFound = list.search(99);
    EXPECT_EQ(notFound, nullptr);
}

// Тест удаления элемента
TEST(LinkedListTest, RemoveElement) {
    LinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    list.remove(2);
    EXPECT_EQ(list.search(2), nullptr);

    auto node1 = list.search(1);
    ASSERT_NE(node1, nullptr);
    EXPECT_EQ(node1->data, 1);

    auto node3 = list.search(3);
    ASSERT_NE(node3, nullptr);
    EXPECT_EQ(node3->data, 3);
}

// Тест удаления головы
TEST(LinkedListTest, RemoveHead) {
    LinkedList<int> list;
    list.insert(1);
    list.insert(2);

    list.remove(1);
    EXPECT_EQ(list.search(1), nullptr);
    EXPECT_NE(list.search(2), nullptr);
}

// Тест удаления хвоста
TEST(LinkedListTest, RemoveTail) {
    LinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.remove(2);
    EXPECT_EQ(list.search(2), nullptr);
    EXPECT_NE(list.search(1), nullptr);
}

// Тест сортировки
TEST(LinkedListTest, SortList) {
    LinkedList<int> list;
    list.insert(3);
    list.insert(1);
    list.insert(2);

    list.sort();

    auto it = list.begin();
    EXPECT_EQ(*(*it), 1);
    ++(*it);
    EXPECT_EQ(*(*it), 2);
    ++(*it);
    EXPECT_EQ(*(*it), 3);
    delete it;
}

// Тест итератора begin/end
TEST(LinkedListTest, IteratorTraversal) {
    LinkedList<int> list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    auto it = list.begin();
    auto end = list.end();

    std::vector<int> values;
    for (; *it != *end; ++(*it)) {
        values.push_back(*(*it));
    }

    EXPECT_EQ(values.size(), 3);
    EXPECT_EQ(values[0], 10);
    EXPECT_EQ(values[1], 20);
    EXPECT_EQ(values[2], 30);

    delete it;
    delete end;
}

// Тест обхода BST через итератор
TEST(BSTIteratorTest, InOrderTraversal) {
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(7);

    auto it = tree.begin();
    auto end = tree.end();

    std::vector<int> result;
    while (*it != *end) {
        result.push_back(*(*it));
        ++(*it);
    }

    std::vector<int> expected = { 5, 7, 10, 15 };
    EXPECT_EQ(result, expected);

    delete it;
    delete end;
}

// Проверка префиксного инкремента
TEST(BSTIteratorTest, PrefixIncrement) {
    BST<int> tree;
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);

    auto it = tree.begin();
    EXPECT_EQ(*(*it), 1);
    ++(*it);
    EXPECT_EQ(*(*it), 2);
    ++(*it);
    EXPECT_EQ(*(*it), 3);

    delete it;
}


// Проверка равенства/неравенства итераторов
TEST(BSTIteratorTest, IteratorEquality) {
    BST<int> tree;
    tree.insert(1);
    tree.insert(2);

    auto it1 = tree.begin();
    auto it2 = tree.begin();
    auto end = tree.end();

    EXPECT_TRUE(*it1 == *it2);
    ++(*it1);
    EXPECT_TRUE(*it1 != *it2);
    ++(*it2);
    EXPECT_TRUE(*it1 == *it2);
    ++(*it1);
    EXPECT_TRUE(*it1 == *end);

    delete it1;
    delete it2;
    delete end;
}