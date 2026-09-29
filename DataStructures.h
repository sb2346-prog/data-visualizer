#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include "DoublyLinkedList.h"

template <typename T>
class Stack {
private:
    DoublyLinkedList<T> list;
public:
    void push(T val) { list.insertBack(val); }
    T pop() { return list.deleteBack(); }
    T top() const { return list.getBack(); }
    bool isEmpty() const { return list.isEmpty(); }
};

template <typename T>
class Queue {
private:
    DoublyLinkedList<T> list;
public:
    void enqueue(T val) { list.insertBack(val); }
    T dequeue() { return list.deleteFront(); }
    T front() const { return list.getFront(); }
    bool isEmpty() const { return list.isEmpty(); }
};

#endif


