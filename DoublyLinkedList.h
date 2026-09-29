#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
    Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insertBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!tail) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void insertFront(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    T deleteBack() {
        if (!tail) throw std::runtime_error("List is empty");
        T data = tail->data;
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        return data;
    }
    T deleteFront() {
        if (!head) throw std::runtime_error("List is empty");
        T data = head->data;
        Node<T>* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        return data;
    }
    bool isEmpty() const { return head == nullptr; }
    T getBack() const { if (!tail) throw std::runtime_error("List is empty"); return tail->data; }
    T getFront() const { if (!head) throw std::runtime_error("List is empty"); return head->data; }
    Node<T>* getHead() const { return head; }
};

#endif

