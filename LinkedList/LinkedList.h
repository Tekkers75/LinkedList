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
        // Если список пустой, новый узел становится головным и хвостовым
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
        // Если список пустой, новый узел становится головным и хвостовым
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            // Привязываем новый узел к текущему хвосту
            tail->next = newNode;
            // Устанавливаем ссылку на предыдущий узел
            newNode->prev = tail;
            // Новый узел становится новым хвостом
            tail = newNode;
        }
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            // Выводим данные текущего узла
            std::cout << current->data << " ";
            // Переходим к следующему узлу
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node* search(int data) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                // Возвращаем узел, если найден элемент
                return current;  
            }
            current = current->next;
        }
        // Если элемент не найден, возвращаем nullptr
        return nullptr; 
    }

    void remove(int data) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                if (current == head) {
                    // Обновляем голову списка, если удаляемый элемент - головной узел
                    head = current->next;  
                }
                if (current == tail) {
                    // Обновляем хвост списка, если удаляемый элемент - хвостовой узел
                    tail = current->prev;  
                }
                if (current->prev != nullptr) {
                    // Обновляем ссылку на следующий узел для предыдущего узла
                    current->prev->next = current->next;  
                }
                if (current->next != nullptr) {
                    // Обновляем ссылку на предыдущий узел для следующего узла
                    current->next->prev = current->prev;  
                }
                // Удаляем узел
                delete current;  
                return;
            }
            current = current->next;
        }
    }

    // Сортировка выбором
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
                // Обмен значениями узлов
                int tempData = current->data;
                current->data = minNode->data;
                minNode->data = tempData;
            }
            current = current->next;
        }
    }

};

