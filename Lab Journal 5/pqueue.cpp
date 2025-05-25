// Exercise 5.1

#include "priority_queue.h"
#include <iostream>
using namespace std;

template <typename ElementType>
PriorityQueue<ElementType>::PriorityQueue() {

}

template <typename ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    for (int index = 0; index < 10; index++) {
        if (!queue[index].isEmpty())
            return false;
    }
    return true;
}

template <typename ElementType>
void PriorityQueue<ElementType>::insert(ElementType newElement, int priorityLevel) {
    if (priorityLevel < 0 || priorityLevel >= 10) {
        cout << "Invalid priority level!" << endl;
        return;
    }
    queue[priorityLevel].insert(newElement);
}

template <typename ElementType>
void PriorityQueue<ElementType>::remove(ElementType& element) {
    for (int index = 0; index < 10; index++) {
        if (!queue[index].isEmpty()) {
            queue[index].remove(element);
            return;
        }
    }
    cout << "Priority queue underflow!" << endl;
}

template class PriorityQueue<int>;

// Exercise 5.2

#include "priority_queue.h"
#include <iostream>
using namespace std;

template <typename ElementType>
PriorityQueue<ElementType>::PriorityQueue(int numLevels) {
    levels = numLevels;
    queueArray = new queue<ElementType>[levels];
}

template <typename ElementType>
PriorityQueue<ElementType>::~PriorityQueue() {
    delete[] queueArray;
}

template <typename ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    for (int index = 0; index < levels; index++) {
        if (!queueArray[index].isEmpty())
            return false;
    }
    return true;
}

template <typename ElementType>
void PriorityQueue<ElementType>::insert(ElementType newItem, int priorityLevel) {
    if (priorityLevel < 0 || priorityLevel >= levels) {
        cout << "Invalid priority level!" << endl;
        return;
    }
    queueArray[priorityLevel].insert(newItem);
}

template <typename ElementType>
void PriorityQueue<ElementType>::remove(ElementType& item) {
    for (int index = 0; index < levels; index++) {
        if (!queueArray[index].isEmpty()) {
            queueArray[index].remove(item);
            return;
        }
    }
    cout << "Priority queue underflow!" << endl;
}