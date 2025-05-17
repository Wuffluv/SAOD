#ifndef BST_H
#define BST_H

#include "BinaryTree.h"
#include <queue>
#include <list>
#include <vector>
#include <functional>

// ��������� ����� ��� ��������� ������ ������
template <typename T>
class BST {
private:
    TreeNode<T>* root; // ��������� �� ������ ������

    // ��������������� ������� ��� ����������� ������� ����
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

    // ��������������� ������� ��� ������������ ������ ����
    TreeNode<T>* searchRec(TreeNode<T>* node, T value) const {
        if (node == nullptr || node->data == value) {
            return node;
        }
        if (value < node->data) {
            return searchRec(node->left, value);
        }
        return searchRec(node->right, value);
    }

    // ��������������� ������� ��� ����������� ������
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
    // �����������
    BST() : root(nullptr) {}

    // ����������
    ~BST() {
        deleteTree(root);
    }

    // ������� ������ ��������
    void insert(T value) {
        root = insertRec(root, value);
    }

    // ����� ���� �� ��������
    TreeNode<T>* search(T value) const {
        return searchRec(root, value);
    }

    // ����������� ������
    BST<T> copy() const {
        BST<T> newTree;
        newTree.root = copyRec(root);
        return newTree;
    }

    // ����� � ������ (BFS)
    std::vector<T> levelOrder() const {
        std::vector<T> result;
        if (root == nullptr) {
            return result;
        }
        std::queue<TreeNode<T>*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode<T>* node = q.front();
            q.pop();
            result.push_back(node->data);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return result;
    }

    // ��������� ����� 
    TreeNode<T>* getRoot() const {
        return root;
    }
};

#endif // BST_H