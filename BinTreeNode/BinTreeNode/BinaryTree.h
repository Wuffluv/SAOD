#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>
#include <functional>

// ��������� ����� TreeNode ��� ������������� ���� ��������� ������
template <typename T>
class TreeNode {
public:
    T data;                  // ������, �������� � ����
    TreeNode* left;          // ��������� �� ����� �������� ����
    TreeNode* right;         // ��������� �� ������ �������� ����

    // ����������� ����
    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}

    // ���������� ��� ������������ ������
    ~TreeNode() {
        delete left;   // ���������� ������� ����� ���������
        delete right;  // ���������� ������� ������ ���������
    }
};

// ������� ��� ������ ������ 
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

// ������� ��� ��������� ����������� ����
template <typename T>
void printNodeData(TreeNode<T>* node) {
    if (node != nullptr) {
        std::cout << "���������� ����: " << node->data << std::endl;
    }
    else {
        std::cout << "���� ������" << std::endl;
    }
}

// NLR (Pre-order) ����� �������� �������
template <typename T>
void NLR_toVector(TreeNode<T>* node, std::vector<T>& result) {
    if (node == nullptr) return;
    result.push_back(node->data); // ������
    NLR_toVector(node->left, result); // ����� ���������
    NLR_toVector(node->right, result); // ������ ���������
}

// LNR (In-order) ����� �������� �������
template <typename T>
void LNR_toVector(TreeNode<T>* node, std::vector<T>& result) {
    if (node == nullptr) return;
    LNR_toVector(node->left, result); // ����� ���������
    result.push_back(node->data); // ������
    LNR_toVector(node->right, result); // ������ ���������
}

// LRN (Post-order) ����� �������� �������
template <typename T>
void LRN_toVector(TreeNode<T>* node, std::vector<T>& result) {
    if (node == nullptr) return;
    LRN_toVector(node->left, result); // ����� ���������
    LRN_toVector(node->right, result); // ������ ���������
    result.push_back(node->data); // ������
}

// NLR (Pre-order) ����� ����� 
template <typename T>
void NLR_print(TreeNode<T>* node) {
    if (node == nullptr) return;
    std::cout << node->data << " "; // ������
    NLR_print(node->left); // ����� ���������
    NLR_print(node->right); // ������ ���������
}

// LNR (In-order) ����� ����� 
template <typename T>
void LNR_print(TreeNode<T>* node) {
    if (node == nullptr) return;
    LNR_print(node->left); // ����� ���������
    std::cout << node->data << " "; // ������
    LNR_print(node->right); // ������ ���������
}

// LRN (Post-order) ����� ����� 
template <typename T>
void LRN_print(TreeNode<T>* node) {
    if (node == nullptr) return;
    LRN_print(node->left); // ����� ���������
    LRN_print(node->right); // ������ ���������
    std::cout << node->data << " "; // ������
}

// NLR (Pre-order) ����� ���������� 
template <typename T>
void NLR_apply(TreeNode<T>* node, std::function<void(T&)> func) {
    if (node == nullptr) return;
    func(node->data); // ������
    NLR_apply(node->left, func); // ����� ���������
    NLR_apply(node->right, func); // ������ ���������
}

// LNR (In-order) ����� ���������� 
template <typename T>
void LNR_apply(TreeNode<T>* node, std::function<void(T&)> func) {
    if (node == nullptr) return;
    LNR_apply(node->left, func); // ����� ���������
    func(node->data); // ������
    LNR_apply(node->right, func); // ������ ���������
}

// LRN (Post-order) ���� ���������� 
template <typename T>
void LRN_apply(TreeNode<T>* node, std::function<void(T&)> func) {
    if (node == nullptr) return;
    LRN_apply(node->left, func); // ����� ���������
    LRN_apply(node->right, func); // ������ ���������
    func(node->data); // ������
}

// ������� �������� ������ (�� ������ LRN)
template <typename T>
void deleteTree(TreeNode<T>*& node) {
    if (node == nullptr) return;
    deleteTree(node->left); // ����� ���������
    deleteTree(node->right); // ������ ���������
    delete node; // ������
    node = nullptr; // �������� ���������
}

// ������� �������� ����� (�� ������ NLR)
template <typename T>
int countNodes(TreeNode<T>* node) {
    if (node == nullptr) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

// ������� ����������� ������� ������ (�� ������ NLR)
template <typename T>
int treeDepth(TreeNode<T>* node) {
    if (node == nullptr) return 0;
    int leftDepth = treeDepth(node->left);
    int rightDepth = treeDepth(node->right);
    return 1 + std::max(leftDepth, rightDepth);
}

// ���������� ������� ��� �������� ������
TreeNode<int>* createSampleTree();

#endif 