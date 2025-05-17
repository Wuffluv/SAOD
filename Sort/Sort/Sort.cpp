#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printList(const vector<int>& arr);
void tournamentSort(vector<int>& arr);

int main() {
    vector<int> arr = { 8, 34, 233, 21, 89, 13, 5, 2, 144, 3, 55, 1 };

    cout << "Start array: ";
    printList(arr);
    cout << endl;

    tournamentSort(arr);

    cout << "End array: ";
    printList(arr);

    cout << endl;


}

void printList(const vector<int>& arr)
{
    // Выводим массив
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void tournamentSort(vector<int>& arr)
{
    // Определяем размер дерева турнира
    int treeSize = 1;
    while (treeSize <= arr.size()) {
        treeSize *= 2;
    }

    // Создаем вектор с размером, равным общему количеству узлов (элементов) в дереве турнира
    vector<int> tree(2 * treeSize, numeric_limits<int>::max());

    // Заполняем узлы дерева элементами из неотсортированного массива
    for (int i = 0; i < arr.size(); i++) {
        tree[treeSize + i] = arr[i];
    }

    // Строим дерево турнира, выбирая минимум из каждой пары узлов
    for (int i = treeSize - 1; i >= 1; i--) {
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }

    // Извлекаем элементы из дерева турнира в возрастающем порядке
    int sortIndex = 0;
    while (sortIndex < arr.size()) {
        // Записываем корень в исходный массив и присваиваем корню "бесконечное" значение
        arr[sortIndex++] = tree[1];
        tree[1] = numeric_limits<int>::max();

        // Заменяем минимальное значение на "бесконечность"
        int node = 1;
        while (node < treeSize) {
            int leftChild = 2 * node;
            int rightChild = 2 * node + 1;

            // Узел получает индекс наименьшего значения
            node = (tree[leftChild] < tree[rightChild]) ? leftChild : rightChild;

            // Устанавливаем наименьшее число на "бесконечность"
            if (tree[leftChild] < tree[rightChild]) {
                tree[leftChild] = numeric_limits<int>::max();
            }
            else {
                tree[rightChild] = numeric_limits<int>::max();
            }
        }

        // Распространяем минимум каждой пары узлов
        for (int i = treeSize - 1; i >= 1; i--) {
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
    }
}