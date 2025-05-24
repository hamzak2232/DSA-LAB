// Example 4.1 and Exercise 4.1

#pragma once
#include <iostream>
using namespace std;
#define MAX_QUEUE_SIZE 100
typedef int ElementType;

class CircularQueue {
private:
    int Head, Tail, Size;
    ElementType Elements[MAX_QUEUE_SIZE];

public:
    queue();
    int IsEmpty();
    int IsFull();
    void Enqueue(ElementType NewElement);
    ElementType Dequeue();
};

// Example 4.2

template <typename itemtype>
class queue {
    int front, rear, maxqueue, count;
    itemtype* items;
public:
    queue();
    queue(int m);
    int isempty();
    int isfull();
    void insert(itemtype newitem);
    void remove(itemtype& item);
};

// Exercise 4.2

template <typename ElementType>
class queue {
    int Head, Tail, MaxSize, CurrentCount;
    ElementType* Elements;
public:
    queue();
    queue(int size);
    int IsEmpty();
    int IsFull();
    void Enqueue(ElementType newElement);
    void Dequeue(ElementType &element);
};

// Exercise 4.3

const int MaxSize = 5;
class queue {
    int Head, Tail;
    int Elements[MaxSize];
public:
    queue();
    void EnqueueBack(int value);
    void EnqueueFront(int value);
    bool IsFull();
    void DequeueFront(int& output);
    void DequeueBack(int& output);
    bool IsEmpty();
};

// Exercise 4.4

const int maxi = 5;
class queue {
    int front, rear;
    char arr[maxi];
public:
    queue();
    void pushright(char x);
    void pushleft(char x);
    bool isfull();
    char popleft();
    char popright();
    bool isempty();
};
