#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *random;
    Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
};


class Solution2 {
private:
    unordered_map<Node *, Node *> origToCloneMap;

public:
    Node *copyRandomBinaryTree(Node *root) {
        // recursive DFS with TC & SC: O(N)
        return copyNode(root);
    }

    Node *copyNode(Node *node) {
        if (!node) return node;
        if (origToCloneMap.find(node) != origToCloneMap.end()) {
            // return the node if already copied
            return origToCloneMap[node];
        }
        Node *newNode = new Node(node->val);
        origToCloneMap[node] = newNode;
        newNode->left = copyNode(node->left);
        newNode->right = copyNode(node->right);
        newNode->random = copyNode(node->random);  // all the nodes are already copied in line-14
        return newNode;
    } 
};

class Solution1 {
public:
    Node* copyRandomBinaryTree(Node* root) {
        // iterative DFS with TC & SC: O(N)
        if (!root) return nullptr; // no node in list
        unordered_map<Node*, Node*> origToCloneMap; // map old node ptr to newly created node ptr, in order to check created or not.
        origToCloneMap[root] = new Node(root->val); // <orig pointer, new node pointer>, new node is a copy of the orig node 

        stack<Node*> stk; // node stack for DFS traversal
        stk.push(root);
        while (!stk.empty()) {
            Node *curr = stk.top();
            stk.pop();
            if (curr->left) {
                if (origToCloneMap.find(curr->left) == origToCloneMap.end()) {
                    // copy of left child has not been created, so make a copy of left child manually.
                    origToCloneMap[curr->left] = new Node(curr->left->val); 
                    stk.push(curr->left); 
                }
                origToCloneMap[curr]->left = origToCloneMap[curr->left]; // update the left ptr of the ceated new node
            }
            if (curr->right) {
                if (origToCloneMap.find(curr->right) == origToCloneMap.end()) {
                    // copy of right child has not been created, so make a copy of right child manually.
                    origToCloneMap[curr->right] = new Node(curr->right->val);
                    stk.push(curr->right);
                }
                origToCloneMap[curr]->right = origToCloneMap[curr->right]; // update the right ptr of the ceated new node
            }
            if (curr->random) {
                if (origToCloneMap.find(curr->random) == origToCloneMap.end()) {
                    origToCloneMap[curr->random] = new Node(curr->random->val);
                    stk.push(curr->random);
                }
                origToCloneMap[curr]->random = origToCloneMap[curr->random];
            }
        }
        return origToCloneMap[root];
    }
};

void printTree(Node *root) {
    if (!root) return;
    cout << "Node: " << root->val << ", ";
    if (root->left) cout << "Left: " << root->left->val << ", ";
    if (root->right) cout << "Right: " << root->right->val << ", ";
    if (root->random) cout << "Random: " << root->random->val << endl;
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution1 s1;
    Solution2 s2;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->random = root->right;
    root->left->random = root;
    root->right->random = root->left;
    Node *newRoot1 = s1.copyRandomBinaryTree(root);
    Node *newRoot2 = s2.copyRandomBinaryTree(root);
    // Print the resulting trees
    cout << "Resulting tree using Solution1:" << endl;
    printTree(newRoot1);

    cout << "Resulting tree using Solution2:" << endl;
    printTree(newRoot2);
    return 0;
}