// EXAMPLE 9.1

#include<iostream>
#include<fstream>
using namespace std;

template <class ItemType>
class TreeType {

    template <class ItemType>
    struct TreeNode {
        ItemType info;
        TreeNode<ItemType>* left;
        TreeNode<ItemType>* right;
    };

public:
    TreeType() {
        root = nullptr;
    }

    ~TreeType() {
        DestroyHelper(root);
        root = nullptr;
        cout << "Successfully DESTROYED ;)" << endl;
    }

    TreeNode<ItemType>* makenode(ItemType value) {
        TreeNode<ItemType>* temp = new TreeNode<ItemType>;
        temp->info = value;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }

    bool IsEmpty() const {
        return (root == nullptr);
    }

    bool Isfull() const {
        return IsFullhelper(root);
    }

    bool IsFullhelper(TreeNode<ItemType>* node) {
        if (node == nullptr) return true;
        else if (node->left == nullptr && node->right == nullptr) return true;
        else if (node->left != nullptr && node->right != nullptr)
            return (IsFullhelper(node->left) && IsFullhelper(node->right));
        return false;
    }

    int Numberofnodes(TreeNode<ItemType>* ptr) const {
        if (ptr == nullptr) return 0;
        return (1 + Numberofnodes(ptr->left) + Numberofnodes(ptr->right));
    }

    void InsertItem(ItemType item) {
        InsertHelper(root, item);
    }

    void DeleteItem(ItemType item) {
        DeleteHelper(root, item);
    }

    void DeleteHelper(TreeNode<ItemType>*& ptr, ItemType item) {
        if (ptr == nullptr) {
            cout << "Sorry! Item does not exist :(" << endl;
            return;
        }
        if (item < ptr->info) DeleteHelper(ptr->left, item);
        else if (item > ptr->info) DeleteHelper(ptr->right, item);
        else DeleteNode(ptr);
    }

    void DeleteNode(TreeNode<ItemType>*& ptr) {
        TreeNode<ItemType>* temp;
        if (ptr->left == nullptr && ptr->right == nullptr) {
            delete ptr;
            ptr = nullptr;
        } else if (ptr->left == nullptr) {
            temp = ptr;
            ptr = ptr->right;
            delete temp;
        } else if (ptr->right == nullptr) {
            temp = ptr;
            ptr = ptr->left;
            delete temp;
        } else {
            ItemType minVal = GetMin(ptr->right);
            ptr->info = minVal;
            DeleteHelper(ptr->right, minVal);
        }
    }

    ItemType GetMin(TreeNode<ItemType>* ptr) {
        while (ptr->left != nullptr)
            ptr = ptr->left;
        return ptr->info;
    }

    void RetrieveItem(ItemType item, bool& found) {
        RetrieveHelper(root, item, found);
    }

    void RetrieveHelper(TreeNode<ItemType>* ptr, ItemType& item, bool& found) {
        if (ptr == nullptr) {
            cout << "Sorry! Does not exist :( ";
            return;
        } else if (item < ptr->info) {
            RetrieveHelper(ptr->left, item, found);
        } else if (item > ptr->info) {
            RetrieveHelper(ptr->right, item, found);
        } else {
            item = ptr->info;
            found = true;
        }
    }

    void PrintTree(ofstream& outFile) {
        PrintHelper(root, outFile);
    }

    void PrintHelper(TreeNode<ItemType>* ptr, ofstream& outFile) {
        if (ptr != nullptr) {
            PrintHelper(ptr->left, outFile);
            outFile << ptr->info << "        ";
            PrintHelper(ptr->right, outFile);
        }
    }

    void InsertHelper(TreeNode<ItemType>*& ptr, ItemType item) {
        if (ptr == nullptr) ptr = makenode(item);
        else if (item < ptr->info) InsertHelper(ptr->left, item);
        else if (item > ptr->info) InsertHelper(ptr->right, item);
    }

    void DestroyHelper(TreeNode<ItemType>* ptr) {
        if (ptr != nullptr) {
            DestroyHelper(ptr->left);
            DestroyHelper(ptr->right);
            delete ptr;
        }
    }

    TreeNode<ItemType>* gettroot() {
        return root;
    }

private:
    TreeNode <ItemType>* root;
};


// EXERCISE 9.1

int main() {
    TreeType<int> tree;
    int item = 1;
    bool flag = false;
    tree.RetrieveItem(item, flag);
    cout << flag << endl;

    // -------- EXERCISE 9.1 --------
    TreeType<string> tree2;
    string arrayofstring[10] = { "Real", "Eyes", "Realise", "Real", "Lies" };

    for (int i = 0; i < 5; i++) {
        tree2.InsertItem(arrayofstring[i]);
    }

    ofstream outfile("out.txt");
    tree2.PrintTree(outfile);
    cout << "Array of strings is successfully printed in a sorted form on out.txt" << endl;

    outfile.close();

    return 0;
}
