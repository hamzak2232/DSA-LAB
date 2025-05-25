// Exercise 5.1

#include <iostream>
#include "pque.cpp"
using namespace std;

int main() {
    pque<int> priorityQueue;

    int element, priority;
    for (int index = 0; index < 10; index++) {
        cout << "Enter element at index " << index << ": ";
        cin >> element;
        cout << "Enter priority (0-9): ";
        cin >> priority;
        priorityQueue.insert(element, priority);
    }

    int removedElement;
    cout << "\nRemoving elements based on priority:\n";
    while (!priorityQueue.isempty()) {
        priorityQueue.remove(removedElement);
        cout << "Removed: " << removedElement << endl;
    }

    return 0;
}

// Exercise 5.2

#include "priority_queue.cpp"
#include <iostream>
using namespace std;

int main() {
    int numLevels;
    cout << "Enter the number of priority levels: ";
    cin >> numLevels;

    pque<int> priorityQueue(numLevels);
    int element, priority;

    for (int index = 0; index < 10; index++) {
        cout << "Enter element at index " << index << ": ";
        cin >> element;
        cout << "Enter priority (0-" << numLevels - 1 << "): ";
        cin >> priority;
        priorityQueue.insert(element, priority);
    }

    int removedElement;
    cout << "\nRemoving elements based on priority:\n";
    while (!priorityQueue.isempty()) {
        priorityQueue.remove(removedElement);
        cout << "Removed: " << removedElement << endl;
    }

    return 0;
}
