# Populating Next Right Pointers in Each Node I/II (116/117)
- (Perfect) Binary Tree
- BFS (Level-Order-Traversal) with SC=O(1)
- If Node has a next pointer to its right next node, no extra space is needed to traverse the tree by level-order
- Otherwise, it takes SC of O(logN) for BFS to traverse by level-order

```cpp
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
```