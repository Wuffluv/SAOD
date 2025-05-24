#include "pch.h"
#include "../Sort/Sort.cpp"
#include <vector>

// �������� ������ ��� ������� heapSort
TEST(HeapSortTest, EmptyArray) {
    // ���������, ��� ������� heapSort ��������� ������������ ������ ������
    // �������, ��� ������ ������ ��������� ������ ����� ����������
    std::vector<int> arr = {};
    std::vector<int> expected = {};
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, SingleElement) {
    // ���������, ��� ������� heapSort ��������� ������������ ������ � ����� ���������
    // �������, ��� ������ � ����� ��������� ��������� ����������
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, MultipleElements) {
    // ���������, ��� ������� heapSort ��������� ��������� ������ � ����������� ����������
    // ������� ������ �������� ��������������� ��������, ������� ���������� �� �����������
    std::vector<int> arr = { 8, 34, 233, 21, 89, 13, 5, 2, 144, 3, 55, 1 };
    std::vector<int> expected = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233 };
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, RepeatedElements) {
    // ���������, ��� ������� heapSort ��������� ������������ ������ � �������������� ����������
    // �������, ��� ��� �������� ����� ������������� �� �����������, ������� ����������
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    std::vector<int> expected = { 1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9 };
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, NegativeNumbers) {
    // ���������, ��� ������� heapSort ��������� ��������� ������ � �������������� �������
    // �������, ��� ������������� � ������������� ����� ����� ������������� �� �����������
    std::vector<int> arr = { -5, 10, -20, 0, 15, -10 };
    std::vector<int> expected = { -20, -10, -5, 0, 10, 15 };
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, AlreadySorted) {
    // ���������, ��� ������� heapSort ��������� ������������ ��� ��������������� ������
    // �������, ��� ������ ��������� ����������, ��� ��� �� ��� ������������ �� �����������
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, ReverseSorted) {
    // ���������, ��� ������� heapSort ��������� ��������� ������, ��������������� �� ��������
    // �������, ��� ������ ����� �������������� �� �����������
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    heapSort(arr);
    EXPECT_EQ(arr, expected);
}