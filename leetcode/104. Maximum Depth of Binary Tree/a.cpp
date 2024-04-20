/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        // recursive BFS
        // BFS: queue (FIFO)
        queue<pair<TreeNode*, int>> q;
        int maxDepth = 0;
        q.push({root, 1});
        bfsTraverse(q, maxDepth);
        return maxDepth;
    }

    void bfsTraverse(queue<pair<TreeNode*, int>> &q, int &maxDepth) {
        if (q.empty()) return;
        auto currNode = q.front().first;
        auto currDepth = q.front().second;
        q.pop();
        maxDepth = max(maxDepth, currDepth);
        if (currNode->left) q.push({currNode->left, currDepth + 1});
        if (currNode->right) q.push({currNode->right, currDepth + 1});
        bfsTraverse(q, maxDepth);
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        // iterative BFS
        // BFS: queue (FIFO)
        queue<pair<TreeNode*, int>> q;
        int maxDepth = 0;
        q.push({root, 1});
        while (!q.empty()) {
            auto currNode = q.front().first;
            auto currDepth = q.front().second;
            q.pop();
            maxDepth = max(maxDepth, currDepth);
            if (currNode->right) q.push({currNode->right, currDepth + 1});
            if (currNode->left) q.push({currNode->left, currDepth + 1});
        }
        return maxDepth;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        // iterative DFS
        stack<pair<TreeNode*, int>> stk;
        int maxDepth = 0;
        stk.push({root, 1});
        while (!stk.empty()) {
            auto currNode = stk.top().first;
            auto currDepth = stk.top().second;
            stk.pop();
            maxDepth = max(maxDepth, currDepth);
            if (currNode->right) stk.push({currNode->right, currDepth + 1});
            if (currNode->left) stk.push({currNode->left, currDepth + 1});
        }
        return maxDepth;
    }
}; 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        // DFS
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight) + 1;
    }
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int maxDepth = INT_MIN;
        solve(root, 1, maxDepth);
        return maxDepth;
    }

    void solve(TreeNode* node, int depth, int &maxDepth) {
        if (!node) {
            return;
        }
        if (depth > maxDepth) maxDepth = depth;
        if (node->left) {
            solve(node->left, depth + 1, maxDepth);
        }
        if (node->right) {
            solve(node->right, depth + 1, maxDepth);
        }
    }
};