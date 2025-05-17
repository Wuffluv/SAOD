#pragma once
#include <iostream>
#include <vector>
#include "Iterator.h"

using namespace std;

// Класс узла дерева
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// Класс бинарного дерева поиска
template <typename T>
class BST {
private:
    TreeNode<T>* root;

    // Рекурсивная вставка
    TreeNode<T>* insertRec(TreeNode<T>* node, T value) {
        if (!node) return new TreeNode<T>(value);
        if (value < node->data)
            node->left = insertRec(node->left, value);
        else if (value > node->data)
            node->right = insertRec(node->right, value);
        return node;
    }

    // Статический рекурсивный обход (LNR)
    static void inOrder(TreeNode<T>* node, std::vector<T>& result) {
        if (!node) return;
        inOrder(node->left, result);
        result.push_back(node->data);
        inOrder(node->right, result);
    }

    // Удаление дерева
    void deleteTree(TreeNode<T>* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        deleteTree(root);
    }

    // Вставка значения
    void insert(T value) {
        root = insertRec(root, value);
    }

    // ===== Итератор дерева =====
    class BSTIterator : public Iterator<T> {
    private:
        std::vector<T> elements; // Список всех элементов
        size_t index;            // Текущая позиция

    public:
        BSTIterator(TreeNode<T>* root) : index(0) {
            BST<T>::inOrder(root, elements); // заполняем вектор при создании
        }

        T& operator*() override {
            return elements[index];
        }

        Iterator<T>& operator++() override {
            if (index < elements.size()) index++;
            return *this;
        }

        Iterator<T>& operator++(int) override {
            BSTIterator* temp = new BSTIterator(*this);
            ++(*this);
            return *temp;
        }

        bool operator==(const Iterator<T>& other) override {
            const BSTIterator* o = dynamic_cast<const BSTIterator*>(&other);
            return o && index == o->index;
        }

        bool operator!=(const Iterator<T>& other) override {
            return !(*this == other);
        }

        friend class BST<T>;
    };

    Iterator<T>* begin() {
        return new BSTIterator(root);
    }

    Iterator<T>* end() {
        BSTIterator* it = new BSTIterator(root);
        it->index = it->elements.size();
        return it;
    }
};