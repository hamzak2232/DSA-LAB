Key Features:
Generic Tree Structure: Uses C++ templates so the tree can store any data type that supports comparison operators.

Smart Insertion: Adds items while maintaining the BST property (left < root < right).

Comprehensive Deletion: Handles all deletion scenarios—whether the node is a leaf, has one child, or two.

Efficient Retrieval: Lets you search the tree to see if a specific item exists.

Check Fullness: Verifies if the tree is “full”—meaning every node has either 0 or 2 children.

Node Counting: Recursively counts and returns the total number of nodes.

Sorted Traversal: Performs an in-order traversal to print items in ascending order.

Automatic Memory Cleanup: Destructor safely frees up memory by deleting all nodes when the tree object goes out of scope.

File Output Support: Writes the sorted contents of the tree to an external file.

🗂️ Code Overview
📦 TreeType Class
🔐 Private Member:
TreeNode* root: A pointer to the root of the tree.

🔓 Public Methods:
TreeType(): Constructor that initializes the root to nullptr.

~TreeType(): Destructor that deletes all nodes and frees memory.

makenode(ItemType value): Creates a new node with the given value.

IsEmpty(): Returns true if the tree has no nodes.

Isfull(): Checks if every node has either 0 or 2 children.

Numberofnodes(): Returns the total number of nodes in the tree.

InsertItem(ItemType item): Adds a new item to the tree.

DeleteItem(ItemType item): Deletes the specified item from the tree.

RetrieveItem(ItemType item, bool& found): Searches for an item and sets found to true if it's there.

PrintTree(ofstream& outFile): Outputs the tree’s contents in sorted order to a file.

🧠 Private Helper Functions:
These handle the recursion behind the scenes:

Insertion

Deletion (including finding min values for replacement)

Retrieval

Destruction of nodes

In-order printing

