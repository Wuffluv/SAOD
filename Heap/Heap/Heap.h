//@author Рычков Р.В.
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Класс куча max
template <typename T>
class Heap
{
private:
    T* heapArray;       // указатель на массив
    int arraySize;      // максимальная емкость кучи
    int heapSize;       // текущий размер кучи

    //Восстановления свойств кучи после вставки элемента. 
    void HeapifyUp(int index) {
        // Если текущий индекс указывает на корневой элемент,
        // то достигнута вершина кучи, и завершаем рекурсию. ==
        if (index == 0)
            return;
        // Вычисляем индекс родительского элемента.
        int parent = (index - 1) / 2;
        // Если значение родительского элемента меньше значения текущего элемента,
        // то меняем их местами.
        if (heapArray[parent] < heapArray[index]) {
            std::swap(heapArray[parent], heapArray[index]);
            // Рекурсивно вызываем HeapifyUp для родительского элемента,
            // чтобы проверить и восстановить свойства кучи выше.
            HeapifyUp(parent);
        }
    }

    //Восстановления свойств кучи после удаления максимального элемента 
    // или изменения значения элемента.
    void HeapifyDown(int index) {
        // Вычисляем индексы левого и правого дочерних элементов.
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        // Предполагаем, что текущий индекс содержит наибольший элемент.
        int largest = index;

        // Проверяем, является ли левый дочерний элемент больше текущего наибольшего элемента.
        // Если да, то обновляем индекс наибольшего элемента.
        if (leftChild < heapSize && heapArray[leftChild] > heapArray[largest])
            largest = leftChild;
        // Проверяем, является ли правый дочерний элемент больше текущего наибольшего элемента.
        // Если да, то обновляем индекс наибольшего элемента.
        if (rightChild < heapSize && heapArray[rightChild] > heapArray[largest])
            largest = rightChild;
        // Если наибольший элемент не является текущим элементом,
        // то меняем их местами и рекурсивно вызываем HeapifyDown для наибольшего элемента.
        if (largest != index) {
            std::swap(heapArray[index], heapArray[largest]);
            HeapifyDown(largest);
        }
    }

public:
    // Конструктор класса куча
    Heap(int capacity) : heapSize(0), arraySize(capacity) {
        if (arraySize <= 0)
            throw std::out_of_range("Heap is full");
        heapArray = new T[arraySize];
    }

    // Деструктор класса куча
    ~Heap() {
        delete[] heapArray;
    }

    // Метод для добавления элемента в кучу
    void InsertOld(const T& item) {
        // Проверка, чтобы убедиться, что куча не достигла своей максимальной емкости.
        if (heapSize == arraySize)
            throw std::out_of_range("Heap is full");
        // Помещаем новый элемент в конец кучи
        heapArray[heapSize] = item;
        // Увеличиваем размер кучи
        heapSize++;
        // Вызываем HeapifyUp для восстановления свойств кучи
        HeapifyUp(heapSize - 1);
    }


    //Вставка нового элемента с увеличением размера кучи
    void Insert(T newNum)
    { //если размер кучи больше или равен макс
        if (heapSize >= arraySize)
        {
            // Максимальный размер кучи достигнут
            int NewArraySize = arraySize * 2; // Увеличение размера в два раза
            //перевыделение памяти
            T* newHeapArr = new T[NewArraySize];

            // Копирование существующих элементов в новый блок памяти
            for (int i = 0; i < heapSize; i++)
            {
                newHeapArr[i] = heapArray[i];
            }

            // Освобождение старого блока памяти
            delete[] heapArray;

            // Обновление указателя на новый блок памяти и максимального размера кучи
            heapArray = newHeapArr;
            arraySize = NewArraySize;

        }
        //если размер кучи=0,куча пуста
        if (heapSize == 0)
        {//новый элемент помещается в корень кучи
            heapArray[0] = newNum;
            //размер увеличивается на 1
            heapSize++;
        }
        else
        { //иначе новый элемент добавляется в конец кучи
            heapArray[heapSize] = newNum;
            //размер увеличивается на 1
            heapSize++;
            //цикл преобразования массива в кучу макс
            //Цикл выполняется для каждого родительского элемента,
            // начиная с последнего родителя и двигаясь к корню кучи.
            for (int i = heapSize / 2 - 1; i >= 0; i--)
            {//преобразование массива в кучу
                HeapifyUp(i);
            }
        }
    }

    // Метод для удаления и возвращения максимального элемента из кучи
    T ExtractMax() {
        // Проверка, чтобы убедиться, что куча не достигла своей максимальной емкости.
        if (heapSize == 0)
            throw std::out_of_range("Heap is empty");
        // Сохраняем текущий максимальный элемент
        T maxElement = heapArray[0];
        // Заменяем корень кучи последним элементом
        heapArray[0] = heapArray[heapSize - 1];
        // Уменьшаем размер кучи
        heapSize--;
        // Вызываем HeapifyDown для восстановления свойств кучи
        HeapifyDown(0);
        // Возвращаем сохраненный максимальный элемент
        return maxElement;
    }

    // Метод для получения текущего размера кучи
    int Size() const {
        return heapSize;
    }

    // Метод для проверки, пустая ли куча
    bool IsEmpty() const {
        return heapSize == 0;
    }


    //удаление элемента
    void deleteNode(T num)
    {
        int i;
        // Проверка, чтобы убедиться, что куча не пуста.
        if (heapSize == 0)
            throw std::out_of_range("Heap is empty");
        //проходим по элементам кучи
        for (i = 0; i < heapSize; i++)
        {
            //сравниваем искомый с элементом массива
            //если элемент найден,цикл прерывается
            //и индекс сохраняется в переменную i 
            if (num == heapArray[i])
                break;
        }
        //если индекс i равен размеру кучи,то элемент в куче не нашелся
        if (i == heapSize)
        {
            throw std::out_of_range("Heap is empty");
        }
        //если элемент найден
        //обмениваем элементы
        std::swap(heapArray[i], heapArray[heapSize - 1]);
        //размер кучи уменьшается
        heapSize--;
        //после удаления происходит преобразование в кучу макс
        HeapifyDown(i);
    }

    void print() {
        for (int i = 0; i < heapSize; i++)
        {
            std::cout << heapArray[i] << " ";
        }
        std::cout << std::endl;
    }


    // Метод для поиска элемента в куче
    bool Search(const T& item) const {
        for (int i = 0; i < heapSize; i++) {
            if (heapArray[i] == item) {
                std::cout << "Item found in heap" << std::endl;
                return true; // Элемент найден
            }
        }
        std::cout << "Item not found in heap" << std::endl;
        return false; // Элемент не найден
    }

   
};