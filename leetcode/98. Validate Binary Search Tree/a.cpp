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
    bool isValidBST(TreeNode* root) {
        return DFS(root, LONG_MIN, LONG_MAX); 
    }
private:
    bool DFS(TreeNode* curr, long leftBound, long rightBound) {
        if (!curr) // if successfully reached nullptr, means this leaf node (parent of this nullptr) is legit.
            return true;
        if (curr->val < rightBound && curr->val > leftBound) {
            return DFS(curr->left, leftBound, curr->val) && DFS(curr->right, curr->val, rightBound);
        }
        return false;
    }
};