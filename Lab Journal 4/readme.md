This project explores several ways to implement queues in C++, based on examples and exercises from Chapter 4 of a typical Data Structures course. It covers static queues, template-based dynamic queues, and double-ended queues (deques), each designed to demonstrate different features and use cases of the queue data structure.

**Example 4.1** introduces a basic static queue using arrays. It includes simple operations like inserting and removing elements, as well as checks for whether the queue is full or empty. **Exercise 4.1** takes this a step further by using an array of queues to handle multiple sets of user inputs—highlighting how the queue class can be reused in different contexts.

**Example 4.2** brings in the power of templates by creating a dynamic queue that works with any data type. This version supports all the standard queue operations. In **Exercise 4.2**, this templated queue is used to store and manage friends’ names, showing how templates make the code more flexible and reusable.

**Exercise 4.3** focuses on building a double-ended queue (deque) using a circular array. It supports inserting and removing items from both the front and back, using modular arithmetic to handle the circular nature of the queue. This implementation adds a layer of complexity and extends beyond the typical queue behavior.

**Exercise 4.4** applies this concept to a real-world task: checking if a string is a palindrome. By adding characters from both ends and comparing them while removing from both ends, this example blends logical thinking with queue operations, demonstrating a practical use of deques.

Together, these examples offer a solid foundation in understanding queues—from basic implementations to more flexible and advanced structures. They emphasize key concepts like index tracking, circular arrays, and code generalization through templates—all essential for mastering data structures.
