#pragma once
#include <iostream>
#include <vector>
#include "Iterator.h"

using namespace std;

// Класс узла дерева
template <typename T>
class TreeNode {
public:
    T data;          // Данные, хранящиеся в узле
    TreeNode* left;  // Указатель на левого потомка
    TreeNode* right; // Указатель на правого потомка

    // Конструктор узла
    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// Класс бинарного дерева поиска (Binary Search Tree)
template <typename T>
class BST {
private:
    TreeNode<T>* root; // Корень дерева

    // Рекурсивная функция вставки значения в дерево
    TreeNode<T>* insertRec(TreeNode<T>* node, T value) {
        if (!node) return new TreeNode<T>(value); // Если достигли листа - создаем новый узел
        if (value < node->data)
            node->left = insertRec(node->left, value); // Идем в левое поддерево
        else if (value > node->data)
            node->right = insertRec(node->right, value); // Идем в правое поддерево
        return node; // Возвращаем текущий узел
    }

    // Рекурсивный обход дерева в порядке LNR (In-order)
    // Результат сохраняется в переданный вектор
    static void inOrder(TreeNode<T>* node, std::vector<T>& result) {
        if (!node) return; // Базовый случай рекурсии
        inOrder(node->left, result);  // Рекурсивно обходим левое поддерево
        result.push_back(node->data); // Добавляем текущий узел
        inOrder(node->right, result); // Рекурсивно обходим правое поддерево
    }

    // Рекурсивное удаление всех узлов дерева (пост-порядок)
    void deleteTree(TreeNode<T>* node) {
        if (!node) return;
        deleteTree(node->left);  // Удаляем левое поддерево
        deleteTree(node->right); // Удаляем правое поддерево
        delete node;             // Удаляем текущий узел
    }

public:
    // Конструктор по умолчанию (пустое дерево)
    BST() : root(nullptr) {}

    // Деструктор - освобождает память
    ~BST() {
        deleteTree(root);
    }

    // Публичный метод вставки значения в дерево
    void insert(T value) {
        root = insertRec(root, value);
    }

    // Вложенный класс итератора для BST
    class BSTIterator : public Iterator<T> {
    private:
        std::vector<T> elements; // Вектор для хранения элементов в порядке обхода
        size_t index;            // Текущая позиция итератора

    public:
        // Конструктор итератора - заполняет вектор элементами при создании
        BSTIterator(TreeNode<T>* root) : index(0) {
            BST<T>::inOrder(root, elements); // Используем in-order обход
        }

        // Перегрузка оператора разыменования
        T& operator*() override {
            return elements[index];
        }

        // Префиксный инкремент (++it)
        Iterator<T>& operator++() override {
            if (index < elements.size()) index++;
            return *this;
        }

        // Постфиксный инкремент (it++)
        Iterator<T>& operator++(int) override {
            BSTIterator* temp = new BSTIterator(*this);
            ++(*this);
            return *temp;
        }

        // Оператор сравнения итераторов
        bool operator==(const Iterator<T>& other) override {
            const BSTIterator* o = dynamic_cast<const BSTIterator*>(&other);
            return o && index == o->index;
        }

        // Оператор неравенства итераторов
        bool operator!=(const Iterator<T>& other) override {
            return !(*this == other);
        }

        friend class BST<T>; // Дружественный класс для доступа к приватным членам
    };

    // Метод для получения итератора на начало дерева
    Iterator<T>* begin() {
        return new BSTIterator(root);
    }

    // Метод для получения итератора на конец дерева (за последним элементом)
    Iterator<T>* end() {
        BSTIterator* it = new BSTIterator(root);
        it->index = it->elements.size(); // Устанавливаем индекс за последним элементом
        return it;
    }
};