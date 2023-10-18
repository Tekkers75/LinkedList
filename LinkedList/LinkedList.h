// @author Саранчин К.А.
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

    void insert(const T& data) {
        Node<T>* newNode = new Node<T>(data);
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


    void insertAfter(int DataAfter, const T& data) {
        Node<T>* newNode = new Node<T>(data);
        Node<T>* current = head;

        while (current != nullptr) {
            if (current->data == DataAfter) {
                if (current == tail) {
                    tail = newNode;  // Обновляем хвост списка, если вставляем после хвостового узла
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
            // Выводим данные текущего узла
            std::cout << current->data << " ";
            // Переходим к следующему узлу
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node<T>* search(const T& data) {
        Node<T>* current = head;
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

    void remove(const T& data) {
        Node<T>* current = head;
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
                // Обмен значениями узлов
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
            // Возвращает ссылку на данные текущего узла
            return current->data;
        }

        AbstractIterator<T>& operator++() override {
            // Переход к следующему узлу
            current = current->next;
            return *this;
        }

        AbstractIterator<T>& operator++(int) override {
            // Постфиксный инкремент (a++)
            Iterator<T> temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const AbstractIterator<T>& other) override {
            // Сравнение итераторов на равенство
            const Iterator* otherIterator = dynamic_cast<const Iterator*>(&other);
            return current == otherIterator->current;
        }

        bool operator!=(const AbstractIterator<T>& other) override {
            // Сравнение итераторов на неравенство
            return !(*this == other);
        }
    };

    Iterator<T> begin() {
        // Возвращает итератор, указывающий на начало списка
        return Iterator<T>(head);
    }

    Iterator<T> end() {
        // Возвращает итератор, указывающий на конец списка (nullptr)
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


    ///не понимаю
    //Iterator begin() {
    //    return Iterator(head);
    //}

    //Iterator end() {
    //    return Iterator(nullptr);
    //}
};

   

   

