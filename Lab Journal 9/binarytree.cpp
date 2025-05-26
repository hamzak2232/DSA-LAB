// Exercise 8.1

#include <iostream>
using namespace std;

#define NUMNODES 100

class BinaryTree {
    struct Node {
        int info;
        int left, right, parent;
        Node() : info(-1), left(-1), right(-1), parent(-1) {}
    };
    Node BT[NUMNODES];

public:
    BinaryTree() {
        for (int i = 0; i < NUMNODES; i++) {
            BT[i] = Node();
        }
    }

    void setRoot(int value) {
        BT[1].info = value;
    }

    void insertLeft(int parentIndex, int value) {
        int leftIndex = 2 * parentIndex;
        if (leftIndex >= NUMNODES) {
            cout << "Error: Left index out of bounds.\n";
            return;
        }
        if (BT[leftIndex].info != -1) {
            cout << "Left child already exists.\n";
            return;
        }
        BT[leftIndex].info = value;
        BT[leftIndex].parent = parentIndex;
        BT[parentIndex].left = leftIndex;
    }

    void insertRight(int parentIndex, int value) {
        int rightIndex = 2 * parentIndex + 1;
        if (rightIndex >= NUMNODES) {
            cout << "Error: Right index out of bounds.\n";
            return;
        }
        if (BT[rightIndex].info != -1) {
            cout << "Right child already exists.\n";
            return;
        }
        BT[rightIndex].info = value;
        BT[rightIndex].parent = parentIndex;
        BT[parentIndex].right = rightIndex;
    }

    void inorder(int index) {
        if (index <= 0 || index >= NUMNODES || BT[index].info == -1) return;
        inorder(BT[index].left);
        cout << BT[index].info << " ";
        inorder(BT[index].right);
    }

    void preorder(int index) {
        if (index <= 0 || index >= NUMNODES || BT[index].info == -1) return;
        cout << BT[index].info << " ";
        preorder(BT[index].left);
        preorder(BT[index].right);
    }

    void postorder(int index) {
        if (index <= 0 || index >= NUMNODES || BT[index].info == -1) return;
        postorder(BT[index].left);
        postorder(BT[index].right);
        cout << BT[index].info << " ";
    }
};

int main() {
    BinaryTree tree;
    tree.setRoot(10);
    tree.insertLeft(1, 20);
    tree.insertRight(1, 30);
    tree.insertLeft(2, 40);
    tree.insertRight(2, 50);
    tree.insertLeft(3, 60);
    tree.insertRight(3, 70);

    cout << "Inorder: ";
    tree.inorder(1);
    cout << "\nPreorder: ";
    tree.preorder(1);
    cout << "\nPostorder: ";
    tree.postorder(1);
    cout << endl;

    return 0;
}

// Exercise 8.2

#include <iostream>
using namespace std;

class BinaryTree {
public:
    struct Treenode {
        int info;
        Treenode* left;
        Treenode* right;
        Treenode* parent;
        Treenode(int val) : info(val), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    typedef Treenode* NODEPTR;

private:
    NODEPTR root;

public:
    BinaryTree() : root(nullptr) {}

    NODEPTR getRoot() {
        return root;
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    NODEPTR makeTree(int x) {
        return new Treenode(x);
    }

    bool isLeft(NODEPTR p) {
        if (isEmpty() || p == nullptr || p->parent == nullptr) return false;
        return (p->parent->left == p);
    }

    bool isRight(NODEPTR p) {
        if (isEmpty() || p == nullptr || p->parent == nullptr) return false;
        return (p->parent->right == p);
    }

    void setRoot(int x) {
        if (!isEmpty()) {
            cout << "Root already exists.\n";
            return;
        }
        root = makeTree(x);
    }

    void setLeft(NODEPTR p, int x) {
        if (p == nullptr) {
            cout << "Cannot insert left child. Parent does not exist.\n";
            return;
        }
        if (p->left != nullptr) {
            cout << "Left child already exists.\n";
            return;
        }
        NODEPTR child = makeTree(x);
        child->parent = p;
        p->left = child;
    }

    void setRight(NODEPTR p, int x) {
        if (p == nullptr) {
            cout << "Cannot insert right child. Parent does not exist.\n";
            return;
        }
        if (p->right != nullptr) {
            cout << "Right child already exists.\n";
            return;
        }
        NODEPTR child = makeTree(x);
        child->parent = p;
        p->right = child;
    }

    void pretrav(NODEPTR p) {
        if (p != nullptr) {
            cout << p->info << " ";
            pretrav(p->left);
            pretrav(p->right);
        }
    }

    void intrav(NODEPTR p) {
        if (p != nullptr) {
            intrav(p->left);
            cout << p->info << " ";
            intrav(p->right);
        }
    }

    void posttrav(NODEPTR p) {
        if (p != nullptr) {
            posttrav(p->left);
            posttrav(p->right);
            cout << p->info << " ";
        }
    }
};

int main() {
    BinaryTree bt;
    bt.setRoot(10);
    BinaryTree::NODEPTR root = bt.getRoot();
    bt.setLeft(root, 5);
    bt.setRight(root, 15);
    bt.setLeft(root->left, 2);
    bt.setRight(root->left, 7);

    cout << "Preorder: ";
    bt.pretrav(root);
    cout << "\nInorder: ";
    bt.intrav(root);
    cout << "\nPostorder: ";
    bt.posttrav(root);
    cout << endl;

    return 0;
}
