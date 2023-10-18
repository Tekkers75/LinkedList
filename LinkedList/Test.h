// @author �������� �.�.
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
    // �������� ������ �� �������� ����� ��������
    int& value = *it; 
    
    // ���������, ��� �������� ����� 1
    assert(value == 1); 
    
    // �������� �������� ����� ������
    value = 10; 
    // ���������, ��� �������� ���������� ����� ��������
    assert(*it == 10); 

    std::cout << "���� �� ������������� �������" << std::endl;
}

void Test_inc() {
    LinkedList<int> list;
    list.insertHead(3);
    list.insertHead(2);
    list.insertHead(1);

    // �������� �������� �� ������ ������� ������
    LinkedList<int>::Iterator<int> it = list.begin();

    // ��������� ��������� �������� ���������
    assert(*it == 1);

    // �������������� ��������
    ++it;

    // ��������� �������� ����� ����������
    assert(*it == 2);

    // �������������� �������� ��� ���
    ++it;

    // ��������� �������� ����� ������� ����������
    assert(*it == 3);

    // �������������� ��������, ����� �� ����� �� ������� ������
    ++it;

    // ���������, ��� �������� ��������� �� ����� ������
    assert(it == list.end());

    std::cout << "���� �� ��������� �������" << std::endl;

}


void Test_post() {
    LinkedList<int> list;
    list.insertHead(3);
    list.insertHead(2);
    list.insertHead(1);

    LinkedList<int>::Iterator<int> it = list.begin();
    int& value = *it;

    assert(value == 1);

    // ����������� ���������
    LinkedList<int>::Iterator<int> temp = it;
    it++;
    // ���������, ��� �������� ���������� ��������� ����� 1
    assert(*temp == 1); 
    // ���������, ��� �������� ��������� ��������� ����������� �� 2
    assert(*it == 2); 

    std::cout << "���� �� ����������� ��������� �������" << std::endl;
}


void testIteratorEquality() {
    LinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    LinkedList<int>::Iterator<int> it1 = list.begin();
    LinkedList<int>::Iterator<int> it2 = list.begin();
    LinkedList<int>::Iterator<int> it3 = list.end();

    // �������� ��������� ����������, ����������� �� ���� � ��� �� �������
    assert(it1 == it2);

    // �������� ����������� ����������, ����������� �� ������ ��������
    assert(it1 != it3);

    // �������� ������� ������ � ���������, ������������ �� ��� �������
    LinkedList<int> otherList;
    otherList.insert(1);
    LinkedList<int>::Iterator<int> otherIt = otherList.begin();

    // �������� ����������� ���������� �� ������ �������
    assert(it1 != otherIt);

    std::cout << "���� �� ��������� �������" << std::endl;
}


void testIteratorEquality1() {
    LinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    // �������� ���� ����������
    LinkedList<int>::Iterator<int> it1 = list.begin();
    LinkedList<int>::Iterator<int> it2 = list.end();

    // �������� ����������� ���������� � �������������� ��������� !=
    assert(it1 != it2);

    std::cout << "���� �� ����������� �������" << std::endl;

}
