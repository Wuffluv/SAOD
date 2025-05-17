#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>
#include <functional>

// Шаблонный класс TreeNode для представления узла бинарного дерева
template <typename T>
class TreeNode {
public:
    T data;                  // Данные, хранимые в узле
    TreeNode* left;          // Указатель на левый дочерний узел
    TreeNode* right;         // Указатель на правый дочерний узел

    // Конструктор узла
    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}

    // Деструктор для освобождения памяти
    ~TreeNode() {
        delete left;   // Рекурсивно удаляем левое поддерево
        delete right;  // Рекурсивно удаляем правое поддерево
    }
};

// Функция для вывода дерева 
template <typename T>
void printTree(TreeNode<T>* node, int level = 0) {
    if (node == nullptr) {
        return;
    }
    printTree(node->right, level + 1);
    for (int i = 0; i < level; i++) {
        std::cout << "   ";
    }
    std::cout << node->data << std::endl;
    printTree(node->left, level + 1);
}

// Функция для просмотра содержимого узла
template <typename T>
void printNodeData(TreeNode<T>* node) {
    if (node != nullptr) {
        std::cout << "Содержимое узла: " << node->data << std::endl;
    }
    else {
        std::cout << "Узел пустой" << std::endl;
    }
}

// NLR (Pre-order) обход создание массива
template <typename T>
void NLR_toVector(TreeNode<T>* node, std::vector<T>& result) {
    if (node == nullptr) return;
    result.push_back(node->data); // Корень
    NLR_toVector(node->left, result); // Левое поддерево
    NLR_toVector(node->right, result); // Правое поддерево
}

// LNR (In-order) обход создание массива
template <typename T>
void LNR_toVector(TreeNode<T>* node, std::vector<T>& result) {
    if (node == nullptr) return;
    LNR_toVector(node->left, result); // Левое поддерево
    result.push_back(node->data); // Корень
    LNR_toVector(node->right, result); // Правое поддерево
}

// LRN (Post-order) обход создание массива
template <typename T>
void LRN_toVector(TreeNode<T>* node, std::vector<T>& result) {
    if (node == nullptr) return;
    LRN_toVector(node->left, result); // Левое поддерево
    LRN_toVector(node->right, result); // Правое поддерево
    result.push_back(node->data); // Корень
}

// NLR (Pre-order) обход вывод 
template <typename T>
void NLR_print(TreeNode<T>* node) {
    if (node == nullptr) return;
    std::cout << node->data << " "; // Корень
    NLR_print(node->left); // Левое поддерево
    NLR_print(node->right); // Правое поддерево
}

// LNR (In-order) обход вывод 
template <typename T>
void LNR_print(TreeNode<T>* node) {
    if (node == nullptr) return;
    LNR_print(node->left); // Левое поддерево
    std::cout << node->data << " "; // Корень
    LNR_print(node->right); // Правое поддерево
}

// LRN (Post-order) обход вывод 
template <typename T>
void LRN_print(TreeNode<T>* node) {
    if (node == nullptr) return;
    LRN_print(node->left); // Левое поддерево
    LRN_print(node->right); // Правое поддерево
    std::cout << node->data << " "; // Корень
}

// NLR (Pre-order) обход применение 
template <typename T>
void NLR_apply(TreeNode<T>* node, std::function<void(T&)> func) {
    if (node == nullptr) return;
    func(node->data); // Корень
    NLR_apply(node->left, func); // Левое поддерево
    NLR_apply(node->right, func); // Правое поддерево
}

// LNR (In-order) обход применение 
template <typename T>
void LNR_apply(TreeNode<T>* node, std::function<void(T&)> func) {
    if (node == nullptr) return;
    LNR_apply(node->left, func); // Левое поддерево
    func(node->data); // Корень
    LNR_apply(node->right, func); // Правое поддерево
}

// LRN (Post-order) обхо применение 
template <typename T>
void LRN_apply(TreeNode<T>* node, std::function<void(T&)> func) {
    if (node == nullptr) return;
    LRN_apply(node->left, func); // Левое поддерево
    LRN_apply(node->right, func); // Правое поддерево
    func(node->data); // Корень
}

// Функция удаления дерева (на основе LRN)
template <typename T>
void deleteTree(TreeNode<T>*& node) {
    if (node == nullptr) return;
    deleteTree(node->left); // Левое поддерево
    deleteTree(node->right); // Правое поддерево
    delete node; // Корень
    node = nullptr; // Обнуляем указатель
}

// Функция подсчёта узлов (на основе NLR)
template <typename T>
int countNodes(TreeNode<T>* node) {
    if (node == nullptr) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

// Функция определения глубины дерева (на основе NLR)
template <typename T>
int treeDepth(TreeNode<T>* node) {
    if (node == nullptr) return 0;
    int leftDepth = treeDepth(node->left);
    int rightDepth = treeDepth(node->right);
    return 1 + std::max(leftDepth, rightDepth);
}

// Объявление функции для создания дерева
TreeNode<int>* createSampleTree();

#endif 