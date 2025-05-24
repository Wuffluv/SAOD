#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Функция для вывода массива
void printList(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Функция сортировки с использованием min-heap
void heapSort(vector<int>& arr) {
    // Создаем min-heap с компаратором greater<int>
    //это объект или функция, которая определяет, как сравнивать два элемента в контексте 
    // сортировки или упорядочивания. В C++ компаратор используется в структурах данных 
    // (например, std::priority_queue, std::sort, std::set) для задания порядка элементов.
    //std::greater<int> — это стандартный компаратор из библиотеки <functional>, 
    // который определяет сравнение элементов так, что больший элемент считается "меньше" в
    // контексте упорядочивания. Это приводит к созданию min-heap в std::priority_queue.

    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Вставляем все элементы массива в кучу
    for (int num : arr) {
        minHeap.push(num);
    }

    // Извлекаем элементы из кучи и записываем в массив
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = minHeap.top(); // Берем минимальный элемент
        minHeap.pop();          // Удаляем его из кучи
    }
}

int main() {
    // Инициализация тестового массива
    vector<int> arr = { 8, 34, 233, 21, 89, 13, 5, 2, 144, 3, 55, 1 };

    // Вывод исходного массива
    cout << "Начальный массив: ";
    printList(arr);
    cout << endl;

    // Сортировка массива
    heapSort(arr);

    // Вывод отсортированного массива
    cout << "Конечный массив: ";
    printList(arr);
    cout << endl;

    return 0;
}