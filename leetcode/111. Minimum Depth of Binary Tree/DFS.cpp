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
    int minDepth(TreeNode* root) {
        // recursive DFS
        if (!root) return 0; // empty tree
        return dfs(root);
    }

    int dfs(TreeNode* currNode) {
        if (!currNode) return 0;
        if (!currNode->left && !currNode->right) return 1;
        int leftMinDepth = INT_MAX;
        if (currNode->left) leftMinDepth = dfs(currNode->left);
        int rightMinDepth = INT_MAX;
        if (currNode->right) rightMinDepth = dfs(currNode->right);
        return min(leftMinDepth, rightMinDepth) + 1;
    }
};