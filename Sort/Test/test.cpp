#include "pch.h"
#include "../Sort/Sort.cpp"
#include <vector>

// Тестовый случай для функции heapSort
TEST(HeapSortTest, EmptyArray) {
    // Проверяем, что функция heapSort корректно обрабатывает пустой массив
    // Ожидаем, что пустой массив останется пустым после сортировки
    std::vector<int> arr = {};
    std::vector<int> expected = {};
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, SingleElement) {
    // Проверяем, что функция heapSort корректно обрабатывает массив с одним элементом
    // Ожидаем, что массив с одним элементом останется неизменным
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, MultipleElements) {
    // Проверяем, что функция heapSort корректно сортирует массив с несколькими элементами
    // Входной массив содержит неупорядоченные элементы, ожидаем сортировку по возрастанию
    std::vector<int> arr = { 8, 34, 233, 21, 89, 13, 5, 2, 144, 3, 55, 1 };
    std::vector<int> expected = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233 };
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, RepeatedElements) {
    // Проверяем, что функция heapSort корректно обрабатывает массив с повторяющимися элементами
    // Ожидаем, что все элементы будут отсортированы по возрастанию, включая повторения
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    std::vector<int> expected = { 1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9 };
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, NegativeNumbers) {
    // Проверяем, что функция heapSort корректно сортирует массив с отрицательными числами
    // Ожидаем, что отрицательные и положительные числа будут отсортированы по возрастанию
    std::vector<int> arr = { -5, 10, -20, 0, 15, -10 };
    std::vector<int> expected = { -20, -10, -5, 0, 10, 15 };
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, AlreadySorted) {
    // Проверяем, что функция heapSort корректно обрабатывает уже отсортированный массив
    // Ожидаем, что массив останется неизменным, так как он уже отсортирован по возрастанию
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, ReverseSorted) {
    // Проверяем, что функция heapSort корректно сортирует массив, отсортированный по убыванию
    // Ожидаем, что массив будет переупорядочен по возрастанию
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}