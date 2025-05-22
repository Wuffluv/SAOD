#ifndef BST_H
#define BST_H

#include "BinaryTree.h"
#include <queue>
#include <list>
#include <vector>
#include <functional>

// Шаблонный класс для BST
template <typename T>
class BST {
private:
    TreeNode<T>* root; // Указатель на корень дерева

    //функция для рекурсивной вставки узла
    TreeNode<T>* insertRec(TreeNode<T>* node, T value) {
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    //функция для рекурсивного поиска узла
    TreeNode<T>* searchRec(TreeNode<T>* node, T value) const {
        if (node == nullptr || node->data == value) {
            return node;
        }
        if (value < node->data) {
            return searchRec(node->left, value);
        }
        return searchRec(node->right, value);
    }
    

    //функция для копирования дерева
    TreeNode<T>* copyRec(TreeNode<T>* node) const {
        if (node == nullptr) {
            return nullptr;
        }
        TreeNode<T>* newNode = new TreeNode<T>(node->data);
        newNode->left = copyRec(node->left);
        newNode->right = copyRec(node->right);
        return newNode;
    }

public:
    // Конструктор
    BST() : root(nullptr) {}

    // Деструктор
    ~BST() {
        deleteTree(root);
    }

    // Вставка нового значения
    void insert(T value) {
        root = insertRec(root, value);
    }

    // Поиск узла по значению
    TreeNode<T>* search(T value) const {
        return searchRec(root, value);
    }

    // Копирование дерева
    BST<T> copy() const {
        BST<T> newTree;
        newTree.root = copyRec(root);
        return newTree;
    }

    // Обход в ширину (BFS)
    std::vector<T> levelOrder() const {
        std::vector<T> result;
        if (root == nullptr) {
            return result;
        }
        std::queue<TreeNode<T>*> q;
        q.push(root);
        while (!q.empty()) {//empty – проверка дерева на пустоту,
            TreeNode<T>* node = q.front();//front()- Возвращает ссылку на первый элемент в очереди
            //(элемент, который находится в начале очереди и будет удален следующим)
            q.pop();//pop() - Удаляет первый элемент из очереди 
            //(тот, который был бы возвращен методом front())
            result.push_back(node->data);//push_back Добавляет эоемент в конец вектора
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return result;
    }

    // Получение корня 
    TreeNode<T>* getRoot() const {
        return root;
    }


};

#endif // BST_H