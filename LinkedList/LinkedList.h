#pragma once
#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};


class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertHead(int data) {
        Node* newNode = new Node(data);
        // ���� ������ ������, ����� ���� ���������� �������� � ���������
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
            
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        // ���� ������ ������, ����� ���� ���������� �������� � ���������
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            // ����������� ����� ���� � �������� ������
            tail->next = newNode;
            // ������������� ������ �� ���������� ����
            newNode->prev = tail;
            // ����� ���� ���������� ����� �������
            tail = newNode;
        }
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            // ������� ������ �������� ����
            std::cout << current->data << " ";
            // ��������� � ���������� ����
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node* search(int data) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                // ���������� ����, ���� ������ �������
                return current;  
            }
            current = current->next;
        }
        // ���� ������� �� ������, ���������� nullptr
        return nullptr; 
    }

    void remove(int data) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                if (current == head) {
                    // ��������� ������ ������, ���� ��������� ������� - �������� ����
                    head = current->next;  
                }
                if (current == tail) {
                    // ��������� ����� ������, ���� ��������� ������� - ��������� ����
                    tail = current->prev;  
                }
                if (current->prev != nullptr) {
                    // ��������� ������ �� ��������� ���� ��� ����������� ����
                    current->prev->next = current->next;  
                }
                if (current->next != nullptr) {
                    // ��������� ������ �� ���������� ���� ��� ���������� ����
                    current->next->prev = current->prev;  
                }
                // ������� ����
                delete current;  
                return;
            }
            current = current->next;
        }
    }

    // ���������� �������
    void sort() {
        Node* current = head;
        while (current != nullptr) {
            Node* minNode = current;
            Node* temp = current->next;
            while (temp != nullptr) {
                if (temp->data < minNode->data) {
                    minNode = temp;
                }
                temp = temp->next;
            }
            if (minNode != current) {
                // ����� ���������� �����
                int tempData = current->data;
                current->data = minNode->data;
                minNode->data = tempData;
            }
            current = current->next;
        }
    }

};

