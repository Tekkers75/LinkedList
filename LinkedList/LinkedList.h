// @author �������� �.�.
#pragma once
#include <iostream>
#include "Iterator.h"

template<typename T>
class Node{
public:
    T data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};





template<typename T>
class LinkedList /*: public AbstractIterated<T>*/ {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertHead(const T& data) {
        Node<T>* newNode = new Node<T>(data);
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

    void insert(const T& data) {
        Node<T>* newNode = new Node<T>(data);
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


    void insertAfter(int DataAfter, const T& data) {
        Node<T>* newNode = new Node<T>(data);
        Node<T>* current = head;

        while (current != nullptr) {
            if (current->data == DataAfter) {
                if (current == tail) {
                    tail = newNode;  // ��������� ����� ������, ���� ��������� ����� ���������� ����
                }
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
        }
    }

    void print() {
        Node<T>* current = head;
        while (current != nullptr) {
            // ������� ������ �������� ����
            std::cout << current->data << " ";
            // ��������� � ���������� ����
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node<T>* search(const T& data) {
        Node<T>* current = head;
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

    void remove(const T& data) {
        Node<T>* current = head;
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
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* minNode = current;
            Node<T>* temp = current->next;
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




    template<typename T>
    class Iterator : public AbstractIterator<T> {
    private:
        Node<T>* current;

    public:
        Iterator(Node<T>* node) {
            current = node;
        }

        T& operator*() override {
            // ���������� ������ �� ������ �������� ����
            return current->data;
        }

        AbstractIterator<T>& operator++() override {
            // ������� � ���������� ����
            current = current->next;
            return *this;
        }

        AbstractIterator<T>& operator++(int) override {
            // ����������� ��������� (a++)
            Iterator<T> temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const AbstractIterator<T>& other) override {
            // ��������� ���������� �� ���������
            const Iterator* otherIterator = dynamic_cast<const Iterator*>(&other);
            return current == otherIterator->current;
        }

        bool operator!=(const AbstractIterator<T>& other) override {
            // ��������� ���������� �� �����������
            return !(*this == other);
        }
    };

    Iterator<T> begin() {
        // ���������� ��������, ����������� �� ������ ������
        return Iterator<T>(head);
    }

    Iterator<T> end() {
        // ���������� ��������, ����������� �� ����� ������ (nullptr)
        return Iterator<T>(nullptr);
    }


   /* class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator(Node<T>* node) {
            current = node;
        }

        int& operator*() {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& other) {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) {
            return current != other.current;
        }
    };*/




    //AbstractIterator<T>& begin() const override {
    //    return Iterator(head);
    //}

    //AbstractIterator<T>& end() const override {
    //    return Iterator<T>(nullptr);
    //}


    ///�� �������
    //Iterator begin() {
    //    return Iterator(head);
    //}

    //Iterator end() {
    //    return Iterator(nullptr);
    //}
};

   

   

