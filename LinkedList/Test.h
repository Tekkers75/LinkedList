// @author Саранчин К.А.
#pragma once
#include <iostream>
#include "LinkedList.h"
#include <cassert>

void Test_operator() {
    LinkedList<int> list;
    list.insertHead(3);
    list.insertHead(2);
    list.insertHead(1);

    LinkedList<int>::Iterator<int> it = list.begin();
    // Получаем ссылку на значение через итератор
    int& value = *it; 
    
    // Проверяем, что значение равно 1
    assert(value == 1); 
    
    // Изменяем значение через ссылку
    value = 10; 
    // Проверяем, что значение изменилось через итератор
    assert(*it == 10); 

    std::cout << "Тест на разыменование пройден" << std::endl;
}

void Test_inc() {
    LinkedList<int> list;
    list.insertHead(3);
    list.insertHead(2);
    list.insertHead(1);

    // Получаем итератор на первый элемент списка
    LinkedList<int>::Iterator<int> it = list.begin();

    // Проверяем начальное значение итератора
    assert(*it == 1);

    // Инкрементируем итератор
    ++it;

    // Проверяем значение после инкремента
    assert(*it == 2);

    // Инкрементируем итератор еще раз
    ++it;

    // Проверяем значение после второго инкремента
    assert(*it == 3);

    // Инкрементируем итератор, чтобы он вышел за границы списка
    ++it;

    // Проверяем, что итератор указывает на конец списка
    assert(it == list.end());

    std::cout << "Тест на инкремент пройден" << std::endl;

}


void Test_post() {
    LinkedList<int> list;
    list.insertHead(3);
    list.insertHead(2);
    list.insertHead(1);

    LinkedList<int>::Iterator<int> it = list.begin();
    int& value = *it;

    assert(value == 1);

    // Постфиксный инкремент
    LinkedList<int>::Iterator<int> temp = it;
    it++;
    // Проверяем, что значение временного итератора равно 1
    assert(*temp == 1); 
    // Проверяем, что значение основного итератора увеличилось до 2
    assert(*it == 2); 

    std::cout << "Тест на постфиксный инкремент пройден" << std::endl;
}


void testIteratorEquality() {
    LinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    LinkedList<int>::Iterator<int> it1 = list.begin();
    LinkedList<int>::Iterator<int> it2 = list.begin();
    LinkedList<int>::Iterator<int> it3 = list.end();

    // Проверка равенства итераторов, указывающих на один и тот же элемент
    assert(it1 == it2);

    // Проверка неравенства итераторов, указывающих на разные элементы
    assert(it1 != it3);

    // Создание другого списка и итератора, указывающего на его элемент
    LinkedList<int> otherList;
    otherList.insert(1);
    LinkedList<int>::Iterator<int> otherIt = otherList.begin();

    // Проверка неравенства итераторов из разных списков
    assert(it1 != otherIt);

    std::cout << "Тест на равенство пройден" << std::endl;
}


void testIteratorEquality1() {
    LinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    // Создание двух итераторов
    LinkedList<int>::Iterator<int> it1 = list.begin();
    LinkedList<int>::Iterator<int> it2 = list.end();

    // Проверка неравенства итераторов с использованием оператора !=
    assert(it1 != it2);

    std::cout << "Тест на неравенство пройден" << std::endl;

}
