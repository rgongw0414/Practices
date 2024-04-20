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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        DFS(root, maxSum);
        return maxSum;
    }

    int DFS(TreeNode* curr, int &maxSum) {
        if (!curr) return 0;
        int left = max(DFS(curr->left, maxSum), 0); // if left is negative, we don't need it
        int right = max(DFS(curr->right, maxSum), 0);
        int currSum = curr->val + left + right; // the sum of the path that goes through the current node
        maxSum = max(maxSum, currSum);
        return curr->val + max(left, right); // we cab choose only one path, left or right
    }
};