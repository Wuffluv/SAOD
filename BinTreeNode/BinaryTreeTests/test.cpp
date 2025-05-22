#include "pch.h"
#include <gtest/gtest.h>
#include "../BinTreeNode/BST.h"

TreeNode<int>* createSampleTreeUsingBinaryTree() {
    TreeNode<int>* root = nullptr;
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    return root;
}

BST<int> createSampleBST() {
    BST<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);
    return bst;
}

class BinaryTreeTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// ���� 1: �������� �������� ����
TEST_F(BinaryTreeTest, NodeCreation) {
    TreeNode<int> node(10);
    EXPECT_EQ(node.data, 10);
    EXPECT_EQ(node.left, nullptr);
    EXPECT_EQ(node.right, nullptr);
}

// ���� 2: �������� ������� ����� (���������� insert �� BinaryTree.h)
TEST_F(BinaryTreeTest, InsertNodes) {
    TreeNode<int>* root = nullptr;
    insert(root, 5);
    EXPECT_NE(root, nullptr);
    EXPECT_EQ(root->data, 5);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);

    insert(root, 3);
    EXPECT_NE(root->left, nullptr);
    EXPECT_EQ(root->left->data, 3);
    EXPECT_EQ(root->left->left, nullptr);
    EXPECT_EQ(root->left->right, nullptr);

    insert(root, 7);
    EXPECT_NE(root->right, nullptr);
    EXPECT_EQ(root->right->data, 7);
    EXPECT_EQ(root->right->left, nullptr);
    EXPECT_EQ(root->right->right, nullptr);

    insert(root, 3);
    EXPECT_EQ(root->left->data, 3);

    deleteTree(root);
}

// ���� 3: �������� ������ �����
TEST_F(BinaryTreeTest, SearchTree) {
    TreeNode<int>* root = createSampleTreeUsingBinaryTree();
    TreeNode<int>* found = searchTree(root, 4);
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->data, 4);

    found = searchTree(root, 5);
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->data, 5);

    found = searchTree(root, 1);
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->data, 1);

    found = searchTree(root, 10);
    EXPECT_EQ(found, nullptr);

    deleteTree(root);
    found = searchTree(root, 5);
    EXPECT_EQ(found, nullptr);
}

// ���� 4: �������� �������� �����
TEST_F(BinaryTreeTest, CountNodes) {
    TreeNode<int>* root = createSampleTreeUsingBinaryTree();
    EXPECT_EQ(countNodes(root), 7);
    EXPECT_EQ(countNodes(root->left), 3);
    EXPECT_EQ(countNodes(root->right), 3);

    deleteTree(root);
    EXPECT_EQ(countNodes(root), 0);
}

// ���� 5: �������� ����������� ������� ������
TEST_F(BinaryTreeTest, TreeDepth) {
    TreeNode<int>* root = createSampleTreeUsingBinaryTree();
    EXPECT_EQ(treeDepth(root), 2);
    EXPECT_EQ(treeDepth(root->left), 1);
    EXPECT_EQ(treeDepth(root->right), 1);

    deleteTree(root);
    EXPECT_EQ(treeDepth(root), -1);
}

// ���� 6: �������� �������� ������
TEST_F(BinaryTreeTest, DeleteTree) {
    TreeNode<int>* root = createSampleTreeUsingBinaryTree();
    EXPECT_NE(root, nullptr);
    deleteTree(root);
    EXPECT_EQ(root, nullptr);
}

// ���� 7: �������� ������ ������ ����
TEST_F(BinaryTreeTest, PrintNodeData) {
    TreeNode<int>* node = new TreeNode<int>(42);
    testing::internal::CaptureStdout();
    printNodeData(node);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "���������� ����: 42\n");

    testing::internal::CaptureStdout();
    printNodeData(static_cast<TreeNode<int>*>(nullptr));
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "���� ������\n");

    delete node;
}

// ���� 8: �������� �������� ������� BST
TEST_F(BinaryTreeTest, BSTCreation) {
    BST<int> bst;
    EXPECT_EQ(bst.getRoot(), nullptr);
}

// ���� 9: �������� ������� ����� � BST
TEST_F(BinaryTreeTest, BSTInsert) {
    BST<int> bst;
    bst.insert(5);
    EXPECT_NE(bst.getRoot(), nullptr);
    EXPECT_EQ(bst.getRoot()->data, 5);
    EXPECT_EQ(bst.getRoot()->left, nullptr);
    EXPECT_EQ(bst.getRoot()->right, nullptr);

    bst.insert(3);
    EXPECT_NE(bst.getRoot()->left, nullptr);
    EXPECT_EQ(bst.getRoot()->left->data, 3);

    bst.insert(7);
    EXPECT_NE(bst.getRoot()->right, nullptr);
    EXPECT_EQ(bst.getRoot()->right->data, 7);

    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    EXPECT_EQ(bst.getRoot()->left->left->data, 1);
    EXPECT_EQ(bst.getRoot()->left->right->data, 4);
    EXPECT_EQ(bst.getRoot()->right->left->data, 6);
    EXPECT_EQ(bst.getRoot()->right->right->data, 8);
}

// ���� 10: �������� ������ ����� � BST
TEST_F(BinaryTreeTest, BSTSearch) {
    BST<int> bst = createSampleBST();
    TreeNode<int>* found = bst.search(4);
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->data, 4);

    found = bst.search(5);
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->data, 5);

    found = bst.search(1);
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->data, 1);

    found = bst.search(10);
    EXPECT_EQ(found, nullptr);

    BST<int> emptyBst;
    found = emptyBst.search(5);
    EXPECT_EQ(found, nullptr);
}

// ���� 11: �������� ����������� BST
TEST_F(BinaryTreeTest, BSTCopy) {
    BST<int> bst = createSampleBST();
    BST<int> bstCopy = bst.copy();

    EXPECT_NE(bstCopy.getRoot(), nullptr);
    EXPECT_EQ(bstCopy.getRoot()->data, 5);
    EXPECT_EQ(bstCopy.getRoot()->left->data, 3);
    EXPECT_EQ(bstCopy.getRoot()->right->data, 7);
    EXPECT_EQ(bstCopy.getRoot()->left->left->data, 1);
    EXPECT_EQ(bstCopy.getRoot()->left->right->data, 4);
    EXPECT_EQ(bstCopy.getRoot()->right->left->data, 6);
    EXPECT_EQ(bstCopy.getRoot()->right->right->data, 8);

    EXPECT_NE(bst.getRoot(), bstCopy.getRoot());
    EXPECT_NE(bst.getRoot()->left, bstCopy.getRoot()->left);
}

// ���� 12: �������� ������ � ������ (BFS)
TEST_F(BinaryTreeTest, BSTLevelOrder) {
    BST<int> bst = createSampleBST();
    std::vector<int> expected = { 5, 3, 7, 1, 4, 6, 8 };
    EXPECT_EQ(bst.levelOrder(), expected);

    BST<int> emptyBst;
    EXPECT_TRUE(emptyBst.levelOrder().empty());
}

// ���� 13: �������� ��������� �����
TEST_F(BinaryTreeTest, BSTGetRoot) {
    BST<int> bst;
    EXPECT_EQ(bst.getRoot(), nullptr);

    bst.insert(5);
    EXPECT_NE(bst.getRoot(), nullptr);
    EXPECT_EQ(bst.getRoot()->data, 5);

    bst.insert(3);
    EXPECT_EQ(bst.getRoot()->left->data, 3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}