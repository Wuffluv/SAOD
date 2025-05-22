#pragma once
#include <iostream>
#include "Iterator.h"

using namespace std;

// Класс шаблонного связного списка
template <typename T>
class LinkedList {
public:
    // Вложенный класс узла списка
    class Node {
    public:
        T data;         // Данные, хранящиеся в узле
        Node* next;     // Указатель на следующий узел

        // Конструктор узла
        Node(T data) {
            this->data = data;
            next = nullptr; // По умолчанию следующий узел отсутствует
        }
    };

private:
    Node* head;         // Указатель на первый узел списка
    Node* tail;         // Указатель на последний узел списка

public:
    // Конструктор по умолчанию (пустой список)
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Вставка элемента в конец списка (аналог push_back)
    void insert(const T& value) {
        Node* newNode = new Node(value); // Создаем новый узел
        if (!head) {
            // Если список пуст, новый узел становится и головой и хвостом
            head = tail = newNode;
        }
        else {
            // Иначе добавляем узел в конец и обновляем хвост
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Печать всех элементов списка
    void print() const {
        Node* current = head; // Начинаем с головы
        while (current != nullptr) {
            cout << current->data << " "; // Выводим данные узла
            current = current->next;      // Переходим к следующему узлу
        }
        cout << endl;
    }

    // Поиск узла по значению (возвращает указатель на найденный узел или nullptr)
    Node* search(const T& value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current; // Узел найден
            }
            current = current->next;
        }
        return nullptr; // Узел не найден
    }

    // Удаление элемента по значению (удаляет первый найденный элемент)
    void remove(const T& value) {
        Node* current = head;
        Node* previous = nullptr; // Указатель на предыдущий узел

        while (current != nullptr) {
            if (current->data == value) {
                // Найден узел для удаления
                if (current == head) {
                    // Удаляем голову списка
                    head = head->next;
                    if (current == tail) {
                        // Если это был единственный узел
                        tail = nullptr;
                    }
                }
                else {
                    // Удаляем узел из середины или конца
                    previous->next = current->next;
                    if (current == tail) {
                        // Если удаляем хвост
                        tail = previous;
                    }
                }
                delete current; // Освобождаем память
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    // Сортировка выбором (не меняет узлы местами, только значения)
    void sort() {
        for (Node* i = head; i != nullptr; i = i->next) {
            Node* minNode = i; // Предполагаем, что текущий узел минимальный
            // Ищем минимальный узел в оставшейся части
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (j->data < minNode->data) {
                    minNode = j;
                }
            }
            // Если нашли узел с меньшим значением, меняем данные местами
            if (minNode != i) {
                swap(i->data, minNode->data);
            }
        }
    }

    // Вложенный класс итератора для LinkedList
    class LinkedListIterator : public Iterator<T> {
    private:
        Node* current; // Текущий узел итератора

    public:
        // Конструктор итератора (начинает с указанного узла)
        LinkedListIterator(Node* node) {
            current = node;
        }

        // Перегрузка оператора разыменования (доступ к данным текущего узла)
        T& operator*() override {
            return current->data;
        }

        // Префиксный инкремент (++it)
        Iterator<T>& operator++() override {
            if (current) current = current->next; // Переходим к следующему узлу
            return *this;
        }

        // Постфиксный инкремент (it++)
        Iterator<T>& operator++(int) override {
            LinkedListIterator* temp = new LinkedListIterator(current);
            ++(*this);
            return *temp;
        }

        // Оператор сравнения итераторов
        bool operator==(const Iterator<T>& other) override {
            const LinkedListIterator* o = dynamic_cast<const LinkedListIterator*>(&other);
            return o && current == o->current;
        }

        // Оператор неравенства итераторов
        bool operator!=(const Iterator<T>& other) override {
            return !(*this == other);
        }
    };

    // Метод для получения итератора на начало списка
    Iterator<T>* begin() {
        return new LinkedListIterator(head); // Итератор начинает с головы
    }

    // Метод для получения итератора на конец списка (за последним элементом)
    Iterator<T>* end() {
        return new LinkedListIterator(nullptr); // Итератор с current = nullptr
    }
};