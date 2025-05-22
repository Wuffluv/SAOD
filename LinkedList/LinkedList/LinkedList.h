#pragma once
#include <iostream>
#include "Iterator.h"

using namespace std;

// ����� ���������� �������� ������
template <typename T>
class LinkedList {
public:
    // ��������� ����� ���� ������
    class Node {
    public:
        T data;         // ������, ���������� � ����
        Node* next;     // ��������� �� ��������� ����

        // ����������� ����
        Node(T data) {
            this->data = data;
            next = nullptr; // �� ��������� ��������� ���� �����������
        }
    };

private:
    Node* head;         // ��������� �� ������ ���� ������
    Node* tail;         // ��������� �� ��������� ���� ������

public:
    // ����������� �� ��������� (������ ������)
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // ������� �������� � ����� ������ (������ push_back)
    void insert(const T& value) {
        Node* newNode = new Node(value); // ������� ����� ����
        if (!head) {
            // ���� ������ ����, ����� ���� ���������� � ������� � �������
            head = tail = newNode;
        }
        else {
            // ����� ��������� ���� � ����� � ��������� �����
            tail->next = newNode;
            tail = newNode;
        }
    }

    // ������ ���� ��������� ������
    void print() const {
        Node* current = head; // �������� � ������
        while (current != nullptr) {
            cout << current->data << " "; // ������� ������ ����
            current = current->next;      // ��������� � ���������� ����
        }
        cout << endl;
    }

    // ����� ���� �� �������� (���������� ��������� �� ��������� ���� ��� nullptr)
    Node* search(const T& value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current; // ���� ������
            }
            current = current->next;
        }
        return nullptr; // ���� �� ������
    }

    // �������� �������� �� �������� (������� ������ ��������� �������)
    void remove(const T& value) {
        Node* current = head;
        Node* previous = nullptr; // ��������� �� ���������� ����

        while (current != nullptr) {
            if (current->data == value) {
                // ������ ���� ��� ��������
                if (current == head) {
                    // ������� ������ ������
                    head = head->next;
                    if (current == tail) {
                        // ���� ��� ��� ������������ ����
                        tail = nullptr;
                    }
                }
                else {
                    // ������� ���� �� �������� ��� �����
                    previous->next = current->next;
                    if (current == tail) {
                        // ���� ������� �����
                        tail = previous;
                    }
                }
                delete current; // ����������� ������
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    // ���������� ������� (�� ������ ���� �������, ������ ��������)
    void sort() {
        for (Node* i = head; i != nullptr; i = i->next) {
            Node* minNode = i; // ������������, ��� ������� ���� �����������
            // ���� ����������� ���� � ���������� �����
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (j->data < minNode->data) {
                    minNode = j;
                }
            }
            // ���� ����� ���� � ������� ���������, ������ ������ �������
            if (minNode != i) {
                swap(i->data, minNode->data);
            }
        }
    }

    // ��������� ����� ��������� ��� LinkedList
    class LinkedListIterator : public Iterator<T> {
    private:
        Node* current; // ������� ���� ���������

    public:
        // ����������� ��������� (�������� � ���������� ����)
        LinkedListIterator(Node* node) {
            current = node;
        }

        // ���������� ��������� ������������� (������ � ������ �������� ����)
        T& operator*() override {
            return current->data;
        }

        // ���������� ��������� (++it)
        Iterator<T>& operator++() override {
            if (current) current = current->next; // ��������� � ���������� ����
            return *this;
        }

        // ����������� ��������� (it++)
        Iterator<T>& operator++(int) override {
            LinkedListIterator* temp = new LinkedListIterator(current);
            ++(*this);
            return *temp;
        }

        // �������� ��������� ����������
        bool operator==(const Iterator<T>& other) override {
            const LinkedListIterator* o = dynamic_cast<const LinkedListIterator*>(&other);
            return o && current == o->current;
        }

        // �������� ����������� ����������
        bool operator!=(const Iterator<T>& other) override {
            return !(*this == other);
        }
    };

    // ����� ��� ��������� ��������� �� ������ ������
    Iterator<T>* begin() {
        return new LinkedListIterator(head); // �������� �������� � ������
    }

    // ����� ��� ��������� ��������� �� ����� ������ (�� ��������� ���������)
    Iterator<T>* end() {
        return new LinkedListIterator(nullptr); // �������� � current = nullptr
    }
};