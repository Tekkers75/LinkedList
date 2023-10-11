#include <iostream>
#include "LinkedList.h"


int main() {

    setlocale(LC_ALL, "rus");
    LinkedList list;

    list.insert(30);
    list.insert(10);
    list.insert(50);
    list.insert(20);
    list.insert(40);

    // Поиск элемента
    int searchData = 30;
    Node* foundNode = list.search(searchData);
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
     

    return 0;
}

