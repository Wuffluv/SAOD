//@author Рычков Р.В.
#include <iostream>
#include "Heap.h"
#include <algorithm>
#include <vector>
#include "Test.h"

int main() {
    setlocale(LC_ALL, "RUS");
    Heap<int> heap(5);

    heap.Insert(5);
    heap.Insert(3);
    heap.Insert(7);
    heap.Insert(2);
    heap.Insert(4);
    heap.Insert(12);
    heap.Insert(1);
    heap.deleteNode(4);
    heap.deleteNode(12);
    heap.Insert(6);



    //            12
    //    7               5
    //4       3       2       1

    //12 7 5 4 3 2 1

    //            7
    //    6               5
    //3       2       1

    heap.Search(12);
    heap.Search(6);


    std::cout << "Размер кучи: " << heap.Size() << std::endl;
    heap.print();




    while (!heap.IsEmpty()) {
        int maxElement = heap.ExtractMax();
        std::cout << maxElement << " ";
    }




    std::cout << std::endl;


    std::vector<int> v{3, 5, 1, 2, 12, 6, 7, 4 };
    int* arr = new int[10] { 3, 2, 4, 1, 5, 9 };





    // организует массив по принципу кучи (max heap)
    std::make_heap(v.begin(), v.end());

    //      9
    //	 / 	 \
    //   5     4
    //  / \    /
    // 1   2  3

    for (int x : v)
        std::cout << x << " ";
    // 9 5 4 1 2 3

    std::cout << "куча: : " << is_heap(v.begin(), v.end());
    std::cout << std::endl;

    //Тесты
    std::cout << "\n" << std::endl;
    std::cout << "Тесты: \n" << std::endl;
    TestConstructor();
    TestInsert();
    TestExtractMax();
    TestSize();
    TestIsEmpty();
    TestDelete();
    TestSearch();
    TestDelete2();
    std::cout << "\n" << std::endl;
    std::cout << "Конец тестов: \n" << std::endl;
    std::cout << "\n" << std::endl;

    heap.InsertOld(5);
    heap.InsertOld(3);
    heap.InsertOld(7);
    heap.InsertOld(2);
    heap.InsertOld(4);
    heap.InsertOld(12);
    heap.InsertOld(1);
 
 
    heap.print();




    return 0;
};