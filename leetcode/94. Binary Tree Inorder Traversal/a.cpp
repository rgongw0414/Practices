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
    vector<int> inorderTraversal(TreeNode* root) {
        // Bottom-up Recursive DFS
        // TC: O(n), SC: O(n)
        vector<int> inorder;
        if (!root) return inorder;
        DFS(inorder, root);
        return inorder;
    }

    void DFS(vector<int>& inorder, TreeNode* curr) {
        if (!curr->left && !curr->right) {
            inorder.push_back(curr->val);
            return;
        }
        if (curr->left) DFS(inorder, curr->left);
        inorder.push_back(curr->val);
        if (curr->right) DFS(inorder, curr->right);
        return;
    }
};