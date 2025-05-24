// Example and EXERCISE 4.1

#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue info;
    info.insert(20);
    info.insert(40);
    info.insert(60);

    Queue info2[10];
    int value;

    for (int i = 0; i < 10; i++) {
        cout << "Insert number at index " << i << ": ";
        cin >> value;
        info2[i].insert(value);
    }

    cout << endl;
    for (int i = 0; i < 10; i++) {
        while (!info2[i].isempty()) {
            int rem = info2[i].remove();
            cout << "Removed number from index " << i << ": " << rem << endl;
        }
    }

    cout << endl;
    while (!info.isempty()) {
        int rem = info.remove();
        cout << rem << endl;
    }

    return 0;
}

// Example 4.2

#include <iostream>
#include "queue.cpp"

using namespace std;

int main() {
    queue<int> data[10];
    int inputNumber;

    for (int index = 0; index < 10; index++) {
        cout << "Enter number at index " << index << ": ";
        cin >> inputNumber;
        data[index].insert(inputNumber);
    }

    int removedNumber;
    cout << endl;
    for (int index = 0; index < 10; index++) {
        while (!data[index].isempty()) {
            data[index].remove(removedNumber);
            cout << "Removed number from index " << index << ": " << removedNumber << endl;
        }
    }

    cout << endl;
    return 0;
}

// Exercise 4.2

#include <iostream>
#include "queue.cpp"

using namespace std;

int main() {
    queue<string> FriendList[10];
    string FriendName;

    for (int Index = 0; Index < 10; Index++) {
        cout << "Enter name of friend " << Index << ": ";
        cin >> FriendName;
        FriendList[Index].insert(FriendName);
    }

    string RemovedName;
    cout << endl;
    for (int Index = 0; Index < 10; Index++) {
        while (!FriendList[Index].isempty()) {
            FriendList[Index].remove(RemovedName);
            cout << "Removed name from index " << Index << ": " << RemovedName << endl;
        }
    }

    cout << endl;
    return 0;
}

// Exercise 4.3

#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    queue myQueue;
    myQueue.pushback(100);
    myQueue.pushback(20);
    myQueue.pushback(30);
    myQueue.pushback(40);
    myQueue.pushback(50);

    int element;
    for (int index = 0; index < 6; index++) {  // One more pop than pushes to test behavior
        if (myQueue.popfront(element)) {
            cout << "Popped: " << element << endl;
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    return 0;
}

// EXERCISE 4.4

#include <iostream>
#include "queue.h"

using namespace std;

bool isPalindrome(string inputStr) {
    queue characterQueue;
    for (char character : inputStr) {
        characterQueue.pushright(character);
    }

    for (char character : inputStr) {
        if (characterQueue.popright() != characterQueue.popleft()) {
            return false;
        }
    }

    return true;
}

int main() {
    string userInput;
    cout << "Enter a string: ";
    cin >> userInput;

    if (isPalindrome(userInput)) {
        cout << userInput << " is a palindrome";
    } else {
        cout << userInput << " is not a palindrome";
    }

    return 0;
}
