#include <iostream>
#include "LinkedList.h"
#include "Iterator.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    LinkedList<int> list;

    // Вставка элементов
    list.insert(30);
    list.insert(10);
    list.insert(50);
    list.insert(20);
    list.insert(40);

    cout << "Список до сортировки:" << endl;
    list.print();

    // Поиск элемента
    int valueToSearch = 30;
    auto found = list.search(valueToSearch);
    if (found) {
        cout << "Элемент " << valueToSearch << " найден." << endl;
    }
    else {
        cout << "Элемент " << valueToSearch << " не найден." << endl;
    }

    // Удаление элемента
    int valueToDelete = 30;
    list.remove(valueToDelete);
    cout << "Список после удаления " << valueToDelete << ":" << endl;
    list.print();

    // Сортировка
    list.sort();
    cout << "Отсортированный список:" << endl;
    list.print();

    // Демонстрация итератора
    cout << "Обход с использованием итератора:" << endl;
    for (Iterator<int>* it = list.begin(); *it != *list.end(); ++(*it)) {
        cout << **it << " ";
    }
    cout << endl;

    return 0;
}
