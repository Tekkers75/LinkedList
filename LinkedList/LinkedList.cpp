#include <iostream>
#include "LinkedList.h"
#include "Iterator.h"


int main() {

    setlocale(LC_ALL, "rus");
    LinkedList<int> list;

    list.insert(30);
    list.insert(10);
    list.insert(50);
    list.insert(20);
    list.insert(40);

    // Поиск элемента
    int searchData = 30;
    Node<int>* foundNode = list.search(searchData);
    if (foundNode != nullptr) {
        std::cout << "Элемент " << searchData << " найден." << std::endl;
    }
    else {
        std::cout << "Элемент " << searchData << " не найден." << std::endl;
    }

    list.print();

    int deleteData = 30;
    list.remove(deleteData);

    list.print();

    std::cout << "Исходный список: ";
    list.print();

    list.sort();

    std::cout << "Отсортированный список: ";
    list.print();
     
    list.insert(65);
    list.insertHead(42);
    list.print();


    list.insertAfter(42, 56);
    list.print();


    //for (Iterator<int> it =list.begin();  /*list.begin();*/ it != list.end(); ++it) {
    //    std::cout << *it << " ";
    //}
    //std::cout << std::endl;

    for (LinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    //for (LinkedList<int>::Iterator<int> it = list.begin(); it != list.end(); ++it) {
    //    std::cout << *it << " ";
    //}
    //std::cout << std::endl;

    return 0;
}

