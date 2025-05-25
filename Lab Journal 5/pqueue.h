// Exercise 5.1

#pragma once
#include "queue.h"

template <typename ElementType>
class PriorityQueue {
private:
    queue<ElementType> elements[10];

public:
    PriorityQueue();
    bool isEmpty() const;
    bool isFull();
    void insert(ElementType newItem, int priority);
    void remove(ElementType& item);
};

// Exercise 5.2

#pragma once
#include "queue.h"
#include <iostream>
using namespace std;

template <typename ItemType>
class PriorityQueue {
private:
    queue<ItemType>* QueueArray;
    int PriorityLevels;

public:
    PriorityQueue(int Size);
    ~PriorityQueue();
    bool IsEmpty() const;
    void Insert(ItemType NewItem, int Priority);
    void Remove(ItemType& Item);
};
