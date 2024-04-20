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
    int diameterOfBinaryTree(TreeNode* root) {
        // similar to max depth problem
        int maxD = 0;
        rec(root, maxD);
        return maxD;
    }
    
    int rec(TreeNode* root, int &maxD) {
        if (root == NULL) return 0;
        int ld = rec(root->left, maxD); // diameter of left child's subtree
        int rd = rec(root->right, maxD);
        maxD = max(maxD, ld + rd);  // ld+rd: diameter of current subtree
        return max(ld, rd) + 1;
    }
};