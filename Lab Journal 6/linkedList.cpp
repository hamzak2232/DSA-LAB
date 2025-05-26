// 6.1

#include <iostream>
using namespace std;

template<class ItemType>
class CustomList {
protected:
    struct Node {
        ItemType data;
        Node* next;
    };

    using NodePtr = Node*;
    NodePtr head;

public:
    CustomList();
    ~CustomList();
    bool isEmpty() const;
    void push(const ItemType& value);
    ItemType pop();
    void insertAfter(const ItemType& target, const ItemType& newVal);
    void deleteItem(const ItemType& target);
    void display() const;
};

template<class ItemType>
CustomList<ItemType>::CustomList() {
    head = nullptr;
}

template<class ItemType>
CustomList<ItemType>::~CustomList() {
    NodePtr current = head, temp;
    while (current != nullptr) {
        temp = current->next;
        delete current;
        current = temp;
    }
}

template<class ItemType>
bool CustomList<ItemType>::isEmpty() const {
    return head == nullptr;
}

template<class ItemType>
void CustomList<ItemType>::push(const ItemType& value) {
    NodePtr newNode = new Node{value, head};
    head = newNode;
}

template<class ItemType>
ItemType CustomList<ItemType>::pop() {
    if (isEmpty()) {
        cerr << "Error: The list is empty!\n";
        exit(1);
    }
    NodePtr temp = head;
    ItemType value = temp->data;
    head = head->next;
    delete temp;
    return value;
}

template<class ItemType>
void CustomList<ItemType>::insertAfter(const ItemType& target, const ItemType& newVal) {
    NodePtr temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Value " << target << " not found.\n";
        return;
    }

    NodePtr newNode = new Node{newVal, temp->next};
    temp->next = newNode;
}

template<class ItemType>
void CustomList<ItemType>::deleteItem(const ItemType& target) {
    NodePtr current = head, prev = nullptr;

    while (current != nullptr && current->data != target) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Value " << target << " not found.\n";
        return;
    }

    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
}

template<class ItemType>
void CustomList<ItemType>::display() const {
    NodePtr current = head;
    cout << "List contents: ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    CustomList<int> myList;

    cout << "Adding elements to the list..." << endl;
    myList.push(50);
    myList.push(40);
    myList.push(30);
    myList.display();

    cout << "Inserting 45 after 40..." << endl;
    myList.insertAfter(40, 45);
    myList.display();

    cout << "Deleting 30..." << endl;
    myList.deleteItem(30);
    myList.display();

    cout << "Popping an element: " << myList.pop() << endl;
    myList.display();

    return 0;
}

// 6.2

#include <iostream>
using namespace std;

template<class ItemType>
class CustomList {
protected:
    struct Node {
        ItemType data;
        Node* next;
    };

    typedef Node* NodePtr;
    NodePtr head;

public:
    CustomList();
    ~CustomList();
    bool isEmpty();
    void push(ItemType value);
    ItemType pop();
    void insertAfter(ItemType target, ItemType newVal);
    void deleteItem(ItemType target);
};

template<class ItemType>
CustomList<ItemType>::CustomList() {
    head = nullptr;
}

template<class ItemType>
CustomList<ItemType>::~CustomList() {
    NodePtr current = head, temp;
    while (current != nullptr) {
        temp = current->next;
        delete current;
        current = temp;
    }
}

template<class ItemType>
bool CustomList<ItemType>::isEmpty() {
    return head == nullptr;
}

template<class ItemType>
void CustomList<ItemType>::push(ItemType value) {
    NodePtr newNode = new Node{value, head};
    head = newNode;
}

template<class ItemType>
ItemType CustomList<ItemType>::pop() {
    if (isEmpty()) {
        cout << "Error: The list is empty!\n";
        exit(1);
    }
    NodePtr temp = head;
    ItemType value = temp->data;
    head = head->next;
    delete temp;
    return value;
}

template<class ItemType>
void CustomList<ItemType>::insertAfter(ItemType target, ItemType newVal) {
    NodePtr temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Value " << target << " not found.\n";
        return;
    }

    NodePtr newNode = new Node{newVal, temp->next};
    temp->next = newNode;
}

template<class ItemType>
void CustomList<ItemType>::deleteItem(ItemType target) {
    NodePtr current = head, prev = nullptr;

    while (current != nullptr && current->data != target) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Value " << target << " not found.\n";
        return;
    }

    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
}

int main() {
    CustomList<int> myList;

    myList.push(50);
    myList.push(40);
    myList.push(30);

    myList.insertAfter(40, 45);
    myList.deleteItem(30);

    cout << "Popped element: " << myList.pop() << endl;

    return 0;
}

// 6.3

#include <iostream>
using namespace std;

class LinkedStructure {
    struct Node {
        int value;
        Node* next;
        Node(int v, Node* n = nullptr) : value(v), next(n) {}
    };

    Node* head;

public:
    LinkedStructure() : head(nullptr) {}

    ~LinkedStructure() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void createList(int length) {
        if (length <= 0) return;
        cout << "Enter " << length << " integers: ";
        for (int i = 0; i < length; i++) {
            int val;
            cin >> val;
            head = new Node(val, head); // inserting at head
        }
    }

    void showList() const {
        Node* temp = head;
        if (!temp) {
            cout << "The list is currently empty.\n";
            return;
        }
        cout << "Linked List: ";
        while (temp) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void removeFirst() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void removeLast() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void remove(int val) {
        if (!head) return;
        if (head->value == val) {
            removeFirst();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->value != val)
            temp = temp->next;
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
    }
};

int main() {
    LinkedStructure ls;
    ls.createList(5);
    ls.showList();

    ls.removeFirst();
    cout << "After removing the first node: ";
    ls.showList();

    ls.removeLast();
    cout << "After removing the last node: ";
    ls.showList();

    ls.remove(3);
    cout << "After removing node with value 3: ";
    ls.showList();

    return 0;
}
