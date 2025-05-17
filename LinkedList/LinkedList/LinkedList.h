#pragma once
#include <iostream>
#include "Iterator.h"

using namespace std;

// Класс шаблонного связного списка
template <typename T>
class LinkedList {
public:
    // Вложенный класс узла
    class Node {
    public:
        T data;         // данные
        Node* next;     // указатель на следующий узел

        Node(T data) {
            this->data = data;
            next = nullptr;
        }
    };

private:
    Node* head;         // голова списка
    Node* tail;         // хвост списка

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Вставка элемента в конец списка
    void insert(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Печать всех элементов списка
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Поиск узла по значению
    Node* search(const T& value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Удаление элемента по значению
    void remove(const T& value) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->data == value) {
                if (current == head) {
                    head = head->next;
                    if (current == tail) {
                        tail = nullptr;
                    }
                }
                else {
                    previous->next = current->next;
                    if (current == tail) {
                        tail = previous;
                    }
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    // Сортировка выбором
    void sort() {
        for (Node* i = head; i != nullptr; i = i->next) {
            Node* minNode = i;
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (j->data < minNode->data) {
                    minNode = j;
                }
            }
            if (minNode != i) {
                swap(i->data, minNode->data);
            }
        }
    }

    // Конкретный итератор для LinkedList
    class LinkedListIterator : public Iterator<T> {
    private:
        Node* current;

    public:
        LinkedListIterator(Node* node) {
            current = node;
        }

        T& operator*() override {
            return current->data;
        }

        Iterator<T>& operator++() override {
            if (current) current = current->next;
            return *this;
        }

        Iterator<T>& operator++(int) override {
            LinkedListIterator* temp = new LinkedListIterator(current);
            ++(*this);
            return *temp;
        }

        bool operator==(const Iterator<T>& other) override {
            const LinkedListIterator* o = dynamic_cast<const LinkedListIterator*>(&other);
            return o && current == o->current;
        }

        bool operator!=(const Iterator<T>& other) override {
            return !(*this == other);
        }
    };

    // Методы получения итераторов
    Iterator<T>* begin() {
        return new LinkedListIterator(head);
    }

    Iterator<T>* end() {
        return new LinkedListIterator(nullptr);
    }
};
