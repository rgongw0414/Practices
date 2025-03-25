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
    bool isSymmetric(TreeNode* root) {
        // TC:O(n), SC:O(n)
        // Method: DFS Recursion
        return is_sym(root->left, root->right);
    }
    bool is_sym(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;  // both are null
        if (!left || !right) return false; // one of them is null
        if (left->val != right->val) return false; 
        return is_sym(left->left, right->right) && is_sym(left->right, right->left); // check the children
    }
};

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
    bool isSymmetric(TreeNode* root) {
        // DFS traverse left and right at the same time
        // TC:O(n), SC:O(n)
        TreeNode* left = root->left, *right = root->right;
        stack<TreeNode*> l_stk, r_stk;
        l_stk.push(root->left);
        r_stk.push(root->right);
        while (!l_stk.empty() && !r_stk.empty()) {
            TreeNode* l_node = l_stk.top();
            l_stk.pop();
            TreeNode* r_node = r_stk.top();
            r_stk.pop();
            if (!l_node && !r_node) continue; // both nodes are null, i.e., prev nodes are symmetric leaves
            if (!l_node || !r_node) return false;
            if (l_node->val != r_node->val) return false;
            l_stk.push(l_node->left);
            l_stk.push(l_node->right);
            r_stk.push(r_node->right);
            r_stk.push(r_node->left);
        }
        return true;
    }
};

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
    bool isSymmetric(TreeNode* root) {
        // BFS
        // TC:O(n), SC:O(n)
        queue<pair<TreeNode*, TreeNode*>> queue;
        queue.push({root->left, root->right}); // push the symmertric nodes
        while (!queue.empty()) {
            for (int i = queue.size(); i > 0; i--) {   
                auto [left, right] = queue.front();
                queue.pop();
                if (!left && !right) continue;
                if (!left || !right || left->val != right->val) {
                    return false;
                }
                queue.push({left->left, right->right});
                queue.push({left->right, right->left});
            }
        }
        return true;
    }
};