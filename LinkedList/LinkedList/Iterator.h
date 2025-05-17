#pragma once
#include <iostream>

// Абстрактный класс итератора
template <typename T>
class Iterator {
public:
    virtual T& operator*() = 0;                       // возвращает текущий элемент
    virtual Iterator<T>& operator++() = 0;            // префиксный инкремент
    virtual Iterator<T>& operator++(int) = 0;         // постфиксный инкремент
    virtual bool operator==(const Iterator<T>& other) = 0; // сравнение ==
    virtual bool operator!=(const Iterator<T>& other) = 0; // сравнение !=
    virtual ~Iterator() {}                            // виртуальный деструктор
};
