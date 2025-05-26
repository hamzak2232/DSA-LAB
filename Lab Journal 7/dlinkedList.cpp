// Example 7.1

#include <iostream>
using namespace std;
// Defining a structure for the list elements
struct ListElement {
    int value;
    ListElement* forward;
    ListElement* backward;

    // Constructor to initialize new element
    ListElement(int val) : value(val), forward(nullptr), backward(nullptr) {}
};

// Doubly linked sequence class implementation
class BiDirectionalList {
private:
    ListElement* first;
    ListElement* last;

public:
    // Initialize an empty list
    BiDirectionalList() : first(nullptr), last(nullptr) {}

    // Destructor to free memory
    ~BiDirectionalList() {
        while (!empty()) {
            removeFirst();
        }
    }

    // Add element at the end of the list
    void addLast(int val) {
        ListElement* newElement = new ListElement(val);

        if (last) {
            // Connect the new element to the current last element
            last->forward = newElement;
            newElement->backward = last;
            last = newElement;
        } else {
            // First element in the list
            first = last = newElement;
        }
    }

    // Add element at the beginning of the list
    void addFirst(int val) {
        ListElement* newElement = new ListElement(val);

        if (first) {
            // Connect the new element to the current first element
            first->backward = newElement;
            newElement->forward = first;
            first = newElement;
        } else {
            // First element in the list
            first = last = newElement;
        }
    }

    // Remove and return the last element
    int removeLast() {
        if (empty()) {
            std::cout << "Cannot remove from an empty list!" << std::endl;
            return -1;
        }

        int removedValue = last->value;
        ListElement* temp = last;

        if (first == last) {
            // Only one element in the list
            first = last = nullptr;
        } else {
            // Update the last pointer
            last = last->backward;
            last->forward = nullptr;
        }

        delete temp;
        return removedValue;
    }

    // Remove and return the first element
    int removeFirst() {
        if (empty()) {
            std::cout << "Cannot remove from an empty list!" << std::endl;
            return -1;
        }

        int removedValue = first->value;
        ListElement* temp = first;

        if (first == last) {
            // Only one element in the list
            first = last = nullptr;
        } else {
            // Update the first pointer
            first = first->forward;
            first->backward = nullptr;
        }

        delete temp;
        return removedValue;
    }

    // Check if list is empty
    bool empty() const {
        return first == nullptr;
    }
};

int main() {
    // Sample array of integers
    int numbers[] = {14, 23, 37, 48, 59};
    BiDirectionalList myList;

    // Add elements from the array to the list
    for (int i = 0; i < 5; i++) {
        myList.addLast(numbers[i]);
    }

    // Add more elements
    myList.addLast(62);
    myList.addFirst(7);

    // Display elements by removing from the end
    std::cout << "Elements removed from end: ";
    while (!myList.empty()) {
        std::cout << myList.removeLast() << " ";
    }
    std::cout << std::endl;

    return 0;
}

// Exercise 7.1

#include <iostream>
using namespace std;

class Node {
public:
    long long data;
    Node* prev;
    Node* next;

    Node(long long val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Destructor to free memory
    ~DoubleLinkedList() {
        while (!isEmpty()) {
            popFront();
        }
    }

    void pushBack(long long value) {
        Node* newNode = new Node(value);
        newNode->prev = tail;
        if (tail != NULL)
            tail->next = newNode;
        tail = newNode;
        if (head == NULL)
            head = newNode;
    }

    void pushFront(long long value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        if (tail == NULL)
            tail = newNode;
    }

    long long popFront() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return -1;
        }
        long long val = head->data;
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
        delete temp;
        return val;
    }

    long long popBack() {
        if (tail == NULL) {
            cout << "List is empty!" << endl;
            return -1;
        }
        long long val = tail->data;
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;
        delete temp;
        return val;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    long long arr[] = { 1000000000001, 2000000000002, 3000000000003, 4000000000004 };
    DoubleLinkedList dlist;

    for (int i = 0; i < 4; i++) {
        dlist.pushBack(arr[i]);
    }

    dlist.pushBack(5000000000005);
    dlist.pushFront(9999999999999);

    cout << "List after insertions: ";
    while (!dlist.isEmpty()) {
        cout << dlist.popFront() << " ";
    }
    cout << endl;

    return 0;
}


// Add more elements
myList.addLast(62);
myList.addFirst(7);

// Display elements by removing from the end
std::cout << "Elements removed from end: ";
while (!myList.empty()) {
std::cout << myList.removeLast() << " ";
}
std::cout << std::endl;

return 0;
}