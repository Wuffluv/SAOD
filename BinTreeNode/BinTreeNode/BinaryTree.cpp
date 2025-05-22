#include "BinaryTree.h"
#include "BST.h"
#include <locale.h>
#include <functional>
#include <list>
#include <vector>


// Удвоение узлов (тестим для проверки что значения работают)
void doubleValue(int& x) {
    x *= 2;
}

// Функция для создания бинарного дерева из 5 узлов
TreeNode<int>* createSampleTree() {
    // Создаем корневой узел со значением 1
    TreeNode<int>* root = new TreeNode<int>(1);
    // Создаем левое поддерево
    root->left = new TreeNode<int>(2);
    root->left->left = new TreeNode<int>(4);
    // Создаем правое поддерево
    root->right = new TreeNode<int>(3);
    root->right->right = new TreeNode<int>(5);
    return root;
}

// Основная функция программы
int main() {
    setlocale(LC_ALL, "RUS"); 

    std::cout << "\n=== Лабораторная работа: Обычное бинарное дерево ===\n" << std::endl;

    // Создаем бинарное дерево
    TreeNode<int>* root = createSampleTree();
    std::cout << "Структура бинарного дерева:" << std::endl;
    printTree(root);

    // Вставляем новое значение 
    std::cout << "\nВставляем значение 6 в дерево:" << std::endl;
    insert(root, 6);
    std::cout << "Структура дерева после вставки:" << std::endl;
    printTree(root);

    // Поиск первого вхождения значения
    int searchValue = 5; 
    std::cout << "Поиск 5:  " << searchValue << ":" << std::endl;
    TreeNode<int>* foundNode = searchTree(root, searchValue);
    printNodeData(foundNode);

    // Демонстрация обходов: создание массивов
    std::vector<int> nlr_result, lnr_result, lrn_result;
    std::cout << "\nNLR (Pre-order) обход (вектор): ";
    NLR_toVector(root, nlr_result);
    for (int x : nlr_result) std::cout << x << " ";
    std::cout << "\nLNR (In-order) обход (вектор): ";
    LNR_toVector(root, lnr_result);
    for (int x : lnr_result) std::cout << x << " ";
    std::cout << "\nLRN (Post-order) обход (вектор): ";
    LRN_toVector(root, lrn_result);
    for (int x : lrn_result) std::cout << x << " ";
    std::cout << std::endl;

    // Демонстрация обходов: вывод содержимого
    std::cout << "\nNLR (Pre-order) вывод: ";
    NLR_print(root);
    std::cout << "\nLNR (In-order) вывод: ";
    LNR_print(root);
    std::cout << "\nLRN (Post-order) вывод: ";
    LRN_print(root);
    std::cout << std::endl;

    // Демонстрация обходов: применение функции
    std::cout << "\nПрименяем удвоение значений (NLR):" << std::endl;
    NLR_apply<int>(root, std::function<void(int&)>(doubleValue));
    std::cout << "Структура дерева после удвоения:" << std::endl;
    printTree(root);

    // Тесты LNR_apply и LRN_apply
    std::cout << "\nПрименяем удвоение значений (LNR):" << std::endl;
    LNR_apply<int>(root, std::function<void(int&)>(doubleValue));
    std::cout << "Структура дерева после удвоения (LNR):" << std::endl;
    printTree(root);

    std::cout << "\nПрименяем удвоение значений (LRN):" << std::endl;
    LRN_apply<int>(root, std::function<void(int&)>(doubleValue));
    std::cout << "Структура дерева после удвоения (LRN):" << std::endl;
    printTree(root);

    // Подсчёт узлов
    std::cout << "\nКоличество узлов в дереве: " << countNodes(root) << std::endl;

    // Глубина дерева
    std::cout << "Глубина дерева: " << treeDepth(root) << std::endl;

    // Просмотр содержимого корневого узла
    std::cout << "\nПросмотр содержимого корневого узла:" << std::endl;
    printNodeData(root);

    // Итераторы для vector (NLR)
    std::cout << "\nИтераторы для std::vector (NLR):" << std::endl;
    std::cout << "Цикл for (item : collection): ";
    for (int x : nlr_result) {
        std::cout << x << " ";
    }
    std::cout << "\nЯвный итератор: ";
    for (auto it = nlr_result.begin(); it != nlr_result.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Итераторы для list (LNR)
    std::cout << "\nИтераторы для std::list (LNR):" << std::endl;
    std::list<int> lnr_list(lnr_result.begin(), lnr_result.end());
    std::cout << "Цикл for (item : collection): ";
    for (int x : lnr_list) {
        std::cout << x << " ";
    }
    std::cout << "\nЯвный итератор: ";
    for (auto it = lnr_list.begin(); it != lnr_list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Удаление дерева
    std::cout << "\nУдаление всех узлов..." << std::endl;
    deleteTree(root);

    


    std::cout << "\n=== Лабораторная работа: Бинарное дерево поиска (BST) ===\n" << std::endl;

    // Создаём бинарное дерево поиска
    BST<int> bst;
    std::cout << "Вставляем значения в BST: 5, 3, 7, 1, 4" << std::endl;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);

    // Вывод структуры BST
    std::cout << "\nСтруктура BST:" << std::endl;
    printTree(bst.getRoot());

    // Демонстрация обхода в ширину
    std::cout << "\nОбход в ширину (BFS): ";
    std::vector<int> bfs_result = bst.levelOrder();
    for (int x : bfs_result) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Копирование BST
    std::cout << "\nКопируем BST" << std::endl;
    BST<int> bst_copy = bst.copy();
    std::cout << "Структура скопированного BST:" << std::endl;
    printTree(bst_copy.getRoot());

    // Применяем удвоение значений к скопированному дереву (NLR)
    std::cout << "\nУдваиваем значения в скопированном BST (NLR):" << std::endl;
    NLR_apply<int>(bst_copy.getRoot(), std::function<void(int&)>(doubleValue));
    std::cout << "Структура после удвоения:" << std::endl;
    printTree(bst_copy.getRoot());

    // Итераторы для vector (ДЛЯ обхода в ширину)
    std::cout << "\nИтераторы для std::vector (BFS):" << std::endl;
    std::cout << "Цикл for (item : collection): ";
    for (int x : bfs_result) {
        std::cout << x << " ";
    }
    std::cout << "\nЯвный итератор: ";
    for (auto it = bfs_result.begin(); it != bfs_result.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Итераторы для std::list (LNR для BST)
    std::cout << "\nИтераторы для std::list (LNR для BST):" << std::endl;
    std::vector<int> lnr_bst_result;
    LNR_toVector(bst.getRoot(), lnr_bst_result);
    std::list<int> lnr_bst_list(lnr_bst_result.begin(), lnr_bst_result.end());
    std::cout << "Цикл for (item : collection): ";
    for (int x : lnr_bst_list) {
        std::cout << x << " ";
    }
    std::cout << "\nЯвный итератор: ";
    for (auto it = lnr_bst_list.begin(); it != lnr_bst_list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Подсчёт узлов и глубина BST
    std::cout << "\nКоличество узлов в BST: " << countNodes(bst.getRoot()) << std::endl;
    std::cout << "Глубина BST: " << treeDepth(bst.getRoot()) << std::endl;

    // Просмотр содержимого корневого узла BST
    std::cout << "\nПросмотр содержимого корневого узла BST:" << std::endl;
    printNodeData(bst.getRoot());
    
    
   



    

    return 0;
}