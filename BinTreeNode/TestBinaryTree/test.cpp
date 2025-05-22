#include <gtest/gtest.h>
#include "../BinTreeNode/BinaryTree.h"

// Тестовый класс для группировки тестов
class BinaryTreeTest : public ::testing::Test {
protected:
    // Инициализация перед каждым тестом
    void SetUp() override {
        // Можно добавить общую инициализацию, если нужно
    }

    // Очистка после каждого теста
    void TearDown() override {
        // Освобождаем ресурсы, если они были созданы
    }
};

// Проверка создания узла
TEST_F(BinaryTreeTest, NodeCreation) {
    TreeNode<int> node(10);
    EXPECT_EQ(node.data, 10);
    EXPECT_EQ(node.left, nullptr);
    EXPECT_EQ(node.right, nullptr);
}

// Проверка вставки узлов
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

    insert(root, 7);
    EXPECT_NE(root->right, nullptr);
    EXPECT_EQ(root->right->data, 7);

    deleteTree(root);
}

// Проверка поиска
TEST_F(BinaryTreeTest, SearchTree) {
    TreeNode<int>* root = createSampleTree();
    ASSERT_NE(root, nullptr); // Проверяем, что дерево создано
    EXPECT_NE(searchTree(root, 4), nullptr);
    EXPECT_EQ(searchTree(root, 4)->data, 4);
    EXPECT_EQ(searchTree(root, 10), nullptr);
    deleteTree(root);
}

// Проверка подсчета узлов
TEST_F(BinaryTreeTest, CountNodes) {
    TreeNode<int>* root = createSampleTree();
    ASSERT_NE(root, nullptr);
    EXPECT_EQ(countNodes(root), 7);
    deleteTree(root);
}

// Проверка глубины дерева
TEST_F(BinaryTreeTest, TreeDepth) {
    TreeNode<int>* root = createSampleTree();
    ASSERT_NE(root, nullptr);
    EXPECT_EQ(treeDepth(root), 2);
    deleteTree(root);
}

// Проверка удаления дерева
TEST_F(BinaryTreeTest, DeleteTree) {
    TreeNode<int>* root = createSampleTree();
    ASSERT_NE(root, nullptr);
    deleteTree(root);
    EXPECT_EQ(root, nullptr);
}

// Проверка пустого дерева
TEST_F(BinaryTreeTest, EmptyTree) {
    TreeNode<int>* root = nullptr;
    EXPECT_EQ(countNodes(root), 0);
    EXPECT_EQ(treeDepth(root), -1);
    EXPECT_EQ(searchTree(root, 5), nullptr);

    std::vector<int> result;
    LNR_toVector(root, result);
    EXPECT_TRUE(result.empty());
}

// Точка входа для запуска тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}