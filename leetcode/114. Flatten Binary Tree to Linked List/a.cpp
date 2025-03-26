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
    void flatten(TreeNode* root) {
        // Iterative DFS (top-down)
        // TC: O(n), SC: O(n)
        if (!root) return;
        stack<TreeNode*> stk;
        stk.push(root);
        while (true) {
            TreeNode* curr = stk.top();
            stk.pop();

            if (curr->right) stk.push(curr->right);
            if (curr->left) stk.push(curr->left);
            if (stk.empty()) break;
            TreeNode* next = stk.top();
            curr->left = nullptr;
            curr->right = next;
        }
        return;
    }
};