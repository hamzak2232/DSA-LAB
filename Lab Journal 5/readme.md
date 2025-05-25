This project explores the implementation of Priority Queues through two hands-on exercises. These exercises demonstrate how elements can be managed and processed based on their assigned priority levels — ensuring higher-priority items are always handled first.

Exercises
Exercise 5.1: Static Priority Queue
In this exercise, a priority queue with a fixed number of 10 levels (from 0 to 9) is implemented. The user inputs elements along with their priority levels, and the system ensures that elements with higher priorities are removed first.

Key Highlights:

Supports 10 predefined priority levels (0–9).

Elements are dequeued in order, starting from the highest priority.

The queue size and levels are fixed (static).

Exercise 5.2: Dynamic Priority Queue
This exercise builds on the static version by allowing users to define the number of priority levels at runtime. A dynamic array of queues is used to adapt to different scenarios where the number of priorities isn't known in advance.

Key Highlights:

User-defined number of priority levels.

Uses a dynamic array of queues for flexible memory management.

Elements are still removed in descending priority order.

Core Classes and Functionality
pque Class (Priority Queue)
Handles both static and dynamic implementations of the priority queue.

Main Methods:

Constructor: Initializes the priority queue with a fixed or user-defined number of levels.

isempty(): Checks if all priority levels are empty.

insert(): Adds an item to the queue based on its priority.

remove(): Removes the item with the highest priority available.

queue Class (Standard Queue)
A general-purpose queue used as the building block for each priority level in the priority queue.

Main Methods:

Constructor: Sets up the queue with a maximum size.

isempty(): Checks if the queue is empty.

isfull(): Checks if the queue is full.

insert(): Enqueues an item.

remove(): Dequeues an item.

How to Compile and Run
Make sure all source files (pque.cpp, queue.cpp, pque.h, and queue.h) are in the same directory.

Use a C++ compiler (like g++ or clang++) to compile the code.

Run the resulting executable and follow the prompts to enter elements and their priorities.

Sample Program Behavior
Exercise 5.1 (Static):

Prompts the user to input 10 elements along with their priority (0–9).

Displays the elements as they’re removed, starting with the highest-priority entries.

Exercise 5.2 (Dynamic):

Asks the user to specify how many priority levels to use.

Collects element-priority pairs and removes them in proper priority order.