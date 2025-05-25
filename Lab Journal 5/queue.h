// Exercise 5.1

#include "queue.h"
#include <iostream>
using namespace std;

template <typename ElementType>
Queue<ElementType>::Queue(int capacity) {
    maxCapacity = capacity;
    frontIndex = 0;
    rearIndex = 0;
    itemCount = 0;
    elements = new ElementType[maxCapacity];
}

template <typename ElementType>
Queue<ElementType>::~Queue() {
    delete[] elements;
}

template <typename ElementType>
bool Queue<ElementType>::isEmpty() const {
    return itemCount == 0;
}

template <typename ElementType>
bool Queue<ElementType>::isFull() const {
    return itemCount == maxCapacity;
}

template <typename ElementType>
void Queue<ElementType>::enqueue(ElementType newElement) {
    if (isFull()) {
        cout << "Queue overflow!" << endl;
        exit(1);
    } else {
        elements[rearIndex] = newElement;
        rearIndex = (rearIndex + 1) % maxCapacity;
        ++itemCount;
    }
}

template <typename ElementType>
void Queue<ElementType>::dequeue(ElementType& element) {
    if (isEmpty()) {
        cout << "Queue underflow!" << endl;
        exit(1);
    } else {
        element = elements[frontIndex];
        frontIndex = (frontIndex + 1) % maxCapacity;
        --itemCount;
    }
}

template class Queue<int>;

// Exercise 5.2

#include "queue.h"
#include <iostream>
using namespace std;

template <typename ElementType>
Queue<ElementType>::Queue(int capacity) {
    maxCapacity = capacity;
    frontIndex = 0;
    rearIndex = 0;
    itemCount = 0;
    elements = new ElementType[maxCapacity];
}

template <typename ElementType>
Queue<ElementType>::~Queue() {
    delete[] elements;
}

template <typename ElementType>
bool Queue<ElementType>::isEmpty() const {
    return itemCount == 0;
}