/*
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
*/

class Solution {
public:
    Node* connect(Node* root) {
        // BFS
        // TC = O(N), N is the number of nodes in the tree
        // SC = O(logN), the maximum number of nodes in a level
        if (!root) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int lv_node_num = q.size(); // The number of nodes in current level
            for (int i = 0; i < lv_node_num; i++) {
                Node* curr = q.front();
                q.pop();
                
                // Except for the last node in current level, Populate each next pointer to its next right node
                if (i < lv_node_num - 1) {
                    Node* next = q.front();
                    curr->next = next;
                }
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return root;
    }
};

/*
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
*/

class Solution {
public:
    Node* connect(Node* root) {
        // Recursive DFS with a hash-map
        // TC = O(N), N is the number of nodes in the tree
        // SC = O(N), the maximum depth of the call stack (i.e., the height of the tree)
        if (!root) return root;
        unordered_map<int, Node*> mp; // map the level to its most recent visited node (i.e., the node to be connected to its right-hand-side node)
        DFS(root, 0, mp);
        return root;
    }

    void DFS(Node* curr, int level, unordered_map<int, Node*>& mp) {
        if (!curr) return;
        if (mp.find(level) == mp.end()) {
            // For the leftmost node in each level
            mp[level] = curr;
        }
        else {
            // For current level, connect the most recent visited node to its right next neighbor
            mp[level]->next = curr;
            mp[level] = curr;
        }
        DFS(curr->left, level + 1, mp);
        DFS(curr->right, level + 1, mp);
        return;
    }
};