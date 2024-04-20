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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool balanced = true;
        DFS(root, balanced);
        return balanced;
    }

    int DFS(TreeNode* node, bool &balanced) {
        // find the height of current node
        if (!node) return 0;
        int leftHeight = DFS(node->left, balanced);   // height of left child
        int rightHeight = DFS(node->right, balanced); // height of right child
        if (abs(leftHeight - rightHeight) > 1) balanced = false;
        return max(leftHeight, rightHeight) + 1;
    }
};