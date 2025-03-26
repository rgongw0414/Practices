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
        // Optimized Iterative BFS (Top-down), or Level-order traversal
        // TC = O(N), N is the number of nodes in the tree
        // SC = O(1), no extra space is used
        if (!root) return nullptr;
        Node* cur_lv = root; // For traversing the current level from left to right
        Node* nxt_lv_start = root->left; // The leftmost node of the next level
        while (cur_lv && nxt_lv_start) {
            cur_lv->left->next = cur_lv->right;
            if (cur_lv->next) { // The current node is not the end of this level
                cur_lv->right->next = cur_lv->next->left;
            }

            cur_lv = cur_lv->next; // Move to the next node in the current level
            if (!cur_lv) { // Reached the end of the current level, so go to the next level
                cur_lv = nxt_lv_start;
                nxt_lv_start = cur_lv->left;
            }
        }
        return root;
    }
};

/*
     d->1->N
       / \
   d->2   3
     / \   \
 d->4   5   7
*/
class Solution {
public:
    Node* connect(Node* root) {
        // Iterative BFS (Top-down), or Level-order traversal
        // TC = O(N), N is the number of nodes in the tree
        // SC = O(1), no extra space is used
        if (root == nullptr) return nullptr;
        Node* level_start = root; // The leftmost node of the current level: l
        while (level_start) {
            Node* curr_lv = level_start; // For traversing level: l
            Node* dummy = new Node(0); // dummy->next: The start (leftmost) node of the next level
            Node* next_lv = dummy; // For traversing the next level: l+1
            while (curr_lv) { // In level l, traverse from leftmost to rightmost->next. 
                // For each node of current level l, connect the left/right child from left to right
                if (curr_lv->left) {
                    next_lv->next = curr_lv->left; // connect the next pointer of level l+1
                    next_lv = next_lv->next;
                }
                if (curr_lv->right) {
                    next_lv->next = curr_lv->right;
                    next_lv = next_lv->next;
                }
                curr_lv = curr_lv->next; // In level l, traverse from leftmost to rightmost->next.
            }
            level_start = dummy->next; // Move to the next level: l+1
            delete dummy; // Free the dummy node
        }
        return root;
    }
};

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

class Solution {
    public:
    Node* connect(Node* root) {
        // Iterative DFS with a hash-map
        // TC = O(N), N is the number of nodes in the tree
        // SC = O(N), the maximum depth of the call stack (i.e., the height of the tree)
        if (!root) return root;
        unordered_map<int, Node*> mp; // map the level to its most recent visited node (i.e., the node to be connected to its right-hand-side node)
        stack<pair<int, Node*>> stk;  // pair: level of Node*, Node*
        stk.push({0, root}); 
        while (!stk.empty()) {
            //    int    Node*
            auto [level, curr] = stk.top();
            stk.pop();
            if (!curr) continue;
            if (mp.find(level) == mp.end()) {
                // For the leftmost node in each level
                mp[level] = curr;
            }
            else {
                // For current level, connect the most recent visited node to its right next neighbor
                mp[level]->next = curr;
                mp[level] = curr;
            }

            stk.push({level + 1, curr->right});
            stk.push({level + 1, curr->left});
        }
        return root;
    }
};